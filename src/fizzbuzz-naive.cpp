#include <fmt/core.h>
#include <numeric>

int main() {
    constexpr long max = std::numeric_limits<long>::max();
    for(long i = 0; i < max; i++) {
        bool fizz = i % 3 == 0;
        bool buzz = i % 5 == 0;
        if (fizz || buzz) {
            if (fizz) {
                fmt::print("Fizz");
            }
            if (buzz) {
                fmt::print("Buzz");
            }
            fmt::print("\n");
        } else {
            fmt::print("{}\n", i);
        }
    }
}
