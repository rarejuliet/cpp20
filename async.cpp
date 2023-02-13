#include "Generator.h"
#include <coroutine>
#include <iostream>
#include "../math.h"
#include <boost/lexical_cast.hpp>
#include "sequences.h"

/**
    @namespace math
    @brief     Contains a collection of math related utilities.
**/
namespace math {
    /**
        @brief  Create and return a prime number sequence generator. (See Generator.h)
        @param  startval - A number from which you wish to start generating primes AFTER.
        @retval          - The next Prime number in the sequence.
    **/
    Generator<uint64_t> get_primes(uint64_t startval=0) {
        uint64_t num{startval};
        while (true) {
	        if (bool p = math::is_prime_a(num)) {
                co_yield num;
            }
            ++num;
        }
        //co_return 0;
    }
}

/**
    @brief The entry point for the asynchronous prime number generator.  
    @param  argc - Number of parameters.
    @param  argv - Parameter values.
    @param  env  - Environment variables.
    @retval      - EXIT_SUCCESS on success, EXIT_FAILURE on failure.
**/
int sequence_main(int argc, char* argv[], char* env[]) {
    try
    {
        // Generate 255 prime numbers starting at (UINT32_MAX*UINT32MAX/2)
        uint64_t start{UINT32_MAX*(UINT32_MAX/2)};
        auto primes = math::get_primes(start);
        for (uint64_t i=0; i<255; ++i) {
            std::cout << primes() << " is prime\n";
        }
        return EXIT_SUCCESS;

    }
    catch (const std::exception&)
    {
        return EXIT_FAILURE;
    }
}