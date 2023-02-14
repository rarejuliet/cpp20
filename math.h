#ifndef MATH_H
#define MATH_H
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include "BigDecimal.h"
#include "BigInteger.h"
#include "uint128_t.h"

namespace math {
/**
    @brief  Get the high 64 bits of an uint128_t.
    @param  x - An uint128_t
    @retval   - The high 64 bits as a uint64_t.
**/
inline uint64_t uint128_high64(uint128_t x) {
  return x >> 64;
}
/**
    @brief  Get the low 64 bits of an uint128_t.
    @param  x - An uint128_t
    @retval   - The low 64 bits as an uint64_t
**/
inline uint64_t uint128_low64(uint128_t x) {
  return x & 0xFFFFFFFFFFFFFFFFull;
}
/**
    @brief  Multiply two uint64_t and return the result as an uint128_t.
    @param  a - An uint64_t 
    @param  b - An uint64_t 
    @retval   - An uint128_t containing the value a * b
**/
inline uint128_t uint128_mul64(uint64_t a, uint64_t b) {
  return (uint128_t)a * b;
}
/**
    @brief  Add two uint64_t.
    @param  a - An uint64_t 
    @param  b - An uint64_t 
    @retval   - An uint128_t containing a + b
**/
inline uint128_t uint128_add(uint128_t a, uint128_t b) {
  return a + b;
}
/**
    @brief  Subtract one uint128_t from another.
    @param  a - An uint128_t
    @param  b - An uint128_t
    @retval   - An uint128_t containing a - b
**/
inline uint128_t uint128_sub(uint128_t a, uint128_t b) {
  return a - b;
}

/**
    @brief  Take the square root of an uint128_t.
    @param  x - The number you wish to find the square root for.
    @retval   - The square root of x.
**/
inline uint128_t uint128_sqrt(uint128_t x) {
    if (x == 0) {
        return 0;
    }
    uint64_t b = uint128_high64(x);
    if (b == 0) {
        return (uint128_t)sqrt(uint128_low64(x));
    }

    uint64_t r = (1ull << 62);
    uint64_t t = 0;
    while (r != 0) {
        t = uint128_add(t, r);
        uint128_t c = uint128_mul64(t, t);
        if (c <= x) {
            x = uint128_sub(x, c);
            t = uint128_add(t, r);
        }
        t = uint128_sub(t, r);
        r >>= 1;
    }
    return t;
}

    static std::map<uint128_t, bool> p_map { {0,false}, {1,false}, {2,true}, {3,true} };
    /**
        @brief Start at 3 and check up to sqrt(n).  Even numbers are ignored since 
        they would have been found by division by 2 already.
        @param n - An unsigned number.
        @retval   - true if prime, else false
    **/
    inline bool is_prime_a(uint128_t n) {
        if(math::p_map.size() < n) {
            return p_map[n];
        } else {
            //const auto sqrt_n = uint128_sqrt(n);
            for (uint128_t i = 3ul; i <= n/2; i += 2ul) {
                p_map[i]=((n % i) == 0);
            }
            p_map[n]=true;
        }
        return p_map[n];
    }
    /**
        @brief  Find out whether a given number is prime.
        @param  n - An unsigned number.
        @retval   - true if prime, else false.
    **/
    inline uint128_t is_prime_b(uint128_t n) {
        if(n<2)
            return 0;
        if(n==2)
            return 1;
        if(n%2==0)
            return 0;
        auto sqrt_n = uint128_sqrt(n);
        uint128_t isprime=1;
	    for (uint128_t i=2ull; i<=n/2; i++) {
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
    inline bool is_prime_c(uint128_t n) {  //todo: memoize this function.  Or create a different

        if (n < 2) 
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        const uint128_t sqrt_n = math::uint128_sqrt(n);
        for (uint128_t i = 3; i <= sqrt_n; i+=2) {
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
    inline constexpr uint64_t ifib(uint64_t n) {
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
    inline constexpr uint64_t rfib(uint64_t n) {
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
		inline constexpr uint64_t recursive(const uint64_t num) {
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
		inline constexpr uint64_t iterative(const uint64_t num) {
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
