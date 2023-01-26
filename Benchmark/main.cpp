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
#include "Generator.h"

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
    auto sqrt_n = static_cast<uint64_t>(sqrt(n));
    for (uint64_t i = 3; i < sqrt_n; ++i) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

//uint64_t get_next_prime() {
//    bool isprime = false;
//    uint64_t i = 0;
//    for (i = 0; i < UINT32_MAX/2; ++i) {
//        co_await isprime = is_prime(i);
//        if (isprime)
//            co_return i;
//    }
//    co_return i;
//}

/* */
Generator<int64_t> get_primes()
{
    int64_t n = 0;
    while (n<UINT_MAX) {
        while (!is_prime(n)) {
            ++n;
        }
        co_yield n;
        ++n;
    }
}
/// <summary>
/// Adds two items.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
auto add(auto x, auto y) { return x + y; }

/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <param name="env"></param>
/// <returns></returns>
int main(int argc, char* argv[], char** env)
{
    int rval = 0;
    try {
        int x{ 3 };
        float y{ 4.5 };
        std::cout << std::format("{0} * {1} == {2}\n", x, y, add(x, y));
        int i = {};
        std::cout << std::format("{0} is prime", i);
        std::cout << "\n";
        Generator<int64_t> primes = get_primes();
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