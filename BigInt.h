#ifndef BIGINT_H
#define BIGINT_H
/*
    This file was produced with the assistance of ChatGPT.
*/
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

class BigInt {
private:
    std::vector<int> bits;

public:
    BigInt() {}

    BigInt(int x) {
        while (x > 0) {
            bits.push_back(x % 10);
            x /= 10;
        }
    }

    BigInt(const std::string &str) {
        for (int i = 0; i < str.size(); i++) {
            bits.push_back(str[str.size() - i - 1] - '0');
        }
    }

    BigInt operator+(const BigInt &other) const {
        BigInt result;
        int carry = 0;
        for (int i = 0; i < std::max(bits.size(), other.bits.size()) || carry; i++) {
            if (i >= result.bits.size()) {
                result.bits.push_back(0);
            }
            result.bits[i] += carry + (i < bits.size() ? bits[i] : 0) + (i < other.bits.size() ? other.bits[i] : 0);
            carry = result.bits[i] / 10;
            result.bits[i] %= 10;
        }
        return result;
    }

    int operator[](int index) const {
        return bits[index];
    }

    BigInt shiftRight(int shift) const {
        BigInt result;
        for (int i = 0; i < bits.size(); i++) {
            result.bits[i] = bits[i + shift];
        }
        return result;
    }

    bool operator==(const BigInt &other) const {
        return memcmp(bits.data(), other.bits.data(), bits.size()) == 0;
    }

    bool operator!=(const BigInt &other) const {
        return !(*this == other);
    }

    bool operator>(const BigInt &other) const {
        for (int i = bits.size() - 1; i >= 0; i--) {
            if (bits[i] > other.bits[i]) {
                return true;
            }
            if (bits[i] < other.bits[i]) {
                return false;
            }
        }
        return false;
    }

    bool operator<(const BigInt &other) const {
        return other > *this;
    }

    bool operator>=(const BigInt &other) const {
        return !(*this < other);
    }

    bool operator<=(const BigInt &other) const {
        return !(*this > other);
    }

    void print() const {
        int i;
        for (i = bits.size() - 1; i >= 0; i--) {
            if (bits[i] != 0) {
                break;
            }
        }
        if (i < 0) {
            std::cout << 0 << std::endl;
        }
        for (; i >= 0; i--) {
            std::cout << bits[i];
        }
        std::cout << std::endl;
    }
};

#endif
