#include <fcntl.h>
#include <sys/uio.h>
#include <array>

int main() {
    alignas(4096) char buffer[4096] {'\0'};
    std::array<iovec, 256> pages;
    for(auto& vec : pages) {
        vec = {buffer, sizeof(buffer)};
    }
    while (vmsplice(1, pages.data(), pages.size(), 0) >= 0)
        ;
}
