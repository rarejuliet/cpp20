#ifndef UINT128_H
#define UINT128_H
#include <cstdint>


class UInt128 {
	UInt128(uint64_t n);
	UInt128(const UInt128& n) = default;
	UInt128 operator=(UInt128 rhs);
	UInt128 operator+(UInt128 rhs);
	UInt128 operator-(UInt128 rhs);
	UInt128 operator/(UInt128 rhs);
	UInt128 operator*(UInt128 rhs);
	bool operator==(const UInt128& rhs) const;
	bool operator!=(const UInt128& rhs) const;
	bool operator<(const UInt128& rhs) const;
	bool operator>(const UInt128& rhs) const;
//private:
	uint64_t lower {};
	uint64_t upper {};
};

#endif

