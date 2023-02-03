#include "bible_statistics.h"

#include <regex>

int bible_main(int argc, char* argv[], char* env[]) {
	// Load all of the words in the text of the bible (add other books later).
	// This will allow many statistical questions to be answered easily
	// First hack will be to put the words in a hash, and every time there's a
	// collision, increment a counter saved at that hashed address.
	std::map<std::string, uint64_t> words{
		{"Adam",1},
		{"Roberta",1}
	};
	std::ifstream in("bible.txt");
	std::string word;

	while(in >> word) {
		//in >> word;
		words[word]++;
	}

	for (auto wrd : words) {
		std::cout << "Found " << wrd.first << " was found " << wrd.second <<
			" times." << std::endl;
	}

	// a space separated list of words (tokens)
	return EXIT_SUCCESS;
}

int regex_main(int argc, char* argv[], char* env[]) {
	std::map<std::string, uint64_t> words{
		{"Adam",1},
		{"Roberta",1}
	};
    std::ifstream in("bible.txt");
    std::string buf;
    while(std::getline(in,buf)) {
    	std::regex word_regex("(\\w+)");

    	auto words_begin = 
			std::sregex_iterator(buf.begin(), buf.end(), word_regex);
    	auto words_end = std::sregex_iterator();

    	std::cout << "Found "
				  << std::distance(words_begin, words_end)
				  << " words\n";

    	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    		std::smatch match = *i;
    		std::string match_str = match.str();
			words[match_str]++;
    		std::cout << "  " << match_str << '\n';
    	}
    }
	for (auto wrd : words) {
		std::cout << "Found " << wrd.first << " was found " << wrd.second <<
			" times." << std::endl;
	}
	  return EXIT_SUCCESS;
}