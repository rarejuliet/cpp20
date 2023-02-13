#include "Generator.h"

#include <cstdlib>
#include <format>
#include <iostream>
#include "Generator.h"
#include "sequences.h"

/**
 * \brief Adds two objects together and returns the result.  This function is used
 * in generator_test to test std::format.
 * \param x left hand operand
 * \param y right hand operand
 * \return x + y
 */
auto add(auto x, auto y) {
    return x + y;
}


int generator_test(){
	int rval = EXIT_SUCCESS;
    try {
        int x{ 3 };
        float y{ 4.5 };
        std::cout << std::format("{0} * {1} == {2}\n", x, y, add(x, y));
        auto primes = sequences::get_prime_sequence();
        for (int i = 0; i < 100; ++i) {
            std::cout << primes() << " is prime\n";
        }
        auto fib = sequences::get_fibonacci_sequence(121);
        uint64_t max=94;
        for(uint64_t i=0; i<max; ++i) {
	        std::cout << "fib(" << i << ")==\t" << fib() << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        rval = EXIT_FAILURE;
    }
    return rval;
}
