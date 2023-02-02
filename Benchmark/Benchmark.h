#ifndef BENCHMARK_H
#define BENCHMARK_H
// Benchmark.h : Include file for standard system include files,
// or project specific include files.


#include <iostream>
#include <tuple>
#include <chrono>
namespace DateTime {
	using namespace std::chrono;
	auto inline Now() -> time_point<high_resolution_clock>{
		return high_resolution_clock::now();
	}
}
// Code to benchmark here
namespace Fibonacci {
	/**
	 * \brief The highest value for which a compile-time evaluation may occur.  May be
	 * different on various platforms but for MSVC it can go up to 94 before constexpr call limits are exceeded.
	 */
	static constexpr uint64_t MAX_FIBONACCI = 94;

	/**
	 * \brief A recursive fibonacci number generator.
	 * \param num The nth fibonacci number 
	 * \return The nth number in the fibonacci sequence. 
	 */
	constexpr uint64_t recursive(const uint64_t num) {
//		[[unlikely]]
		if( num < 2 )
			return num;
		return recursive(num-1) + recursive(num-2);
	}

	/**
	 * \brief An iterative solution to the fibonacci sequence.
	 * \param num The nth fibonacci number
	 * \return The nth number in the fibonacci sequence.
	 */
	constexpr uint64_t iterative(const uint64_t num) {
		if( num < 2 )
			return num;
		uint64_t p {1};
		uint64_t pp {0};
		uint64_t tmp{p+pp};
		for(uint64_t i=0; i<num; ++i) {
			tmp = p + pp;
			p=pp;
			pp=tmp;
		}
		return tmp;
	}
}

namespace Benchmark {
	using namespace std::chrono;
//	extern uint64_t MAX_FIBONACCI;
	struct test {
		test() {
			t0 = high_resolution_clock::now();
//			elapsed;
		}
		time_point<high_resolution_clock, nanoseconds> t0{}; // = high_resolution_clock::now();
		time_point<high_resolution_clock, nanoseconds> t1{};
		nanoseconds elapsed;
		void start() {
			t0 = high_resolution_clock::now();
		}
		void stop() {
			t1 = high_resolution_clock::now();
			elapsed = t1-t0;
		}

	};
}
//auto t2 = std::chrono::high_resolution_clock::now();
//auto dur = t2 - t1;
int dc_main(int argc, char* argv[]);
int ascii_main(int argc, char* argv[]);
int ss_main(int argc, char* argv[]);
int bm_main(int argc, char* argv[]);
// TODO: Reference additional headers your program requires here.
#endif //defined BENCHMARK_H