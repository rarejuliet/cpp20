#include "Benchmark/Benchmark.h"
#include "Token.h"
#include <string_view>
#include <iostream>

int ss_main(int argc, char* argv[]) {
	try
	{
	auto s = std::stringstream("78+65-9+(9*3-(3/4))+2");
	auto s2 = std::stringstream("pi/4*3.49-(e^2)");
	Lexer l(s2);
	Lexer l2(s);
	while(l) {
		auto tk = l.get_next_token();
		std::cout << "Got token: " << tk->to_string() << ": " << tk->Buffer
			<< std::endl;
		if (tk->Type == TokenType::Eof)
			break;
	}

	while( l2 )	{
		auto tk = l.get_next_token();
		std::cout << "Got token: " << tk->to_string() << ": " << tk->Buffer
			<< std::endl;
		if (tk->Type == TokenType::Eof)
			break;
	}
		
	} catch (std::exception& e) {
		std::cerr << "Caught a std::exception"
		std::cerr << e.what() << "\n";
	}
	return EXIT_SUCCESS;
}