#ifndef MATH_H
#define MATH_H
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include "BigDecimal.h"
#include "BigInteger.h"
#include "BaseN.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <bitset>
union u64 {
    uint64_t value;
    unsigned char b00;
    unsigned char b01;
    unsigned char b02;
    unsigned char b03;
    unsigned char b04;
    unsigned char b05;
    unsigned char b06;
    unsigned char b07;
    unsigned char b08;
    unsigned char b09;
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char bytes[16];
    // unsigned char b16;
    // unsigned char b17;
    // unsigned char b18;
    // unsigned char b19;
    // unsigned char b20;
};
inline void print(u64 u) {
    std::cout << "uint64_t value: {" << u.value << "}" << std::endl;
    std::cout << "byte values:" << std::endl;
    int i=0;
    for(auto &byte : u.bytes) {
        std::cout << "byte:" << i++ << "{" << std::bitset<8>(byte) << ", " << basen::dec_to_hex(byte) << "}" << std::endl;
    }
}

namespace math {

    /**
        @brief Start at 3 and check up to sqrt(n).  Even numbers are ignored since 
        they would have been found by division by 2 already.
        @param n - An unsigned number.
        @retval   - true if prime, else false
    **/
    inline bool is_prime_a(uint64_t n) {
    static std::map<uint64_t, int> p_map { {0,0}, {1,0}, {2,1}, {3,1} };
        if(p_map.count(n)>0) {
            return p_map[n];
        } else {
            const uint64_t sqrt_n = static_cast<uint64_t>(sqrt(n));
            for (uint64_t i = 3ul; i <= sqrt_n; i += 2ul) {
                if( ((n % i) == 0) ) {
                    p_map.insert_or_assign(n,0);
                    return p_map[n];
                }
            }
            p_map.insert_or_assign(n,1);
//            p_map[n]=1;
        }
//        p_map[n]=1;
        return p_map[n];
    }
    /**
        @brief  Find out whether a given number is prime.
        @param  n - An unsigned number.
        @retval   - true if prime, else false.
    **/
    inline uint64_t is_prime_b(uint64_t n) {
        if(n<2)
            return 0;
        if(n==2)
            return 1;
        if(n%2==0)
            return 0;
        uint64_t isprime=1;
	    for (uint64_t i=2ull; i<=n/2; i++) {
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
    inline bool is_prime_c(uint64_t n) {  //todo: memoize this function.  Or create a different

        if (n < 2) 
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        const uint64_t sqrt_n = static_cast<uint64_t>(sqrt(n));
        for (uint64_t i = 3; i <= sqrt_n; i+=2) {
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
