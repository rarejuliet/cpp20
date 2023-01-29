#include "Token.h"
int lexer_main(int argc, char* argv[], char** env)
{
    int rval = 0;
    try {
        Lexer lexer(std::cin);
        while (lexer) {
            auto tk = lexer.get_next_token();
            std::cout << "Got token: " << tk->to_string() << " " << tk->Buffer << "\n";
            if (tk->Type == TokenType::Eof)
                break;
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}