typedef int K;
typedef string V;

const int CAP = 10;
class HashTable {
	//data memebers
	list<pair<K, V>> table[CAP];
	
	//private helper method
	K hashFunction(K key) {
		return key % CAP;
	}

public:
	HashTable() = default;

	bool Empty() {
		for (list<pair<K, V>> item : table) {
			if (!item.empty()) return false;
		}
		return true;
	}

	void add(K key, V value) {
		int index = hashFunction(key);
		list<pair<K, V>>::iterator ITR = table[index].begin();

		for (; ITR != table[index].end(); ITR++) {
			//if key already taken
			if (ITR->first == key) {
				cout << "[WARNING] Key exists. Value Replaced.\n";
				ITR->second = value;
				return;
			}
		}
		
		table[index].emplace_back(key, value);
	}

	void remove(K key) {
		int index = hashFunction(key);
		list<pair<K, V>>::iterator ITR = table[index].begin();
		for (; ITR != table[index].end(); ITR++) {
			//if key already taken
			if (ITR->first == key) {
				cout << "[INFO] Key exists. Removing Pair.\n";
				table[index].erase(ITR);
				return;
			}
		}
		cout << "[INFO] No value with the given key exists!\n";
	}

	pair<K, V>& Search(K key) {
		int index = hashFunction(key);
		list<pair<K, V>>::iterator ITR = table[index].begin();
		//searching through the list to find the (key, value)
		for (; ITR != table[index].end(); ITR++) {
			//if key already taken
			if (ITR->first == key) {
				return *ITR;
			}
		}
		cout << "[INFO] No value with the given key exists!\n";
	}

	void display() {
		for (list<pair<K,V>> lst : this->table) {
			if (!lst.empty()) {
				for (pair<K,V> item : lst) {
					cout << "Key: " << item.first << " Value: " << item.second << endl;
				}
			}
		}
	}

	V& operator[](K key) {
		return Search(key).second;
	}


};
