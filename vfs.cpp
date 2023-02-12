#include <filesystem>
#include "vfs.h"

#include <iostream>

#include "exceptions.h"
//namespace fs = std::filesystem;


//bool vfs::chdir(const std::string& directory) {
//	throw NotImplementedException{"This function (chdir) hasn't been implemented yet."};
//}
namespace vfs {
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
		fs::path tmp = fs::temp_directory_path();
		fs::path src = tmp / "source";
		fs::path tst = src / "testdir_from_vfs";

		auto vfs = std::make_unique<real_fs>(tmp);
		if(vfs->mkdir(src))
		{
			std::cout << "mkdir() was successful." << std::endl;
		}
		if(vfs->mkdir(tst)) {
			std::cout << "mkdir() was successful." << std::endl;
		}
		vfs->chdir(fs::temp_directory_path());
		if(vfs->unlink(src)) {
			std::cerr << "unlink(" << src << ") was successful." << std::endl;
		} else {
			std::cerr << "unlink(" << src << ") was NOT successful." << std::endl;
		}

		auto dirs = vfs->readdir_recurse();
		for (const auto & dir : dirs)
		{
			std::cout << dir << std::endl;
		}
		return EXIT_SUCCESS;
	}
}