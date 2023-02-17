#ifndef NUMBER_H
#define NUMBER_H
#include <cstdint>
namespace math{
struct number {
	int64_t lower;
	int64_t upper;
	number() : lower(0), upper(0) {}
	number(int64_t n) {
		lower = n;
		upper = 0;
	}
	number operator+(const number& other) {
		number result{};
		bool carry = (lower+other.lower) < lower;
		result.lower += other.lower;
		if(carry)
			upper++;
		result.upper += other.upper; //Might overflow.
		return result;
	}
	void operator=(const number &n) {
		lower=n.lower;
		upper=n.upper;
	}
	number operator-() {
		number result;
		result.lower = lower;
		result.upper = upper;
		return -result;
	}
	number operator++() {
		if(this->lower < INT64_MAX) {
			this->lower++;
		} else {
			this->lower=0;
			this->upper++;
		}
		return *this;
	}
	bool operator<(const number& other) {
		if(upper < other.upper)
			return true;
		else if( upper == other.upper && lower < other.lower )
			return true;
		else
			return false;
	}
	number operator-(const number& other) {
		number result{};
		bool borrow = (std::abs(static_cast<long long>(lower)) < std::abs(static_cast<long long>(other.lower)));
		if( borrow ) {
			result.lower++;
			result.upper--;
		}
		result.upper = (upper-other.upper);
		return result;
	}
};
}
#endif