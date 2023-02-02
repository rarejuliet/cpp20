#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
namespace containers {
	inline unsigned long hash_function(char* str) {
		unsigned long i = 0;
		for (int j = 0; str[j]; j++)
			i += str[j];
		return i % Capacity;
	}
	/// <summary>
	/// 
	/// </summary>
	template <typename Key, typename Val>
	class HashTable {
	uint64_t Capacities[] = { 
		13, //minimum size for our HashTable
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
	public:
		struct HashItem<Key, Val> {
			public:
				HashItem(Key k, Val v) : key(k), val(v) {}
			protected:
				Key key;
				Val val;
			};
		const uint64_t DefaultValue = 0;
		const uint64_t DefaultSize = 0;
			HashTable() : items(DefaultValue), size(DefaultSize) {}
			HashItem Get(Key k) { return items[k]; }
			bool Exists(Key k) { return false; }
			
	private:
		uint64_t size;
		std::vector<HashItem<Key, Val>> items;
	};
}
//template <typename Key, typename Val>
//class HashItem {
//public:
//	HashItem(Key k, Val v) : key(k), val(v) {}
//	Key key;
//	Val val;
//};
#endif //defined HASHTABLE_H