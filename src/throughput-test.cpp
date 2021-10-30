#include <array>
#include <fcntl.h>
#include <sys/uio.h>
#include <thread>
#include <vector>
#include <string>

void runner() {
    alignas(4096) char buffer[4096] {'\0'};
    std::array<iovec, 256> pages;
    for (auto& vec : pages) {
        vec = {buffer, sizeof(buffer)};
    }
    while (vmsplice(1, pages.data(), pages.size(), 0) >= 0)
        ;
}

int main(int argc, char** argv) {
    int n_threads = 1;
    if (argc > 1) {
        std::string input = argv[1];
        n_threads = std::stoi(input, 0);
    }
    std::vector<std::thread> threads(n_threads - 1);

    for (auto& t : threads)
        t = std::thread(runner);
    runner();

    for (auto& t : threads)
        t.join();
}
