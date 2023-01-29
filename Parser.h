#ifndef PARSER_H__
#define PARSER_H__
#include <iostream>
#include <map>
#include "Token.h"
#include <memory>
//int parser_main(int argc, char* argv[], char* env[]);

namespace ajc {
	struct Parser {
		Parser(std::istream stream) : s(stream) {
			lex = new Lexer(stream);
		}
		std::map<std::string, double> sym {
			{	"e",2.718281828459045	}
			,{	"pi",3.141592653589793	}
		};
		//constexpr double GetExpr() {
		//	auto t = lex.get_next_token();
		//}
		~Parser() {
			delete lex;
			lex = nullptr;
		}
		Lexer *lex;
		std::istream& s;
	};
}
#endif //PARSER_H__
