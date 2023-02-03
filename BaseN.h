#ifndef BASEN_H
#define BASEN_H
#include <cstdint>
#include <string>
#include <sstream>

std::string dec_to_hex(const uint64_t n);
uint64_t hex_to_dec(const std::string& hex);
std::string dec_to_bin(uint64_t n);
uint64_t bin_to_dec(std::string bin);
uint64_t toThePower(uint64_t num, uint64_t power);
#endif
