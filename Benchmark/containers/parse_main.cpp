#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <map>

void print_map(std::map<std::string, std::string> m) {
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "\n";
}
void print(auto& a) {
    for( auto i : a ) {
        std::cout << i;
    }
}
void println(auto& a) {
    for( auto i : a ) {
        std::cout << i;
    }
    std::cout << std::endl;
}
void print_lines(auto& a) {
    for( auto i : a ) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char * argv[], char * envp[]) {
    std::vector<std::string> args(argc);
    for( int i=0; i<argc; ++i ) {
        args.push_back(argv[i]);
    }
    std::string key, value;
    print_lines(args);

    std::map<std::string, std::string> env_map{
        {"HOSTNAME","hyperion"},
        {"COMPUTERNAME","Hyperion"},
        {"PATH", "C:\\Users\\Adam\\bin"},
        {"LIB", "C:\\Users\\Adam\\lib"}
    };

    print_map(env_map);
    const char* env[]{
         "HOSTNAME"
        ,"COMPUTERNAME"
        ,"PATH"
        ,"LIB"
        ,"OS"
        ,"PATHEXT"
        ,"USERNAME"
    };
    if (const char* env_p = std::getenv("HOSTNAME"))
        std::cout << "Your HOSTNAME is: " << env_p << "\n";
    if (const char* env_p = std::getenv("PATH"))
        std::cout << "Your PATH is: " << env_p << "\n";
    print_lines(env);
    for(auto s : env) {
        if(std::getenv(s))
            std::cout << s << " == " << std::getenv(s) << std::endl;
    }
    //for (auto s : env) {
    //    std::cout << s << " == " << std::setenv(s, env_map[s]) <<
    //        std::endl;
    //}
    std::cout << "Now raw printing env..." << std::endl;
    for (int i = 0; i < 255; ++i) {
        std::cout << "Checking [" << i << "]\n";
        if (envp[i]) {
            std::string s{ envp[i] };
            auto equals = s.find('=');
            std::string first = s.substr(0, equals);
            std::string second = s.substr(equals + 1);
            std::cout << first << " == " << second << std::endl;
            env_map.insert(std::make_pair(first, second));
            std::cout << "envp[" << i << "]: " << envp[i] << std::endl;
            env_map[first]=second;
        }
        else {
            std::cout << "envp[" << i << "]: " << "nullptr" << std::endl;
            break;
        }
    }
    print_map(env_map);
    return EXIT_SUCCESS;
}