// Benchmark.cpp : Defines the entry point for the application.
//

#include "Benchmark.h"
#include "../math.h"
int bm_main(int argc, char* argv[]) {
	static_assert(math::Fibonacci::iterative(3) == math::Fibonacci::recursive(3));
	static_assert(math::Fibonacci::recursive(9) == math::Fibonacci::iterative(9));
	uint64_t input {0};

	Benchmark::test t{};
	for(uint64_t i=0; i< math::Fibonacci::MAX_FIBONACCI / 3; ++i)	{
		std::cout << "Recursive: fib(" << i << ") ->\t" << math::Fibonacci::recursive(i) << std::endl;
	}
	t.stop();
	std::cout << "Elapsed time was: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t.elapsed) << "\n";
	Benchmark::test t2{};
	for(uint64_t i=0; i< math::Fibonacci::MAX_FIBONACCI / 3; ++i)	{
		std::cout << "Iterative: fib(" << i << ") ->\t" << math::Fibonacci::iterative(i) << std::endl;
	}
	t2.stop();
	std::cout << "Elapsed time was: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2.elapsed) << "\n";
	std::cout << "It took the recursive function [" << t.elapsed - t2.elapsed << 
		"] ns longer that the iterative one." << std::endl;
	std::cin >> input;

	return EXIT_SUCCESS;
}