#include "bible_statistics.h"








#include <cstdlib>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

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

	while(in) {
		in >> word;
		words[word]++;
	}

	for (auto word : words)
	{
		std::cout << "Found " << word.first << " was found " << word.second <<
			" times." << std::endl;
	}

	// a space separated list of words (tokens)
	return EXIT_SUCCESS;
}
