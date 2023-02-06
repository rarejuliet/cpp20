#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <algorithm>
#include <string>
#include <sstream>
namespace util {
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
	std::string commify(const auto& value)
	{
	    std::stringstream ss;
	    ss.imbue(std::locale("en_US.UTF8"));
	    ss << std::fixed << value;
	    return ss.str();
	}
}
#endif