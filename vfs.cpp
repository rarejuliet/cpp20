#include "vfs.h"

namespace vfs {
	struct NotImplementedException : public std::exception {};

	vfs::vfs(std::string root) {
		throw NotImplementedException{};
	}

	bool vfs::chdir(const std::string& directory) {
		throw NotImplementedException{};
	}

	bool vfs::closedir() {
		throw NotImplementedException{};
	}

	bool vfs::mkdir(const std::string& directory_name) {
		throw NotImplementedException{};
	}
	bool vfs::mount() {
		throw NotImplementedException{};
	}
	bool vfs::opendir(const std::string& filename) {
		throw NotImplementedException{};
	}
	std::vector<std::string> vfs::readdir() {
		throw NotImplementedException{};
	}
	bool vfs::unmount() {
		throw NotImplementedException{};
	}
	bool vfs::unlink(const std::string &directory) {
		throw NotImplementedException{};
	}


}