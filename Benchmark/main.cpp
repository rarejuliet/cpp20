#include <array>
#include <cstdlib>
#include <iostream>
#include <format>
#include <exception>

#include "Benchmark.h"
#include "Generator.h"
#include "../bible_statistics.h"
#include "../sequences.h"

/// <summary>
/// The entry point for the fibonacci sequence generator.
/// </summary>
/// <returns>0 on success, else <> 0</returns>
int test_main(int argc, char** argv)
{
    try
    {
        auto gen = get_fibonacci_sequence(10); // max 94 before uint64_t overflows

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


int tuple_tie_main(int argc, char* argv[], char* env[]);


int main(int argc, char* argv[], char* env[])
{
    try
    {
        test_main(argc, argv);
//	    bible_main(argc, argv, env);
//    	regex_main(argc, argv, env);
    	//ht_main(argc,argv,env);
    	//parse_main(argc, argv, env);
    	//ascii_main(argc, argv);
    	//bm_main(argc, argv);
    	//ss_main(argc, argv);
    	//tuple_tie_main(argc,argv,env);
    }
	catch(std::exception& e)
    {
	    std::cout << "Caught a std::exception.  The message is:\n\t" << 
            e.what() << std::endl;
    }
    int n{};
    std::cin >> n;
    return EXIT_SUCCESS;
}
