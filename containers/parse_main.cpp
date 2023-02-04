#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <cstdio>
#include <map>
#include "../Token.h"
#include "../bible_statistics.h"
#include "../output_utils.h"


int parse_main(int argc, char * argv[], char * envp[]) {
    std::vector<std::string> args(argc);
    for( int i=0; i<argc; ++i ) {
        args.emplace_back(argv[i]);
    }
    std::string key, value;

    auto env_map = util::parse_env(envp);
    //util::print_lines(env_map);
    
    util::print_map(env_map);
    return EXIT_SUCCESS;
}