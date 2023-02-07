#include "BaseN.h"



struct NotImplementedException : std::exception {
	
};

//INTEGER TO HEXADECIMAL
/**
 * \brief Convert a number to hexadecimal string.
 * \param n A number to convert to hex.
 * \return A string representation of the decimal value for n.
 */
std::string dec_to_hex(const uint64_t n) {
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
//HEXADECIMAL TO DECIMAL
/**
 * \brief Convert a hex value to decimal.
 * \param hex A string representation of an hexadecimal number.
 * \return An integer with the corresponding decimal value for hex.
 */
uint64_t hex_to_dec(const std::string& hex) {
    std::stringstream ss;
    uint64_t converted;
    ss << std::hex << hex;
    ss >> converted;
    return converted;
}

/**
 * \brief Convert an integer into a string representation of the number in binary.
 * \param n A number to convert.
 * \return A string representation of the binary value of n.
 */
std::string dec_to_bin(uint64_t n) {
    std::string bin;
    while (n != 0)
    {
        bin += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    std::reverse(bin.begin(), bin.end());
    return bin;
}
//BINARY TO DECIMAL
/**
 * \brief Convert a binary string representation of a number to its decimal representation.
 * \param bin A string containing a binary representation of a number.
 * \return An integer containing the decimal value of bin.
 */
uint64_t bin_to_dec(std::string bin)
{
    uint64_t dec = 0;
    uint64_t count = 0;
    for (auto i = bin.rbegin(); i != bin.rend(); ++i) {
        std::string s; s += (*i); uint64_t a = std::stoul(s);
        dec += (static_cast<uint64_t>(a) * toThePower(2, count));
        count += 1;
    }
    return --dec;
}

/**
 * \brief Does the same job as std::pow
 * \param num A number to be raised to power.
 * \param power An exponent to raise num to the power of.
 * \return An integer containing num**power.
 */
uint64_t toThePower(uint64_t num, uint64_t power)
{
    return std::pow(num,power);
    uint64_t temp = num;
    for (uint64_t i = 1; i < power; i++)
        temp = temp * num;
    return temp;
}
