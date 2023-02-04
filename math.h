#ifndef MATH_H
#define MATH_H
#include <cmath>
#include <cstdint>

namespace math {
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
     * they would have been found by division by 2 already.  This is the best
     * algorithm I have for finding primes.  A further optimization would be to
     * cache results of previous calls and return the cached copy in case of 
     * further calls.
     * \param n A uint64_t
     * \return true if n is prime, else false
     */
    constexpr bool is_prime(uint64_t n) {  //todo: memoize this function.  Or create a different
        // todo: function and memoize that one.
        if (n < 2) 
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        const auto sqrt_n = static_cast<uint64_t>(sqrt(n));
        for (uint64_t i = 3; i < sqrt_n; i+=2) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * \brief Computes the nth fibonacci number.  This function uses a loop
     * or iterative design to compute fib(n), and so is much faster than the
     * recursive version of this function.  For more information, see
     * documentation for the rfib function.
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

    /**
     * \brief A recursive fibonacci number generator.  Mainly for test and
     * comparison with the iterative algorithm in function ifib.  This
     * function will be slow, and might cause a stack overflow with high
     * enough values for n.  In any case, overflow is NOT noted or reported.
     *   Instead, this function will happily compute values for n where the
     * result doesn't fit in a 64-bit integer.  It simply overflows.  The
     * value for n where this starts to happen is 94.  I could have thrown an
     * exception, but for now this suffices.  I'd like to keep it constexpr
     * if possible.
     * \param n The number in the sequence to obtain.
     * \return The nth number in the fibonacci sequence.
     */
    constexpr uint64_t rfib(uint64_t n) {
	    if(n<2)
            return n;
        return rfib(n-1)+rfib(n-2);
    }

}
#endif
