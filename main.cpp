#include <array>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <format>
#include <exception>
#include "Benchmark.h"
#include "Generator.h"
#include "bible_statistics.h"
#include "sequences.h"
#include "parse_main.h"
#include "output_utils.h"
#include "tests.h"
#include "vfs.h"
#include "concepts.h"
#include "Hashtable.h"
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
        std::cout << std::bitset<8>(18) << "\n";
        //zlib_test_main(argc, argv, env);
        concept_main(argc, argv, env);
	    vfs::vfs_test(argc, argv, env);
	    string_utils_test_main(argc, argv, env);
        fib_test_main(argc, argv);
        inf_test_main(argc, argv, env);
	    bible_main(argc, argv, env);
    	regex_main(argc, argv, env);
    	ht_main(argc,argv,env);
    	parse_test_main(argc, argv, env);
    	ascii_main(argc, argv);
    	bm_main(argc, argv);
    	ss_main(argc, argv);
    	tuple_tie_main(argc,argv,env);
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
