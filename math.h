#ifndef MATH_H
#define MATH_H
#include <cmath>
#include <cstdint>

namespace ajc::math {
/// <summary>
/// Start at 3 and check up to sqrt(n).  Even numbers are ignored since
/// they would have been found by division by 2 already.
/// </summary>
/// <param name="n">An unsigned number/param>
/// <returns>true if prime, else false</returns>
    constexpr bool isPrime(uint64_t n) {
        if (n < 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        const auto sqrt_n = static_cast<uint64_t>(sqrt(n));
        for (auto i = 3ul; i <= sqrt_n; i += 2ul) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }
    /**
     * \brief Start at 3 and check up to sqrt(n).  Even numbers are ignored since
     * they would have been found by division by 2 already.
     * \param n A uint64_t
     * \return true if n is prime, else false
     */
    constexpr bool is_prime(uint64_t n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        const auto sqrt_n = static_cast<uint64_t>(sqrt(n));
        for (uint64_t i = 3; i < sqrt_n; ++i) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * \brief Computes the nth fibonacci number.
     * \param n An integer specifying the number in the sequence we desire.
     * \return The fibonacci number associated with slot n in the sequence.
     */
    constexpr uint64_t ifib(uint64_t n) {
	    if(n<2)
            return n;
        uint64_t a=0; uint64_t b=1; uint64_t c=a+b;
        for(uint64_t i=0; i<n; ++i) {
	        a=b;
            b=a+b;
        }
        return a;
    }

}
#endif
