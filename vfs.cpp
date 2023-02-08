#include <filesystem>
#include "vfs.h"

#include <iostream>

#include "exceptions.h"
//namespace fs = std::filesystem;


//bool vfs::chdir(const std::string& directory) {
//	throw NotImplementedException{"This function (chdir) hasn't been implemented yet."};
//}

bool vfs::closedir() {
	throw NotImplementedException{"This function (chdir) hasn't been implemented yet."};
}

bool vfs::mkdir(const fs::path& path) {
	throw NotImplementedException{"This function (mkdir) hasn't been implemented yet."};
}
bool vfs::mount() {
	throw NotImplementedException{"This function (mount) hasn't been implemented yet."};
}
bool vfs::opendir(const fs::path& path) {
	throw NotImplementedException{"This function (opendir) hasn't been implemented yet."};
}
//std::vector<std::string> vfs::readdir() {
//	throw NotImplementedException{"This function (readdir) hasn't been implemented yet."};
//}
bool vfs::unmount() {
	throw NotImplementedException{"This function (unmount) hasn't been implemented yet."};
}
bool vfs::unlink(const fs::path &directory) {
	throw NotImplementedException{"This function (unlink) hasn't been implemented yet."};
}


int vfs_test(int argc, char* argv[], char* env[]) {
	auto vfs = std::make_unique<real_fs>(R"(C:\Users\Adam)");
	if(vfs->chdir("source"))
	{
		std::cout << "chdir() was successful." << std::endl;
	}
	if(vfs->mkdir("testdir_from_vfs"))
		std::cout << "mkdir() was successfull." << std::endl;
	auto dirs = vfs->readdir_recurse();
	for (const auto & dir : dirs)
	{
		std::cout << dir << std::endl;
	}
	return EXIT_SUCCESS;
}