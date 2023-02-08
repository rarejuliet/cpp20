#include "concepts.h"

#include <string>
#include <vector>

int concept_main(int argc, char * argv[], char ** env) {
    static_assert(container<A<int>>);
    static_assert(not container<B<int>>);
    std::vector<int> is;
    static_assert(true == container<std::vector<std::string>>);
    return 0;
}