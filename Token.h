#ifndef TOKEN_H__
#define TOKEN_H__
#include <iostream>
#include <cctype>
#include <memory>
#include <string>

enum class TokenType {
	Id,
	Number,
	Sin,
	Cos,
	Tan,
	Log,
	Exp,
	Log10,
	Exp10,
	Sqrt,
	Int,
	Dot = '.',
	Assign = '=',
	Plus = '+',
	Minus = '-',
	Mul = '*',
	Div = '/',
	Mod = '%',
	Pow = '^',
	Lp = '(',
	Rp = ')',
	Eofsym = -1
};

class Token {
public:
	TokenType Type = TokenType::Eofsym;
	std::string Buffer;
	explicit Token(TokenType t, std::string buffer) : Type(t), Buffer(buffer) {}
	static std::unique_ptr<Token> CreateToken(TokenType t, std::string buffer) {
		auto tk = std::make_unique<Token>(t, buffer);
//		std::unique_ptr<Token> tk(new Token(t, buffer));
		return tk;
	}
	std::string toString() {
		std::string rv{ "" };
		switch (this->Type) {
		case TokenType::Id:
			rv = "Id";
			break;
		case TokenType::Number:
			rv = "Number";
			break;
		case TokenType::Int:
			rv = "Int";
			break;
		case TokenType::Assign:
			rv = "Assign";
			break;
		case TokenType::Plus:
			rv = "Plus";
			break;
		case TokenType::Minus:
			rv = "Minus";
			break;
		case TokenType::Mul:
			rv = "Mul";
			break;
		case TokenType::Div:
			rv = "Div";
			break;
		case TokenType::Mod:
			rv = "Mod";
			break;
		case TokenType::Pow:
			rv = "Pow";
			break;
		case TokenType::Lp:
			rv = "Lp";
			break;
		case TokenType::Rp:
			rv = "Rp";
			break;
		case TokenType::Dot:
			rv = "Dot";
			break;
		case TokenType::Eofsym:
			rv = "Eofsym";
			break;
		}
		return rv;
	}
};

class Lexer {
public:
	Lexer(std::istream& s) : stream(s), buf("") {}
	operator bool() {
		return !stream.eof();
	}
	std::unique_ptr<Token> get_next_token() {
		char ch = stream.get();
		char la{ };
		TokenType type = TokenType::Eofsym;
		buf = ch;
		double num{ 0 };
		switch (ch) {
			buf += ch;
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
			case	'.':
				type = TokenType::Number;
				stream.putback(ch);
				stream >> num;
				buf = std::to_string(num);
				//while (isdigit(la = stream.peek())) {
				//	buf += stream.get();
				//}
				break;
			case '+':
				type = TokenType::Plus;
				break;
			case '-':
				type = TokenType::Minus;
				break;
			case '*':
				type = TokenType::Mul;
				break;
			case '/':
				type = TokenType::Div;
				break;
			case '^':
				type = TokenType::Pow;
				break;
			case '%':
				type = TokenType::Mod;
				break;
			case '(':
				type = TokenType::Lp;
				break;
			case ')':
				type = TokenType::Rp;
				break;
			//case '.':
			//	type = TokenType::Dot;
			//	break;
			default:
				type = TokenType::Eofsym;
				break;
		}
		return Token::CreateToken(type, buf);
	}
private:
	std::istream &stream;
	std::string buf;
};
/// <summary>
/// A test driver for Lexer.
/// </summary>
int lexer_main(int argc, char* argv[], char* env[]);
#endif //TOKEN_H__