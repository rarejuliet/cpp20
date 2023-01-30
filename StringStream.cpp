#include "Benchmark/Benchmark.h"
#include "Token.h"
#include <string_view>
#include <iostream>

int ss_main(int argc, char* argv[]) {
	auto s = std::stringstream("78+65-9+(9*3-(3/4))+2");
	Lexer l(s);
	while(l) {
		auto tk = l.get_next_token();
		std::cout << "Got token: " << tk->to_string() << ": " << tk->Buffer
			<< std::endl;
	}
	return EXIT_SUCCESS;
}