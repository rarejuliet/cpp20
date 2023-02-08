#ifndef TOKEN_H__
#define TOKEN_H__
#include <iostream>
#include <cctype>
#include <memory>
#include <string>

enum class TokenType : char {
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
	Eof = -1
};

/**
 * @brief 
 */
class Token {
public:

	TokenType Type = TokenType::Eof;
	std::string Buffer;
	explicit Token(TokenType t, std::string buffer) :
		Type(t), Buffer(std::move(buffer)) {}
	static auto CreateToken(TokenType t, const std::string& buffer) {
		//		std::unique_ptr<Token> tk(new Token(t, buffer));
		// Supposedly it's better to do it this way.
		//auto tk = std::make_unique<Token>(t, buffer);
		return std::make_unique<Token>(t, buffer);
		//return tk;
	}

	/**
	 * @brief Returns a string representation of this Token
	 * @return A string name for the enumerated value.
	 */
	[[nodiscard]] auto to_string() const -> std::string {
		std::string rv;
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
		case TokenType::Eof:
			rv = "Eof";
			break;
		case TokenType::Sin:
			rv = "Sin";
			break;
		case TokenType::Cos:
			rv = "Cos";
			break;
		case TokenType::Tan:
			rv = "Tan";
			break;
		case TokenType::Log:
			rv = "Log";
			break;
		case TokenType::Exp:
			rv = "Exp";
			break;
		case TokenType::Log10:
			rv = "Log10";
			break;
		case TokenType::Exp10:
			rv = "Exp10";
			break;
		case TokenType::Sqrt:
			rv = "Sqrt";
			break;
		default: 
			rv = "Eof";
		}
		return rv;
	}
};

class Lexer {
public:
	Lexer(std::istream& s) : stream(s), buf(std::string("")) {}

	/**
	 * \brief operator bool - Used to detect when the stream has reached eof.
	 */
	explicit operator bool() const {
		return !stream.eof();
	}

	/**
	 * \brief Retrieves the next token in the input stream.
	 * \return unique_ptr<Token> 
	 */
	std::unique_ptr<Token> get_next_token() {
		char ch{};
		ch = stream.get();
		char la{ };
		TokenType type = TokenType::Eof;
		buf = ch;
		double num{ 0 };
		//buf += ch;
		switch (ch) {
		case 'a': case 'b': case 'c': case 'd': case 'e':
		case 'f': case 'g': case 'h': case 'i': case 'j':
		case 'k': case 'l': case 'm': case 'n': case 'o':
		case 'p': case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x': case 'y':
		case 'z':
		case 'A': case 'B': case 'C': case 'D': case 'E':
		case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O':
		case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y':
		case 'Z':
			type = TokenType::Id;
			while(isalnum(stream.peek())) {
				buf += stream.get();
			}
			break;
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
				type = TokenType::Eof;
				break;
		}
		return Token::CreateToken(type, std::move(buf));
	}
private:
	std::istream &stream;
	std::string buf;
};
struct Node {
	/**
	 * \brief 
	 * \param t
	 */
	Node(Token t) : token(std::move(t)) {}
	Token token;
	Node* left = nullptr;
	Node* right= nullptr;
};
/**
    @struct Expression
    @brief  
**/
struct Expression : Node{
	Expression(std::unique_ptr<Node> &root_node) : Node(std::move(root_node->token)) {}
	std::unique_ptr<Node> root;
};
/**

    @class   Parser
    @brief   
    @details ~

**/
class Parser {
public:
	explicit Parser(std::istream& is) {
		lexer = std::make_unique<Lexer>(is);
	}
	void expr() {
		std::unique_ptr<Token> t = lexer->get_next_token();
		std::unique_ptr<Token> la = lexer->get_next_token();
		Node node(std::move(*t));

		switch (t->Type)
		{

		case TokenType::Id: break;
		case TokenType::Number:
			//Should find an operator and another Number
			node.left->token = *t;
			t = lexer->get_next_token();
			
			break;
		case TokenType::Sin: break;
		case TokenType::Cos: break;
		case TokenType::Tan: break;
		case TokenType::Log: break;
		case TokenType::Exp: break;
		case TokenType::Log10: break;
		case TokenType::Exp10: break;
		case TokenType::Sqrt: break;
		case TokenType::Int: break;
		case TokenType::Dot: break;
		case TokenType::Assign: break;
		case TokenType::Plus: break;
		case TokenType::Minus: break;
		case TokenType::Mul: break;
		case TokenType::Div: break;
		case TokenType::Mod: break;
		case TokenType::Pow: break;
		case TokenType::Lp: break;
		case TokenType::Rp: break;
		case TokenType::Eof: break;
		default:
			//If we got here, there's some error.
			break;
		}
		return;
	}
private:
	std::unique_ptr<Lexer> lexer = nullptr;
};

/// <summary>
/// A test driver for Lexer.
/// </summary>
int lexer_main(int argc, char* argv[], char* env[]);
//int parser_main(int argc, char* argv[], char* env[]);
#endif //TOKEN_H__