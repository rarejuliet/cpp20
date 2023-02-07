#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <array>
#include <map>
#include <string>
//constexpr uint64_t MAX_CAPACITY {87};
int ht_main(int argc, char* argv[], char* env[]);
namespace containers {
	template <typename Val>
	class Hashtable : public std::map<std::string,Val> {
		
		/**
		 * \brief  We don't want to spend too much time resizing our
		 * underlying container every time we add something, so we'll
		 * do it in steps.
		 *	This number list is taken from the fibonacci sequence, and
		 *	should be a good starting point for relative primality.
		 *	Also, we approximately double the size of the collection at
		 *	each resize so as not to waste time doing it too often.
		 */

//	constexpr uint64_t Capacity = Capacities[0];
	/**
	 * \brief Our hash function.  This is the reason the key is specialized to
	 * std::string, because our hash function only accepts std::string(s).
	 * \param str A std::string
	 * \return An integer representation of str, after hashing and doing modulo
	 * Capacities[size_] to ensure we're within bounds of the current array.
	 */
	static inline uint64_t hash_str(const std::string& str) {
	uint64_t i = 0;
	for (uint64_t j = 0; str[j]; j++)
		i += str[j];
	return i;
}
public:
		/**
		 * \brief Constructor.  Made explicit due to conversion from int being
		 * such a common occurrence that it might happen accidentally.
		 * \param start_size Zero based index to a size array.  For example,
		 * size 0 is 13, size 1 is 21, etc.  (Yes, it's the fibonacci sequence
		 * again!)
		 */
		explicit Hashtable() = default;
		Val get(std::string key) {
			return items[key];
		}
		Val operator[](const std::string& key) {
			return items[key];
		}
		bool exists(const std::string& key) const {
			return items.at(key);
		}
		size_t size() {
			return items.size();
		}
		size_t capacity() {
			return items.max_size();
		}
		void set(std::string key, Val value) {
			items[key] = value;
		}
		std::map<std::string,Val> items;
	}; // class Hashtable
}

#endif //defined HASHTABLE_H