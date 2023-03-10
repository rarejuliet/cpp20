#include "concepts.h"

#include <string>
#include <vector>
template<class T>
struct A : public std::vector<T>{};
template<class T>
struct B {};

int concept_main(int argc, char * argv[], char ** env) {
    static_assert(container<A<int>>);
    static_assert(not container<B<int>>);
    static_assert(true == container<std::vector<std::string>>);
    return 0;
}