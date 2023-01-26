#include <iostream>
#include <tuple>        // for tie() tuple_cat() swap() and tuple
#include <cstdlib>      // EXIT_SUCCESS and EXIT_FAILURE
#include <thread>       // jthread
int tuple_cat_main(int argc, char **argv, char **env)
{
    using namespace std;
    // Initializing 1st tuple
    tuple <int, char, float> tup1(20, 'g', 17.5);

    // Initializing 2nd tuple
    tuple <int, char, float> tup2(30, 'f', 10.5);

    // Concatenating 2 tuples to return a new tuple
    auto tup3 = tuple_cat(tup1, tup2);

    // Displaying new tuple elements
    cout << "The new tuple elements in order are : ";
    cout << get<0>(tup3) << " " << get<1>(tup3) << " ";
    cout << get<2>(tup3) << " " << get<3>(tup3) << " ";
    cout << get<4>(tup3) << " " << get<5>(tup3) << endl;

    return EXIT_SUCCESS;
}

int tuple_swap_main(int argc, char** argv, char** env)
{
    using namespace std;
    // Initializing 1st tuple
    tuple <int, char, float> tup1(20, 'g', 17.5);

    // Initializing 2nd tuple
    tuple <int, char, float> tup2(10, 'f', 15.5);

    // Printing 1st and 2nd tuple before swapping
    cout << "The first tuple elements before swapping are : ";
    cout << get<0>(tup1) << " " << get<1>(tup1) << " "
        << get<2>(tup1) << endl;
    cout << "The second tuple elements before swapping are : ";
    cout << get<0>(tup2) << " " << get<1>(tup2) << " "
        << get<2>(tup2) << endl;

    // Swapping tup1 values with tup2
    tup1.swap(tup2);

    // Printing 1st and 2nd tuple after swapping
    cout << "The first tuple elements after swapping are : ";
    cout << get<0>(tup1) << " " << get<1>(tup1) << " "
        << get<2>(tup1) << endl;
    cout << "The second tuple elements after swapping are : ";
    cout << get<0>(tup2) << " " << get<1>(tup2) << " "
        << get<2>(tup2) << endl;

    return EXIT_SUCCESS;
}

int tuple_tie_main(int argc, char** argv, char** env) {
    using namespace std;
    // Initializing variables for unpacking
    int i_val;
    char ch_val;
    float f_val;

    // Initializing tuple
    tuple <int, char, float> tup1(20, 'g', 17.5);

    // Use of tie() without ignore
    tie(i_val, ch_val, f_val) = tup1;

    // Displaying unpacked tuple elements
    // without ignore
    cout << "The unpacked tuple values (without ignore) are : ";
    cout << i_val << " " << ch_val << " " << f_val;
    cout << endl;

    // Use of tie() with ignore
    // ignores char value
    tie(i_val, ignore, f_val) = tup1;

    // Displaying unpacked tuple elements
    // with ignore
    cout << "The unpacked tuple values (with ignore) are : ";
    cout << i_val << " " << f_val;
    cout << endl;

    return EXIT_SUCCESS;

}

int jthread_main(int argc, char** argv, char** env) {
    using std::cout;
    uint32_t n = std::jthread::hardware_concurrency();
    cout << n << " concurrent threads are supported.\n";

    cout << "main(" << argc << ", ";
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << ", ";
    }
    for (int i = 0; i < argc; ++i) {
        cout << env[i];
    }
    cout << "\n";
    tuple_cat_main(argc, argv, env);
    tuple_swap_main(argc, argv, env);
    tuple_tie_main(argc, argv, env);
    return EXIT_SUCCESS;
}