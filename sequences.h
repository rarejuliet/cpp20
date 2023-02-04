#ifndef SEQUENCES_H
#define SEQUENCES_H
#include <cstdint>
#include <stdexcept>

#include "Generator.h"
#include "math.h"

inline Generator<uint64_t>
get_fibonacci_sequence(uint64_t n)
{
    constexpr uint8_t max_fibonacci = 94;
    if (n == 0)
        co_return;
    /*if (n > max_fibonacci)
        throw std::runtime_error("Fibonacci sequence too big. Elements would overflow.");*/
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
Generator<uint64_t> get_prime_sequence()
{
    uint64_t n = 0;
    while (n<UINT64_MAX) {
        while (!math::is_prime(n)) {
            ++n;
        }
        co_yield n;
        ++n;
    }
}
#endif

