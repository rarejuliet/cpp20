#ifndef OUTPUT_UTILS_H
#define OUTPUT_UTILS_H
#include <iostream>
#include <map>
#include <string>
namespace util {
    std::map<std::string, std::string> parse_env(char** env) {
        std::map<std::string, std::string> env_map{};
        for (int i = 0; i < 16386; ++i) {
            std::cout << "Checking [" << i << "]\n";
            if (env[i]) {
                std::string s{ env[i] };
                auto equals = s.find('=');
                std::string first = s.substr(0, equals);
                std::string second = s.substr(equals + 1);
                std::cout << first << " == " << second << std::endl;
                env_map.insert(std::make_pair(first, second));
                std::cout << "envp[" << i << "]: " << env[i] << std::endl;
                env_map[first] = second;
            }
            else {
                std::cout << "envp[" << i << "]: " << "nullptr" << std::endl;
                break;
            }
        }
        return env_map;
    }

    void print_map(std::map<std::string, std::string>& m) {
        for (const auto& [key, value] : m)
            std::cout << '[' << key << "] = " << value << "\n";
    }
    void print(auto& a) {
        for (auto &i : a) {
            std::cout << i;
        }
    }
    void println(auto& a) {
        for (auto &i : a) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
    void print_lines(auto& a) {
        for (auto &i : a) {
            std::cout << i << std::endl;
        }
        std::cout << std::endl;
    }
}

int parse_main(int argc, char * argv[], char * envp[]);
#endif
