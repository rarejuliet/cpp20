#include "Hashtable.h"







int ht_main(int argc, char* argv[], char* env[]) {
	containers::Hashtable<std::string> tbl(0);
	tbl.Set("Adam","Choate");
	tbl.Set("Roberta","Choate");
	tbl.Get("Adam");
	tbl.Get("Roberta");
	return EXIT_SUCCESS;
}