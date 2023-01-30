#include "Benchmark/Benchmark.h"
int ascii_main(int argc, char *argv[]) {
    std::cout << "Printable ASCII [32..126]:\n";
    for (char c{ ' ' }; c <= '~'; c++) {
        std::cout << c << ((c + 1) % 32 ? ' ' : '\n');
    }
    return EXIT_SUCCESS;
}