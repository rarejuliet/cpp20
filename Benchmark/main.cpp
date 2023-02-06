#include <array>
#include <cstdlib>
#include <iostream>
#include <format>
#include <exception>
#include "Benchmark.h"
#include "Generator.h"
#include "../bible_statistics.h"
#include "../sequences.h"
#include "../Hashtable.h"

/// <summary>
/// The entry point for the fibonacci sequence generator.
/// </summary>
/// <returns>0 on success, else <> 0</returns>
int fib_test_main(int argc, char** argv)
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

/**
 * \brief Entry point for infinity generator test.
 * \param argc number of elements in argv
 * \param argv a string array containing argc elements.
 * \param env a null terminated array of char* containing
 * the environment variables for this process.
 * \return EXIT_SUCCESS
 */
int inf_test_main(int argc, char* argv[], char* env[]) {
    auto inf = get_infinite_sequence();
    while (inf)
    {
	    uint64_t i = inf();
    	std::cout << i << " ";
        if (i >= 255)
    		break;
    }
    return EXIT_SUCCESS;
}


/**
 * \brief Entry point for the application.
 * \param argc 
 * \param argv 
 * \param env 
 * \return 
 */
int main(int argc, char* argv[], char* env[])
{
    try
    {
	    std::istringstream iss{};
        iss.imbue(std::locale("en_US.UTF8"));
        std::cout << "Current locale: " << iss.getloc().name() << std::endl;

        iss.imbue(std::locale());
        std::cout << "Global locale : " << iss.getloc().name() << std::endl;
 
//	    string_utils_test_main(argc, argv, env);
        //fib_test_main(argc, argv);
        //inf_test_main(argc, argv, env);
//	    bible_main(argc, argv, env);
//    	regex_main(argc, argv, env);
    	ht_main(argc,argv,env);
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
