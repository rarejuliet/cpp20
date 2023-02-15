#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <algorithm>
#include <filesystem>
#include <string>
#include <strstream>
namespace util {
	constexpr const char* UTF8 = "en_US.UTF8";
	 /**
	     @brief Set the current locale for cin, cout and cerr.
	     @param locale - A C string containing the name of the locale you wish to set the
	     stdin, stdout, and stderr (std::cin, std::cout, std::err) iostreams to.  Default
	     is UTF8.
	 **/
	inline auto set_locale(const char* locale = UTF8) {
		auto old = std::cout.imbue(std::locale(locale));
		std::cerr.imbue(std::locale(locale));
		std::cin.imbue(std::locale(locale));
		return old;
	}
	/**
	 * \brief Takes a string argument and creates a copy in uppercase.
	 * \param s A source string to convert to uppercase.  s is not
	 * modified.
	 * \return A copy of s converted to uppercase.
	 */
	constexpr std::string uppercase_copy(const std::string& s) {
		std::string uc{s};
		std::ranges::transform(s,uc.begin(), ::toupper);
		return uc;
	}

	/**
	 * \brief Convert a string to all uppercase.  After this function returns,
	 * s will have been modified so that all characters are uppercase.
	 * \param s A std::string to convert.
	 */
	constexpr inline void uppercase(std::string& s) {
		std::ranges::transform(s,s.begin(),::toupper);
	}
	/**
	 * \brief Takes a string argument and creates a copy in lowercase.
	 * \param s A source string to convert to lowercase.  s is not
	 * modified.
	 * \return A copy of s converted to lowercase.
	 */
	constexpr inline std::string lowercase_copy(const std::string& s) {
		std::string uc{s};
		std::ranges::transform(s,uc.begin(), ::tolower);
		return uc;
	}
	/**
	 * \brief Convert a string to all lowercase.  After this function returns,
	 * s will have been modified so that all characters are lowercase.
	 * \param s A std::string to convert.
	 */
	constexpr inline void lowercase(std::string& s) {
		std::ranges::transform(s,s.begin(),::tolower);
	}

	/**
	 * \brief 
	 * \param value A numeric value is expected.
	 * \return A new string with a comma-separated value.
	 */
	constexpr inline std::string commify(const auto& value)
	{
	    std::stringstream ss;
	    auto loc = ss.imbue(std::locale(UTF8)); //Save current locale.
	    ss << std::fixed << value;
		ss.imbue(loc);  // Set it back to its previous value
	    return ss.str();
	}
	 /**
	     @brief  Convert a value to its string representation.
	     @param  val - Some value to convert to a string.
	     @retval     - A std::string containing the string representation of val
	 **/
	constexpr inline std::string to_str(auto& val) {
		std::stringstream ss;
		auto loc = ss.imbue(std::locale(UTF8));
		ss << val;
		ss.imbue(loc);
		return ss.str();
	}
	 /**
	     @brief  This function converts a std::string to a const char*.  Many functions
	     require a const char* as an argument, so to minimize casting and cluttered code
	     this function is used.  Same effect as calling std::string::c_str on a string
	     object.
	     @param  s - A string to be converted to a const char*
	     @retval   - A const char* containing the contents of s.
	 **/
	constexpr inline const char* to_c_str(const std::string& s) {
		return s.c_str();
	}
/**
     @brief  Creates and returns a std::filesystem::path with any trailing char removed.
     @param  path - A std::filesystem::path to remove the trailing char from.
     @param  c	  - A char to remove from the end of path.
     @retval      - A copy of the string with the char removed.
 **/
	inline std::string remove_trailing(std::filesystem::path path, auto c) {
		std::string s = path.string();
		const uint64_t len = s.length();
		if(s.at(len-1)==c)
			s = s.substr(0,s.size()-1);
		return s;
	}
 /**
     @brief  Creates and returns a std::filesystem::path with any trailing backslash removed.
     @param  path - A std::filesystem::path to remove the trailing backslash from.
     @retval      - A copy of the string with the backslash removed.
 **/
	inline std::string remove_trailing_backslash(std::filesystem::path path) {
		return remove_trailing(path,'\\');
		uint64_t len = path.string().length();
		std::string s = path.string();

		if(s.at(len-1)=='\\')
			s = s.substr(0,s.size()-1);
		return s;
	}
 /**
     @brief  Creates and returns a std::filesystem::path with any trailing slash removed.
     @param  path - A std::filesystem::path to remove the trailing slash from.
     @retval      - A copy of the string with the slash removed.
 **/
	inline std::string remove_trailing_slash(std::filesystem::path path) {
		return remove_trailing(path,'/');
		uint64_t len = path.string().length();
		std::string s = path.string();

		if(s.at(len-1)=='/')
			s = s.substr(0,s.size()-1);
		return s;
	}
 /**
     @brief  Bite the newline off the end of a path.
     @param  path - A path.
     @retval      - A std::string with the last character removed (if it was a newline).
 **/
	inline std::string chomp(std::filesystem::path path) {
		return remove_trailing(path,'\n');
	}
 /**
     @brief  Remove the trailing character from a string.
     @param  path - A path to trim.
     @retval      - A string with the last character removed.
 **/
	inline std::string chop(std::filesystem::path path) {
		std::string s = path.string();
		uint64_t len = s.length();
		s = s.substr(0,s.size()-1);
		return s;
	}
}
#endif