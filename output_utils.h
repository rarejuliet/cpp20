#ifndef OUTPUT_UTILS_H
#define OUTPUT_UTILS_H
#include <iostream>
#include <map>
#include <string>

#include "main.h"
#include "string_utils.h"

namespace util {
	/**
	 * \brief Parse environment variables and put contents in a map, where the variable
	 * name is the key to the value associated with it.  We know exactly what format the
	 * environment variables are in, so most error checking is done away with.
	 * \param env A pointer to an array of char * containing the environment variables for
	 * the current process.
	 * \return A std::map<std::string, std::string> containing the environment variables.
	 */
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

	/**
	 * \brief Print the contents of a map to stdout.  Note that this is a template function,
	 * and it has not been specialized for the new char type char8_t.
	 * \param m A std::map
	 */
	inline void print_map(const auto& m) {
        for (const auto& [key, value] : m)
            std::cout << '[' << key << "] = " << value << "\n";
        
    }

	/**
	 * \brief Print the contents of a to std::cout
	 * \param a A container having an iterator interface.
	 */
	inline void print(auto& a) {
        for (auto &i : a) {
            std::cout << i;
        }
    }

	/**
	 * \brief Print the contents of a to std::cout, followed by a newline.
	 * \param a A container having an iterator interface.
	 */
	inline void println(auto& a) {
        for (auto &i : a) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

	/**
	 * \brief Print the contents of a to std::cout, with each value followed by a newline.
	 * \param a A container having an iterator interface.
	 */
	inline void print_lines(auto& a) {
        for (auto &i : a) {
            std::cout << i << std::endl;
        }
        std::cout << std::endl;
    }
}
#endif
