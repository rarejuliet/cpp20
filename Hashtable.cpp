#include "Hashtable.h"

#include <iostream>


int ht_main(int argc, char* argv[], char* env[]) {
	containers::Hashtable<char8_t> tbl(0);
	tbl.Set("zero",'0');
	tbl.Set("one",'1');
	tbl.Set("two",'2');
	tbl.Set("three",'3');
	tbl.Set("four",'4');
	tbl.Set("five",'5');
	tbl.Set("six",'6');
	tbl.Set("seven",'7');
	tbl.Set("eight",'8');
	tbl.Set("nine",'9');
	tbl.Set("A",'A');
	tbl.Set("B",'B');
	tbl.Set("C",'C');
	tbl.Set("D",'D');
	tbl.Set("E",'E');
	tbl.Set("F",'F');
	tbl.Set("G",'G');
	tbl.Set("H",'H');
	tbl.Set("I",'I');
	tbl.Set("J",'J');
	tbl.Set("K",'K');
	tbl.Set("L",'L');
	tbl.Set("M",'M');
	tbl.Set("N",'N');
	tbl.Set("O",'O');
	tbl.Set("P",'P');
	tbl.Set("Q",'Q');
	tbl.Set("R",'R');
	tbl.Set("S",'S');
	tbl.Set("T",'T');
	tbl.Set("U",'U');
	tbl.Set("V",'V');
	tbl.Set("W",'W');
	tbl.Set("X",'X');
	tbl.Set("Y",'Y');
	tbl.Set("Z",'Z');
	tbl.Set("a",'a');
	tbl.Set("b",'b');
	tbl.Set("c",'c');
	tbl.Set("d",'d');
	tbl.Set("e",'e');
	tbl.Set("f",'f');
	tbl.Set("g",'g');
	tbl.Set("h",'h');
	tbl.Set("i",'i');
	tbl.Set("j",'j');
	tbl.Set("k",'k');
	tbl.Set("l",'l');
	tbl.Set("m",'m');
	tbl.Set("n",'n');
	tbl.Set("o",'o');
	tbl.Set("p",'p');
	tbl.Set("q",'q');
	tbl.Set("r",'r');
	tbl.Set("s",'s');
	tbl.Set("t",'t');
	tbl.Set("u",'u');
	tbl.Set("v",'v');
	tbl.Set("w",'w');
	tbl.Set("x",'x');
	tbl.Set("y",'y');
	tbl.Set("z",'z');

	for (const auto & key : tbl.keys())
	{
		std::cout << key << ": " << static_cast<char>(tbl.Get(key)) << std::endl;
	}
	return EXIT_SUCCESS;
}
