#include "BaseN.h"

#include <cstdint>
#include <string>
struct NotImplementedException : std::exception {
	
};
std::string to_hex(uint64_t n) {
	throw NotImplementedException{};
}
std::string to_int(uint64_t n) {
	throw NotImplementedException{};
}
std::string to_bin(uint64_t n) {
	throw NotImplementedException{};
}
