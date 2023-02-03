#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
int ht_main(int argc, char* argv[], char* env[]);
namespace containers {
	/// <summary>
	/// 
	/// </summary>
	template <typename Val>
	class Hashtable {
	std::vector<uint64_t> Capacities = { //[24]
		13, //minimum size for our Hashtable
		29,
		63,
		127,
		233,
		467,
		1237,
		4095,
		8191,
		16357,
		32767,
		65537,
		150001,
		3276717,
		51276717,
		334276717,
		3274446717,
		32767145347,
		327675445417,
		3276765577517,
		32767149828837,
		327671223432457,
		3276717987586587,
		32767179084151611
	};
	uint64_t Capacity = Capacities[0]; 
	inline uint64_t hash_function(std::string str) const {
		uint64_t i = 0;
		for (uint64_t j = 0; str[j]; j++)
			i += str[j];
		return i % Capacities[size];
	}
	public:
		const uint64_t DefaultValue = 0;
		const uint64_t DefaultSize = 0;
		explicit Hashtable(uint64_t start_size) {
			size = Capacities[start_size];
			vals.reserve(Capacities[size]);
			keys.reserve(Capacities[size]);
		}
		Val Get(std::string key) {
			return vals[hash_function(key)];
		}
		bool Exists(std::string key) {
			keys[hash_function(key)] != nullptr;
		}
		void grow() {
			size++;
			vals.reserve(Capacities[size]);
		}

	void Set(std::string key, Val value) {
			keys[hash_function(key)] = value;
		}

private:
		uint64_t size;
		std::vector<Val> vals;
		std::vector<std::string> keys;
	};
}

#endif //defined HASHTABLE_H