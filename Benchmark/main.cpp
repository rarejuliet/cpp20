#include <array>
#include <cstddef>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <format>
#include <exception>
#include <initializer_list>
#include <cstdint>
#include <map>
#include <coroutine>

#include "Benchmark.h"
#include "Generator.h"
#include "../Token.h"
#include "../Parser.h"

namespace ajc {
/// <summary>
/// Start at 3 and check up to sqrt(n).  Even numbers are ignored since
/// they would have been found by division by 2 already.
/// </summary>
/// <param name="n">An unsigned number/param>
/// <returns>true if prime, else false</returns>
    constexpr bool isPrime(uint64_t n) {
        if (n < 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        auto sqrt_n = static_cast<uint64_t>(sqrt(n));
        for (auto i = 3ul; i <= sqrt_n; i += 2ul) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }

    constexpr bool is_prime(uint64_t n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        const auto sqrt_n = static_cast<uint64_t>(sqrt(n));
        for (uint64_t i = 3; i < sqrt_n; ++i) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }
}


ajc::Generator<int64_t> get_primes()
{
    int64_t n = 0;
    while (n<UINT_MAX) {
        while (!ajc::is_prime(n)) {
            ++n;
        }
        co_yield n;
        ++n;
    }
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int test_main(int argc, char** argv)
{
    try
    {
        auto gen = fibonacci_sequence(10); // max 94 before uint64_t overflows

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
int main(int argc, char* argv[], char** env)
{
    //parser_main(argc, argv, env);
    ascii_main(argc, argv);
   // bm_main(argc, argv);
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
        ajc::Generator<int64_t> primes = get_primes();
        for (int i = 0; i < 100; ++i) {
            std::cout << primes() << " is prime\n";
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}