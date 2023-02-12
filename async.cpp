#include "Generator.h"
#include <coroutine>
#include <iostream>
#include "../math.h"

namespace math {

    Generator<uint64_t> get_primes() {
        static unsigned long long i = 0;
        ++i;
        uint64_t num = 0;
        while (num < UINTMAX_MAX) {
	        if (bool p = math::is_prime_c(num)) {
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
 * \return EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int async_main(int argc, char ** argv) {
    try
    {
        Generator<uint64_t> primes = math::get_primes();
        for (uint64_t i = 0; i < 255; ++i) {
            std::cout << primes() << " is prime\n";
        }
        return EXIT_SUCCESS;

    }
    catch (const std::exception&)
    {
        return EXIT_FAILURE;
    }
}