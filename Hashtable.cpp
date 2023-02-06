#include "Hashtable.h"
#include <iostream>
#include "string_utils.h"
int string_utils_test_main(int argc, char* argv[], char* env[]) {
	const double d = 125489.3254;
	const std::string num_with_commas = util::commify(d);
	std::cout << num_with_commas << std::endl;
	return EXIT_SUCCESS;
}
int ht_main(int argc, char* argv[], char* env[]) {
	string_utils_test_main(argc, argv, env);
	containers::Hashtable<char8_t> tbl{};
	tbl.set("zero",'0');
	tbl.set("one",'1');
	tbl.set("two",'2');
	tbl.set("three",'3');
	tbl.set("four",'4');
	tbl.set("five",'5');
	tbl.set("six",'6');
	tbl.set("seven",'7');
	tbl.set("eight",'8');
	tbl.set("nine",'9');
	tbl.set("A",'A');
	tbl.set("B",'B');
	tbl.set("C",'C');
	tbl.set("D",'D');
	tbl.set("E",'E');
	tbl.set("F",'F');
	tbl.set("G",'G');
	tbl.set("H",'H');
	tbl.set("I",'I');
	tbl.set("J",'J');
	tbl.set("K",'K');
	tbl.set("L",'L');
	tbl.set("M",'M');
	tbl.set("N",'N');
	tbl.set("O",'O');
	tbl.set("P",'P');
	tbl.set("Q",'Q');
	tbl.set("R",'R');
	tbl.set("S",'S');
	tbl.set("T",'T');
	tbl.set("U",'U');
	tbl.set("V",'V');
	tbl.set("W",'W');
	tbl.set("X",'X');
	tbl.set("Y",'Y');
	tbl.set("Z",'Z');
	tbl.set("a",'a');
	tbl.set("b",'b');
	tbl.set("c",'c');
	tbl.set("d",'d');
	tbl.set("e",'e');
	tbl.set("f",'f');
	tbl.set("g",'g');
	tbl.set("h",'h');
	tbl.set("i",'i');
	tbl.set("j",'j');
	tbl.set("k",'k');
	tbl.set("l",'l');
	tbl.set("m",'m');
	tbl.set("n",'n');
	tbl.set("o",'o');
	tbl.set("p",'p');
	tbl.set("q",'q');
	tbl.set("r",'r');
	tbl.set("s",'s');
	tbl.set("t",'t');
	tbl.set("u",'u');
	tbl.set("v",'v');
	tbl.set("w",'w');
	tbl.set("x",'x');
	tbl.set("y",'y');
	tbl.set("z",'z');

	std::cout << "tbl.size() == ";
	std::cout << tbl.size() << std::endl;
	std::cout << "tbl.max_size() == ";
	std::cout << util::commify(tbl.max_size()) << std::endl;
	std::cout << "tbl.capacity() == ";
	std::cout << util::commify(tbl.capacity()) << std::endl;

	for (const auto &[key, val] : tbl.items)
	{
		std::cout << key << ": " << static_cast<char>(val) << std::endl;
	}
	return EXIT_SUCCESS;
}
