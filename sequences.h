#ifndef SEQUENCES_H
#define SEQUENCES_H
#include <cstdint>
#include <stdexcept>
#include <format>
#include "Generator.h"
#include "math.h"

namespace sequences {
	
/**
 * \brief Create a Generator<uint64> which will iterate through the fibonacci
 * sequence.
 * \param n The fibonacci number you wish to retrieve.
 * \return The nth number in the fibonacci sequence.
 */
inline Generator<uint64_t>
get_fibonacci_sequence(uint64_t n)
{
    constexpr uint8_t max_fibonacci = 94;
    if (n == 0)
        co_return;
    if (n > max_fibonacci)
        throw std::runtime_error(std::format("Fibonacci sequence for [fib({0})] would overflow a 64-bit integer.",n));
    co_yield 0;
    if (n == 1)
        co_return;
    co_yield 1;
    if (n == 2)
        co_return;
    uint64_t a = 0;
    uint64_t b = 1;
    for (uint64_t i = 2; i < n; i++) {
        uint64_t s = a + b;
        co_yield s;
        a = b;
        b = s;
    }
}
/**
 * \brief Get a Generator<int64_t> which will iterate through the prime
 * numbers.
 * \return A Generator<int64_t> over the prime numbers.
 */
inline Generator<BigInteger> get_prime_sequence(uint64_t startval=0)
{
    uint64_t n = startval;
    while (true) {
        while (!math::is_prime_c(n)) {
            ++n;
        }
        co_yield n;
        ++n;
    }
}

/**
 * \brief Get a sequence for infinity (at least up to
 * 2^64)
 * \return A uint64_t
 */
inline Generator<uint64_t> get_infinite_sequence() {
	uint64_t i=0;
    while(i<UINT64_MAX)
    {
	    co_yield i;
        ++i;
    }
}
}
int sequence_main(int argc, char* argv[], char* env[]);
#endif

