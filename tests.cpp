#include <cstdlib>
#include <vector>

#include "output_utils.h"
#include "sequences.h"
#include "string_utils.h"
#include "number.h"

int parse_test_main(int argc, char * argv[], char * envp[]) {
    std::vector<std::string> args(argc);
    for( int i=0; i<argc; ++i ) {
        args.emplace_back(argv[i]);
    }
    std::string key, value;

    auto env_map = util::parse_env(envp);
    //util::print_lines(env_map);
    
    util::print_map(env_map);
    return EXIT_SUCCESS;
}
int string_utils_test_main(int argc, char* argv[], char* env[]) {
	const double d = 125489.3254;
	const std::string num_with_commas = util::commify(d);
	std::cout << num_with_commas << std::endl;
	return EXIT_SUCCESS;
}
/// <summary>
/// The entry point for the fibonacci sequence generator.
/// </summary>
/// <returns>0 on success, else <> 0</returns>
int fib_test_main(int argc, char** argv)
{
    try
    {
        auto gen = sequences::get_fibonacci_sequence(10); // max 94 before uint64_t overflows

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

/**
 * \brief Entry point for infinity generator test.
 * \param argc number of elements in argv
 * \param argv a string array containing argc elements.
 * \param env a null terminated array of char* containing
 * the environment variables for this process.
 * \return EXIT_SUCCESS
 */
int inf_test_main(int argc, char* argv[], char* env[]) {
    auto inf = sequences::get_infinite_sequence();
    while (inf)
    {
	    auto i = inf();
    	std::cout << i << " ";
        if (i >= 255)
    		break;
    }
    return EXIT_SUCCESS;
}
void print(math::number n) {
     std::cout << n.lower << " " << n.upper << std::endl;
}
/**
    @brief  
    @param  argc - 
    @param  argv - 
    @param  env  - 
    @retval      - 
**/
int number_test_main(int argc, char* argv[], char* env[]) {
    math::number a{INT64_MAX-1};
    print(a);
    math::number b{7};
    print(b);
    math::number c=a+b;
    print(c);
    for(math::number i{INT64_MAX}; i.upper < INT64_MAX; ++i) {
        print(i);
    }
    return EXIT_SUCCESS;
}

/**
 * \brief Entry point for u64 test.
 * \param argc number of elements in argv
 * \param argv a string array containing argc elements.
 * \param env a null terminated array of char* containing
 * the environment variables for this process.
 * \return EXIT_SUCCESS
 */
int u64_test_main(int argc, char* argv[], char* env[]) {
    u64 window {0xFF};
    for(; window.value<0xFFF; ++window.value)
        print(window);
    return EXIT_SUCCESS;
}