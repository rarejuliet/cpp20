#include <array>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <format>
#include <exception>
#include "Benchmark.h"
#include "Generator.h"
#include "bible_statistics.h"
#include "BigInteger.h"
#include "sequences.h"
#include "parse_main.h"
#include "output_utils.h"
#include "tests.h"
#include "vfs.h"
#include "concepts.h"
#include "Hashtable.h"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include "BigInt.h"
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

        BigInteger max_value = BigInteger("99999");
        for (BigInteger i=max_value-BigInteger(UINT64_MAX); i<max_value ; ++i) {
		    std::cout << "Is " << i.getNumber() << " prime?: ";
//            std::cout << math::is_prime_b(i) << std::endl;
	    }

        Benchmark::test t1;
        bool isprime =  math::is_prime_a(1073741);
        t1.stop();
        Benchmark::test t2;
        bool isprime2 = math::is_prime_b(1073741);
        t2.stop();

        std::cout << "It took is_prime_a(1073741827) " << std::chrono::duration_cast<std::chrono::nanoseconds>(t1.elapsed) << std::endl;
        std::cout << "It took is_prime_b(1073741827) " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2.elapsed) << std::endl;

        auto difference = std::chrono::duration_cast<std::chrono::nanoseconds>(t1.elapsed-t2.elapsed);
        std::cout << "That is a difference of " << difference << std::endl;



        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(t1.elapsed-t2.elapsed);

        auto n = 247;
        std::cout << boost::format("Is %1% prime?: %2%") % n % math::is_prime_a(n);
        std::cout << math::is_prime_a(n) << std::endl;
        auto p = 37;
        std::cout << boost::format("Is %1% prime?: %2%") % p % math::is_prime_a(p);
        std::cout << math::is_prime_a(37) << std::endl;

        util::print_map(util::parse_env(env));
        concept_main(argc, argv, env);
	    //vfs::vfs_test(argc, argv, env);
	    //string_utils_test_main(argc, argv, env);
        fib_test_main(argc, argv);
        inf_test_main(argc, argv, env);
        //sequence_main(argc, argv, env);
	    //bible_main(argc, argv, env);
    	regex_main(argc, argv, env);
    	//ht_main(argc,argv,env);
    	//parse_test_main(argc, argv, env);
    	//ascii_main(argc, argv);
        //u64_test_main(argc, argv, env);
    	//bm_main(argc, argv);
    	//ss_main(argc, argv);
    	//tuple_tie_main(argc,argv,env);
        //zlib_test_main(argc, argv, env);
        //maze_test_main(argc, argv, env);
        //number_test_main(argc, argv, env);
        time_test_main(argc, argv, env);
    }
	catch(std::exception& e)
    {
	    std::cout << "Caught a std::exception.  The message is:\n\t" << 
            e.what() << std::endl;
    }
    int n{};
//    std::cin >> n;
    return EXIT_SUCCESS;
}
