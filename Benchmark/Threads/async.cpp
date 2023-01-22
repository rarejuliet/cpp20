#include "Generator.h"
#include <coroutine>
#include <iostream>

constexpr bool is_prime(uint64_t n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return true;
    auto sqrt_n = static_cast<uint64_t>(sqrt(n));
    for (uint64_t i = 3; i < sqrt_n; ++i) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

Generator<int64_t> get_primes() {
    static unsigned long long i = 0;
    ++i;
    int64_t num = 0;
    while (true) {
        while (!is_prime(num)) {
            ++num;
        }
        co_yield num;
        ++num;
    }
    //co_return 0;
}


int main(int argc, char ** argv) {
    Generator<int64_t> primes = get_primes();
    for (uint64_t i = 0; i < UINT_MAX; ++i) {
        std::cout << primes.next() << " is prime\n";
    }
    return 0;
}