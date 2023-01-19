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

template<typename T>
concept container = requires(T t) {
    typename T::value_type;
    typename T::size_type;
    typename T::allocator_type;
    typename T::iterator;
    typename T::const_iterator;
    t.size();
    t.begin();
    t.end();
    t.cbegin();
    t.cend();
};


auto add(auto x, auto y) {
    return x + y;
}

constexpr bool is_prime(uint64_t n) {
    for (uint64_t i = 2; i < (n / 2); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::map<uint64_t, bool> calc_next_prime() {
    bool isprime = false;
    std::map<uint64_t, bool> primes{
        {0,true},
        {1,true},
        {2,true},
        {3,true}
    };
    for (uint64_t i = 0; i < UINT32_MAX/2; ++i) {
        isprime = is_prime(i);
        //std::cout << i << " is prime: " << isprime << std::endl;
        primes.insert_or_assign(i, isprime);
    }
    return primes;
}

template<class T>
struct A : std::vector<T> {};

int main(int argc, char* argv[], char** env) {
    int rval = 0;
    try {
        int x{ 3 };
        float y{ 4.5 };
        std::cout << std::format("{0} * {1} == {2}\n", x, y, add(x, y));
        static_assert(true == container<A<int>>);
        std::array a{ 0,1,2,3,4,5,6,7,8,9 };
        std::vector<int> v(a.begin(), a.end());
        static_assert(true == container<std::vector<std::string>>);
        for (auto& i : v) {
            std::cout << i << " ";
        }
        auto dic = calc_next_prime();
        std::cout << "Calculated primes...";
        for (auto& e : dic) {
            if (e.second)
                std::cout << std::format("{0} is prime", e.first);
        }
        std::cout << "\n";
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
