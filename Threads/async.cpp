#include "Generator.h"
#include <coroutine>
#include <iostream>

namespace math {
    constexpr bool is_prime(uint64_t n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        auto sqrt_n = static_cast<uint64_t>(sqrt(n));
        for (uint64_t i = 3; i <= sqrt_n; i = i + 2) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }

    Generator<uint64_t> get_primes() {
        static unsigned long long i = 0;
        ++i;
        uint64_t num = 0;
        while (num < UINTMAX_MAX) {
	        if (bool p = math::is_prime(num)) {
                co_yield num;
            }
            ++num;
        }
        //co_return 0;
    }
}

/**
 * \brief The entry point for the asynchronous prime number generator.
 * \param argc Number of parameters.
 * \param argv Parameter values.
 * \return 
 */
int async_main(int argc, char ** argv) {
    Generator<uint64_t> primes = math::get_primes();
    for (uint64_t i = 0; i < 255; ++i) {
        std::cout << primes() << " is prime\n";
    }
    return 0;
}