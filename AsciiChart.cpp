#include "Benchmark/Benchmark.h"
#include "BaseN.h"


constexpr uint64_t chars_per_row {32};
int ascii_main(int argc, char *argv[]) {
    std::cout << "Printable Extended ASCII Chart [0..255]:\n";
    std::cout << "Char\tDEC\tOCT\tHEX\tBIN" << std::endl;
    for (char c{CHAR_MIN}; c < CHAR_MAX; c++) {
        //std::cout << c << ((c + 1) % chars_per_row ? ' ' : '\n');
        std::cout << std::dec << (int)c << "\t" << static_cast<int8_t>(c) << "\t"  << dec_to_hex(c) << "\t"  << dec_to_bin(c) << '\n';
    }
    return EXIT_SUCCESS;
}