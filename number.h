#ifndef NUMBER_H
#define NUMBER_H
#include <cstdint>
namespace math{
struct number {
	uint64_t lower;
	uint64_t upper;
	bool sign;
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
};
}
#endif