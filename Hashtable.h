#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <array>
#include <string>
constexpr uint64_t MAX_CAPACITY {87};
int ht_main(int argc, char* argv[], char* env[]);
namespace containers {
	/// <summary>
	/// 
	/// </summary>
	static uint64_t Capacities[MAX_CAPACITY] { //87
		 13
		,21
		,34
		,55
		,89
		,144
		,233
		,377
		,610
		,987
		,1597
		,2584
		,4181
		,6765
		,10946
		,17711
		,28657
		,46368
		,75025
		,121393
		,196418
		,317811
		,514229
		,832040
		,1346269
		,2178309
		,3524578
		,5702887
		,9227465
		,14930352
		,24157817
		,39088169
		,63245986
		,102334155
		,165580141
		,267914296
		,433494437
		,701408733
		,1134903170
		,1836311903
		,2971215073
		,4807526976
		,7778742049
		,12586269025
		,20365011074
		,32951280099
		,53316291173
		,86267571272
		,139583862445
		,225851433717
		,365435296162
		,591286729879
		,956722026041
		,1548008755920
		,2504730781961
		,4052739537881
		,6557470319842
		,10610209857723
		,17167680177565
		,27777890035288
		,44945570212853
		,72723460248141
		,117669030460994
		,190392490709135
		,308061521170129
		,498454011879264
		,806515533049393
		,1304969544928657
		,2111485077978050
		,3416454622906707
		,5527939700884757
		,8944394323791464
		,14472334024676221
		,23416728348467685
		,37889062373143906
		,61305790721611591
		,99194853094755497
		,160500643816367088
		,259695496911122585
		,420196140727489673
		,679891637638612258
		,1100087778366101931
		,1779979416004714189
		,2880067194370816120
		,4660046610375530309
		,7540113804746346429
		,12200160415121876738ull
	};
	template <typename Val>
	class Hashtable {
		
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

	explicit Hashtable(const uint64_t start_size = 0) {
		size_=start_size;
		vals_=new Val[Capacities[size_]];
		filled_=new bool[Capacities[size_]];
		for (uint64_t i=0; i<capacity(); ++i) {
			filled_[i]=false;
		}
	}
	Val Get(std::string key) {
		uint64_t n = hash_str(key);
		return vals_[n];
	}
	auto keys() {
		return keys_;
	}
	bool exists(const std::string& key) const {
		uint64_t hash = hash_str(key);
		return filled_[hash];
	}
	void grow() {
		size_++;
		Val *v = vals_;
		bool *oldfilled = filled_;
		filled_=new bool[Capacities[size_]];
		for (uint64_t i=0; i<Capacities[size_]; ++i)	{
			filled_[i]=false;
		}
		vals_ = new Val[Capacities[size_]];

		for (const auto & val : keys_) {
			uint64_t oldhash=hash_str(val)%Capacities[size_-1];
			uint64_t newhash=hash_str(val)%capacity();
			if(oldfilled[oldhash])
				filled_[newhash] = true;
			Val item = v[oldhash];
			vals_[newhash]=item;
		}
		delete[] v;
		v=nullptr;
	}
	size_t size() {
		[[maybe_unused]]uint64_t count = keys_.size();
		return num_items_;
	}

	size_t capacity() {
		return Capacities[size_];
	}

	void Set(std::string key, Val value) {
			uint64_t hash = hash_str(key) % capacity();
			if(filled_[hash] == false) // New item
			{
				num_items_++;
				vals_[hash] = value;
				keys_.push_back(key);
				filled_[hash] = true;
				if( (num_items_) > (capacity() / 3)) //We're a third full, so resize.
				{
					grow();
				}
			}
			else  // Overwrite existing value
			{
				uint64_t i=0;
				//Handle collisions
				while(filled_[hash+i])
				{
					if(!filled_[hash+i])
						filled_[hash+i]=true;
					vals_[hash+i] = value;
					++i;
				}
			}
		}
private:
		uint64_t size_{0};
		uint64_t num_items_{0};
		bool* filled_{nullptr};
		Val* vals_{nullptr};
		std::vector<std::string> keys_{};
	};
}

#endif //defined HASHTABLE_H