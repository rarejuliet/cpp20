#include <type_traits> // std::alignment_of()
#include <memory>
#include <cstdlib>
#include <vector>
#include <iostream>
//...
//template <class T>
struct MyObj {};
int aligned_main(int argc, char **argv, char **env) {
    char buffer[256]; // for simplicity
    std::cout << "Buffer:" << std::endl;
    for (auto i : buffer) {
        std::cout << i;
    }
    std::cout << "Buffer:" << std::endl;
    size_t alignment = std::alignment_of<int>::value;
    void* ptr = buffer;
    std::size_t space = sizeof(buffer); // Be sure this results in the true size of your buffer

    while (std::align(alignment, sizeof(MyObj), ptr, space)) {
        // You now have storage the size of MyObj, starting at ptr, aligned on
        // int boundary. Use it here if you like, or save off the starting address
        // contained in ptr for later use.
        // ...
        // Last, move starting pointer and decrease available space before
        // the while loop restarts.
        ptr = reinterpret_cast<char*>(ptr) + sizeof(MyObj);
        space -= sizeof(MyObj);
    }
    // At this point, align() has returned a null pointer, signaling it is not
    // possible to allow more aligned storage in this buffer.
    std::cout << "Buffer full." << std::endl;
    return 0;
}