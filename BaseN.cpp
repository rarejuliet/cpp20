#include "BaseN.h"

#include <cstdint>
#include <string>
struct NotImplementedException : std::exception {
	
};

inline std::string to_hex(const uint64_t n) {
    if (n == 0)
        return "0";
    uint64_t num = n;
    std::string s;
    while (num) {
        const uint64_t temp = num % 16;
        if (temp <= 9)
            s += (static_cast<char>(48 + temp));
        else
            s += (static_cast<char>(87 + temp));
        num = num / 16;
    }
    s += "x0";
    std::reverse(s.begin(), s.end());
    return s;
}

uint64_t to_int(const std::string& hex) {

	//throw NotImplementedException{};
	return EXIT_SUCCESS;
}
std::string to_bin(uint64_t n) {
	throw NotImplementedException{};
}
