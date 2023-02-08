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
		nanoseconds elapsed{};
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
int tuple_tie_main(int argc, char* argv[], char* env[]);
int inf_test_main(int argc, char* argv[], char* env[]);
// TODO: Reference additional headers your program requires here.
#endif //defined BENCHMARK_H