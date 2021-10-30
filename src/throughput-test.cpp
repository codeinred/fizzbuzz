#include <fcntl.h>
#include <sys/uio.h>

int main() {
    char buffer[131072] {'\0'};
    auto io = iovec{buffer, sizeof(buffer)};
    while (vmsplice(1, &io, 1, 0) >= 0)
        ;
}
