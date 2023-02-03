#include <array>
#include <cstdlib>
#include <iostream>
#include <format>
#include <exception>
#include <cstdint>
#include <coroutine>

#include "Benchmark.h"
#include "Generator.h"
#include "../bible_statistics.h"
#include "../sequences.h"
#include "../math.h"



/// <summary>
/// The entry point for the fibonacci sequence generator.
/// </summary>
/// <returns>0 on success, else <> 0</returns>
int test_main(int argc, char** argv)
{
    try
    {
        auto gen = get_fibonacci_sequence(10); // max 94 before uint64_t overflows

        for (int j = 0; gen; j++)
            std::cout << "fib(" << j << ")=" << gen() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown exception.\n";
    }
    return 0;
}


auto add(auto x, auto y) {
    return x + y;
}

/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <param name="env"></param>
/// <returns></returns>
int main(int argc, char* argv[], char* env[])
{
    //bible_main(argc, argv, env);
    regex_main(argc, argv, env);
    //ht_main(argc,argv,env);
    //parser_main(argc, argv, env);
    //ascii_main(argc, argv);
    //bm_main(argc, argv);
    //ss_main(argc, argv);
    int n{};
    std::cin >> n;
    return EXIT_SUCCESS;
    int rval = 0;
    try {
        int x{ 3 };
        float y{ 4.5 };
        std::cout << std::format("{0} * {1} == {2}\n", x, y, add(x, y));
        int i = {};
        std::cout << std::format("{0} is prime", i);
        std::cout << "\n";
        Generator<uint64_t> primes = get_prime_sequence();
        for (int i = 0; i < 100; ++i) {
            std::cout << primes() << " is prime\n";
        }
        Generator<uint64_t> fib = get_fibonacci_sequence(121);
        uint64_t max=121;
        for(uint64_t i=0; i<max; ++i) {
	        std::cout << "fib(" << i << ")==\t" << fib() << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}