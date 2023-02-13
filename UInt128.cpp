#include "UInt128.h"

UInt128::UInt128(uint64_t n) : lower(n), upper(0){}

UInt128 UInt128::operator=(UInt128 rhs) {
	this->lower = rhs.lower;
	return *this;
}
UInt128 UInt128::operator+(UInt128 rhs) {
	this->lower += rhs.lower;
	this->upper += rhs.upper;
	return *this;
}
UInt128 UInt128::operator-(UInt128 rhs){ return *this; }
UInt128 UInt128::operator/(UInt128 rhs){ return *this;}
UInt128 UInt128::operator*(UInt128 rhs){return *this;}
bool UInt128::operator==(const UInt128& rhs) const{return lower == rhs.lower && upper == rhs.upper;}
bool UInt128::operator!=(const UInt128& rhs) const{return lower != rhs.lower || upper != rhs.upper;}
bool UInt128::operator<(const UInt128& rhs) const { return lower < rhs.lower && upper < rhs.upper; }
bool UInt128::operator>(const UInt128& rhs) const{return lower > rhs.lower && upper > rhs.upper;}
