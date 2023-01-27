#ifndef TOKEN_H__
#define TOKEN_H__
#include <iostream>
#include <cctype>

enum class TokenType {
	Id, Number, Sin, Cos, Tan, Asin, Acos, Atan, Log, Exp,
	Log10, Exp10, Sqrt, Int, Assign = '=', Plus = '+', Minus = '-',
	Mul = '*', Div = '/', Mod = '%', Pow = '^', Lp = '(', Rp = ')', Eofsym = -1

};
struct Token {
	TokenType Type;
	std::string buf;
};
class Lexer {
public:
	Lexer(std::istream& s) : stream(s), buf("") {}
	Token get_next_token() {
		char ch = stream.get();
		switch (ch) {
		case (int)TokenType::Number: {
				buf += ch;
				while(isdigit(stream.peek())) {
					buf += stream.get();
					return Token(TokenType::Number, buf);
				}
			}
		}
	}
private:
	std::istream &stream;
	std::string buf;
};

#endif //TOKEN_H__