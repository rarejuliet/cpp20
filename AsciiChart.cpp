#include <bitset>
#include <fstream>

#include "Benchmark/Benchmark.h"
#include "BaseN.h"


int ascii_main(int argc, char *argv[]) {
    std::ofstream out("ascii.html");
    out << "<html><head><title>ASCII Chart</title></head><body><h1>";
    out << "Printable Extended ASCII Chart [0..255]:\n";
    out << "<table><thead><tr><td>Char</td><td>DEC</td><td>OCT</td><td>HEX</td><td>BIN</td></tr></thead><tbody>" << std::endl;
    for (uint8_t c{0}; c < UCHAR_MAX; ++c) {
//        out << "<tr>" << std::endl;
        //std::cout << c << ((c + 1) % chars_per_row ? ' ' : '\n');
//        std::cout << static_cast<int8_t>(c) << "\t" << std::dec << (int)c << "\t" << std::oct << int(c) << "\t"  << std::hex << int(c) << "\t"  << dec_to_bin(c) << '\n';
//        if(c==9 || c==27)
        out << "<tr><td>" << std::dec << static_cast<char>(c) << "</td><td>" << std::oct << static_cast<int>(c) << "</td><td>" << std::hex << static_cast<int>(c) << "</td><td>" << std::bitset<8>(c) << "</td></tr><br />" << std::endl;
   //     else
			//std::cout << static_cast<int8_t>(c) << "\t" << std::dec << static_cast<int>(c) << "\t" << std::oct << static_cast<int>(c) << "\t"  << std::hex << static_cast<int>(c) << "\t"  << std::bitset<8>(c) << '\n';
    }
    out << "<tbody></table></body></html>";
    out.close();
    return EXIT_SUCCESS;
}