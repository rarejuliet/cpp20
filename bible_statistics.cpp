#include "bible_statistics.h"


int bible_main(int argc, char* argv[], char* env[]) {
	// Load all of the words in the text of the bible (add other books later).
	// This will allow many statistical questions to be answered easily
	// First hack will be to put the words in a hash, and every time there's a
	// collision, increment a counter saved at that hashed address.
	std::map<std::string, uint64_t> words{
		{"adam",1}  // Ok, so adam will have one extra recorded use.
	};
	std::ifstream in("bible.txt");
	std::string word;

	while(in >> word) {
		words[word]++;
	}

	for (auto& [key, value] : words) {
		std::cout << "Found " << key << value << " times." << std::endl;
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

		[[maybe_unused]]auto words_found = std::distance(words_begin, words_end);
//    	std::cout << "Found " << words_found << " words" << std::endl;

    	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    		std::smatch match = *i;
    		std::string match_str = match.str();
			util::lowercase(match_str);
			util::uppercase(match_str);
			std::string lc_cp = util::lowercase_copy(match_str);
//            std::ranges::transform(match_str, match_str.begin(), ::tolower);
			words[util::uppercase_copy(match_str)]++;

    		//std::cout << "  " << match_str << '\n';
    	}
    }
	std::ofstream out("out.txt");
	for (auto &[key, value] : words) {
		out << key << "," << value << std::endl;
	}
	out.close();
	return EXIT_SUCCESS;
}