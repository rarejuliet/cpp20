#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <algorithm>
#include <filesystem>
#include <string>
#include <sstream>
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
	constexpr  inline std::string commify(const auto& value)
	{
	    std::stringstream ss;
	    ss.imbue(std::locale(UTF8));
	    ss << std::fixed << value;
	    return ss.str();
	}
	 /**
	     @brief  Convert a value to its string representation.
	     @param  val - Some value to convert to a string.
	     @retval     - A std::string containing the string representation of val
	 **/
	constexpr inline std::string to_str(auto& val) {
		std::stringstream ss;
		ss.imbue(std::locale(UTF8));
		ss << val;
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
	inline std::string remove_trailing_backslash(std::filesystem::path path) {
		std::string s = path.string();
		auto p = s.substr(0,s.find_last_of("\\"));
		return p;
	}
}
#endif