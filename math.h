#ifndef MATH_H
#define MATH_H
#include <cmath>
#include <cstdint>

#include "BigDecimal.h"
#include "BigInteger.h"

namespace math {
/// <summary>
/// Start at 3 and check up to sqrt(n).  Even numbers are ignored since
/// they would have been found by division by 2 already.
/// </summary>
/// <param name="n">An unsigned number/param>
/// <returns>true if prime, else false</returns>
    inline constexpr bool is_prime_a(uint64_t n) {
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
    inline constexpr uint64_t is_prime_b(uint64_t n) {
        if(n<2)
            return 0;
        if(n==2)
            return 1;
        if(n%2==0)
            return 0;
        auto sqrt_n = static_cast<uint64_t>(sqrt(n));
        uint64_t isprime=1;
	    for (auto i=2ull; i<=sqrt_n; i++) {
            isprime = isprime & ((n % i) != 0);
            if(!isprime)
                return 0;
	    }
        return isprime;
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
    inline bool is_prime_c(BigInteger n) {  //todo: memoize this function.  Or create a different
        // todo: function and memoize that one.
        if (n < 2) 
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        //const uint64_t sqrt_n = sqrtl((static_cast<uint64_t>(n));
        for (BigInteger i = 3; i < (n/2); i+=2) {
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
    namespace Fibonacci {
		/**
		 * \brief The highest value for which a compile-time evaluation may occur.  May be
		 * different on various platforms but for MSVC it can go up to 94 before int type
		 * uint64_t overflows (64-bit).
		 */
		static constexpr uint64_t MAX_FIBONACCI = 94;

		/**
		 * \brief A recursive fibonacci number generator.
		 * \param num The nth fibonacci number 
		 * \return The nth number in the fibonacci sequence. 
		 */
		constexpr uint64_t recursive(const uint64_t num) {
	//		[[unlikely]]
			if( num < 2 )
				return num;
			return recursive(num-1) + recursive(num-2);
		}

		/**
		 * \brief An iterative solution to the fibonacci sequence.
		 * \param num The nth fibonacci number
		 * \return The nth number in the fibonacci sequence.
		 */
		constexpr uint64_t iterative(const uint64_t num) {
			if( num < 2 )
				return num;
			uint64_t p {1};
			uint64_t pp {0};
			uint64_t tmp{p+pp};
			for(uint64_t i=0; i<num; ++i) {
				tmp = p + pp;
				p=pp;
				pp=tmp;
			}
			return tmp;
		}
}

}
#endif
