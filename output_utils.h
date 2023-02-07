#ifndef OUTPUT_UTILS_H
#define OUTPUT_UTILS_H
#include <iostream>
#include <map>
#include <string>

#include "main.h"
#include "string_utils.h"

namespace util {
	inline auto parse_env(char** env) {
        std::map<std::string, std::string> env_map{};
        for (int i = 0; env[i]; ++i) {
			if(DEBUG) {
				std::cerr << "Checking [" << i << "]\n";
            }
        	std::string s{ env[i] };
            auto equals = s.find('=');
            // Make sure all variable names are in uppercase so we don't have problems
            //with lookup later.
            std::string first = util::uppercase_copy(s.substr(0, equals));
            std::string second = s.substr(equals + 1);
            if(DEBUG)
				std::cerr << first << " == " << second << std::endl;
            env_map.insert(std::make_pair(first, second));
            if(DEBUG){
        		std::cerr << "envp[" << i << "]: " << env[i] << std::endl;
            }
            env_map[first] = second;
        }
        return env_map;
    }

    inline void print_map(const auto& m) {
        for (const auto& [key, value] : m)
            std::cout << '[' << key << "] = " << value << "\n";
    }
    inline void print(auto& a) {
        for (auto &i : a) {
            std::cout << i;
        }
    }
    inline void println(auto& a) {
        for (auto &i : a) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
    inline void print_lines(auto& a) {
        for (auto &i : a) {
            std::cout << i << std::endl;
        }
        std::cout << std::endl;
    }
}
#endif
