#include "Benchmark/Benchmark.h"
constexpr uint64_t chars_per_row {32};
int ascii_main(int argc, char *argv[]) {
    std::cout << "Printable ASCII [32..126]:\n";
    for (char c{ ' ' }; c <= '~'; c++) {
        std::cout << c << ((c + 1) % chars_per_row ? ' ' : '\n');
    }
    return EXIT_SUCCESS;
}