#ifndef VFS_H
#define VFS_H
#include <cassert>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

/**
    @namespace vfs
    @brief     Contains all classes and functions making up the virtual filesystem.
**/
namespace vfs {
int vfs_test(int argc, char* argv[], char* env[]);
	/**
	 * \brief Base class for all virtual filesystem components.
	 */
	class vfs {
	private:
		constexpr static std::string default_directory {R"(C:\Users\Adam)"};
		std::string current_directory {default_directory};
		fs::path root;

	public:
		/**
		 * \brief Create a virtual filesystem object, rooted to root.
		 * \param root The real path for this vfs (this will become the root directory
		 * for this filesystem.)
		 */
		inline explicit vfs(fs::path root = fs::path(default_directory)): root(root) {
			fs::current_path(fs::path(root));
		}

		/**
		 * \brief Change the current directory.
		 * \param directory A path to a directory to change to.
		 * \return true on success, else false
		 */
		inline virtual void chdir(const fs::path& directory) {
			fs::current_path(directory);
		};
		/**
		 * \brief open a directory.
		 * \param path a path to a directory to open
		 * \return true on success, else false.
		 */
		virtual bool opendir(const fs::path& path = default_directory) = 0;
		/**
		 * \brief Close a directory opened with opendir()
		 * \return true on success, else false
		 */
		virtual bool closedir() = 0;
		/**
		 * \brief read the contents of a directory into a std::vector<string>.
		 * \return a std::vector<string> containing the file and directory names.
		 */
		virtual std::vector<std::string> readdir() = 0;
		/**
		 * \brief Like readdir(), only this version recurses into all subdirectories.
		 * \return A vector of string containing all directory entries and sub-entries.
		 */
		virtual std::vector<std::string> readdir_recurse() = 0;
		/**
		 * \brief Create a new directory.
		 * \param path Path containing the name of the folder
		 * you wish to create.
		 * \return true on success, else false
		 */
		virtual bool mkdir(const fs::path& path) = 0;
		/**
		 * \brief Mount, or connect a filesystem to this one.
		 * \return true on success, else false
		 */
		virtual bool mount() = 0;
		/**
		 * \brief Unmount, or disconnect a filesystem from this one.
		 * \return true on success, else false
		 */
		virtual bool unmount() = 0;
		/**
		 * \brief Unlink(), or delete a directory or file.
		 * \param directory A path to a file or directory.
		 * \return true on success, else false
		 */
		virtual bool unlink(const fs::path& directory) = 0;

		/**
		 * \brief Get the current working directory.
		 * \return The current working directory as a std::string
		 */
		virtual std::filesystem::path cwd() {
			return fs::current_path();
		}

		/**
		 * \brief Destructor.  Virtual here by necessity.
		 */
		virtual ~vfs() = default;
	};

/**
 * \brief real_fs - An implementation of vfs using the real underlying filesystem.
 */
class real_fs : public vfs {
		public:
	/**
	 * \brief Constructor.
	 * \param root A path to startup at.
	 */
	explicit real_fs(fs::path root) : vfs(root) {}

		/**
		 * \brief open a directory.
		 * \param path a path to a directory to open
		 * \return true on success, else false.
		 */
		bool opendir(const fs::path& path) override {
			fs::current_path(path);
			entry = fs::directory_entry(fs::path(path));
			if(entry.exists())
				return true;
			else
				return false;
		}

		/**
		 * \brief Close a directory opened with opendir()
		 * \return true on success, else false
		 */
		bool closedir() override {
			return true;
		}

		/**
		 * \brief read the contents of a directory into a std::vector<string>.
		 * \return a std::vector<string> containing the file and directory names.
		 */
		std::vector<std::string> readdir() {
			auto dir_entries = std::vector<std::string>();
			for (const auto & entry_it : fs::directory_iterator(cwd()))
			{
				auto filename= entry_it.path().filename().string();
				dir_entries.push_back(std::move(filename));
			}
			return dir_entries;
		}

		/**
		 * \brief Like readdir(), only this version recurses into all subdirectories.
		 * \return A vector of string containing all directory entries and sub-entries.
		 */
		std::vector<std::string> readdir_recurse() {
			auto list = std::vector<std::string>{};
			for (const auto& it : fs::recursive_directory_iterator(cwd())) {
				auto filename = it.path().filename().string();
				list.push_back(filename);
			}
			return list;
		}

		/**
		 * \brief Mount, or connect a filesystem to this one.
		 * \return true on success, else false
		 */
		bool mount() override { return false; }
		/**
		 * \brief Unmount, or disconnect a filesystem from this one.
		 * \return true on success, else false
		 */
		bool unmount() override { return false; }
		/**
		 * \brief Destructor
		 */
		virtual ~real_fs() {}

		/**
		 * \brief Create a new directory.
		 * \param path Path containing the name of the folder
		 * you wish to create.
		 * \return true on success, else false
		 */
		inline virtual bool mkdir(const fs::path& path) override{
			bool success = fs::create_directory(path);
			entry = fs::directory_entry(path);
			return success;
		}

		/**
		 * \brief Unlink(), or delete a directory or file.
		 * \param path A path to a file or directory.
		 * \return true on success, else false
		 */
		virtual bool unlink(const fs::path& path) override {
			uintmax_t removed {0};
			try {
				if (path != fs::path(R"("C:\")")) {
					removed = fs::remove_all(path);
					return removed > 0;
				} else {
					return false;
				}
			} catch(std::exception& e) {
				std::cerr << "Caught an exception: " << typeid(e).name() << "\n" << typeid(e).raw_name() << std::endl;
				std::cerr << e.what() << "\n";
				return false;
			}
		}
		fs::directory_entry entry;
	};
}
#endif
