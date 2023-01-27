#ifndef TOKEN_H__
#define TOKEN_H__
#include <iostream>
#include <cctype>

enum class TokenType {
	Id, Number, Sin, Cos, Tan, Asin, Acos, Atan, Log, Exp,
	Log10, Exp10, Sqrt, Int, Assign = '=', Plus = '+', Minus = '-',
	Mul = '*', Div = '/', Mod = '%', Pow = '^', Lp = '(', Rp = ')', Eofsym = -1

};
class Token {
public:
	TokenType Type = TokenType::Eofsym;
	std::string Buffer;
	explicit Token(TokenType t, std::string buffer) : Type(t), Buffer(buffer) {}
	static Token* CreateToken(TokenType t, std::string buffer) {
		//	std::make_unique()
		//	std::unique_ptr<Token> tk = new Token(t, buffer);
		return new Token(t, buffer);
	}
};

class Lexer {
public:
	Lexer(std::istream& s) : stream(s), buf("") {}
	Token* get_next_token() {
		char ch = stream.get();
		char la{ };
		switch (ch) {
		case	'0':
		case	'1':
		case	'2':
		case	'3':
		case	'4':
		case	'5':
		case	'6':
		case	'7':
		case	'8':
		case	'9':
			buf += ch;
			while (isdigit(la = stream.peek())) {
				buf += stream.get();
			}
			return Token::CreateToken(TokenType::Number, buf);
			break;
		case static_cast<int>(TokenType::Number): {
			buf += ch;
			char la{};
			while (isdigit(la = stream.peek())) {
				buf += stream.get();
				return Token::CreateToken(TokenType::Number, buf);
			}
		}
		}
		return Token::CreateToken(TokenType::Number, buf);

	}
private:
	std::istream &stream;
	std::string buf;
};

#endif //TOKEN_H__