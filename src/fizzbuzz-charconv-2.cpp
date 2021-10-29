#include <charconv>
#include <cstring>
#include <limits>
#include <unistd.h>

inline char* print_to(char* buff, char* last, long n) {
    char* dest = std::to_chars(buff, last, n).ptr;
    *dest = '\n';
    return dest + 1;
}
template <size_t N>
inline char* print_to(char* buff, char* last, char const (&str)[N]) {
    memcpy(buff, str, N - 1);
    return buff + (N - 1);
}
int main() {
    constexpr long max = std::numeric_limits<long>::max();
    alignas(4096) char buffer[300 * 101];
    char* const buffer_last = buffer + sizeof(buffer);
    long i = 0;
    while (true) {
        char* dest = buffer;
        for (int j = 0; j < 100; j++) {
            dest = print_to(dest, buffer_last, "FizzBuzz\n");
            dest = print_to(dest, buffer_last, i + 1);
            dest = print_to(dest, buffer_last, i + 2);
            dest = print_to(dest, buffer_last, "Fizz\n");
            dest = print_to(dest, buffer_last, i + 4);
            dest = print_to(dest, buffer_last, "Buzz\n");
            dest = print_to(dest, buffer_last, "Fizz\n");
            dest = print_to(dest, buffer_last, i + 7);
            dest = print_to(dest, buffer_last, i + 8);
            dest = print_to(dest, buffer_last, "Fizz\n");
            dest = print_to(dest, buffer_last, "Buzz\n");
            dest = print_to(dest, buffer_last, i + 11);
            dest = print_to(dest, buffer_last, "Fizz\n");
            dest = print_to(dest, buffer_last, i + 13);
            dest = print_to(dest, buffer_last, i + 14);
            i += 15;
        }
        write(1, buffer, dest - buffer);
    }
}
