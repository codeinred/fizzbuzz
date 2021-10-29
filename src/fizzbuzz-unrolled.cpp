#include <fmt/core.h>
#include <numeric>

int main() {
    constexpr long max = std::numeric_limits<long>::max();
    for(long i = 0; i < max; i+= 15) {
        fmt::print("{}\n", "FizzBuzz");
        fmt::print("{}\n", i + 1);
        fmt::print("{}\n", i + 2);
        fmt::print("{}\n", "Fizz");
        fmt::print("{}\n", i + 4);
        fmt::print("{}\n", "Buzz");
        fmt::print("{}\n", "Fizz");
        fmt::print("{}\n", i + 7);
        fmt::print("{}\n", i + 8);
        fmt::print("{}\n", "Fizz");
        fmt::print("{}\n", "Buzz");
        fmt::print("{}\n", i + 11);
        fmt::print("{}\n", "Fizz");
        fmt::print("{}\n", i + 13);
        fmt::print("{}\n", i + 14);
    }
}
