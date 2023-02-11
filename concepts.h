#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <vector>
#include <string>
#include <iostream>
#include <format>

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
int concept_main(int argc, char * argv[], char ** env);

#endif
