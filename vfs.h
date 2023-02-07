#ifndef VFS_H
#define VFS_H
#include <string>
#include <vector>

namespace vfs {
	class vfs {
	private:
		constexpr static std::string default_directory {R"(C:\Users\Adam)"};
		std::string current_directory {default_directory};
	public:
		/**
		 * \brief Create a virtual filesystem object, rooted to root.
		 * \param root The real path for this vfs (this will become the root directory
		 * for this filesystem.)
		 */
		explicit vfs(std::string root);
		/**
		 * \brief Change the current directory.
		 * \param directory A path to a directory to change to.
		 * \return true on success, else false
		 */
		virtual bool chdir(const std::string& directory) = 0;
		virtual bool opendir(const std::string& filename = default_directory) = 0;
		virtual bool closedir() = 0;
		virtual std::vector<std::string> readdir() = 0;
		virtual bool mkdir(const std::string& directory_name) = 0;
		virtual bool mount() = 0;
		virtual bool unmount() = 0;
		bool unlink(const std::string& directory);

		/**
		 * \brief Get the current working directory.
		 * \return The current working directory as a std::string
		 */
		virtual std::string cwd() {
			return current_directory;
		}
	};
	class realfs : vfs {
		
	};
	}
#endif
