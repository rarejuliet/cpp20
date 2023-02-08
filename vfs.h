#ifndef VFS_H
#define VFS_H
#include <string>
#include <vector>
int vfs_test(int argc, char* argv[], char* env[]);
namespace fs = std::filesystem;

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
		explicit vfs(fs::path root = fs::path(default_directory)): root(root) {
			fs::current_path(fs::path(root));
		}

		/**
		 * \brief Change the current directory.
		 * \param directory A path to a directory to change to.
		 * \return true on success, else false
		 */
		inline virtual bool chdir(const std::string& directory) {
			fs::current_path(directory);
			if(fs::current_path()==directory)
				return true;
			else
				return false;
		};
		/**
		 * \brief open a directory.
		 * \param filename a path to a directory to open
		 * \return true on success, else false.
		 */
		virtual bool opendir(const std::string& filename = default_directory) = 0;
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
		 * \brief Create a new directory.
		 * \param directory_name Path containing the name of the folder
		 * you wish to create.
		 * \return true on success, else false
		 */
		virtual bool mkdir(const std::string& directory_name) = 0;
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
		bool unlink(const std::string& directory);

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
	explicit real_fs(std::string root) : vfs(root) {}

		/**
		 * \brief open a directory.
		 * \param filename a path to a directory to open
		 * \return true on success, else false.
		 */
		bool opendir(const std::string& filename) override {
			fs::current_path(filename);
			entry = fs::directory_entry(fs::path(filename));
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
		 * \param directory_name Path containing the name of the folder
		 * you wish to create.
		 * \return true on success, else false
		 */
		virtual bool mkdir(const std::string& directory_name) override{
			fs::create_directory(directory_name);
			entry = fs::directory_entry(directory_name);
			return entry.exists();
		}

		/**
		 * \brief Unlink(), or delete a directory or file.
		 * \param directory A path to a file or directory.
		 * \return true on success, else false
		 */
		virtual bool unlink(const std::string& directory) {
			return fs::remove(directory);
		}
		fs::directory_entry entry;
	};
#endif
