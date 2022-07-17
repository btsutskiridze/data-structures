class HashTable {
	//data memebers
	int size;
	int CAP;	
	string* table;
	
	//private helper method
	unsigned long hashFunction(string key) {
		unsigned long j = 0;
		for (int i = 0; i < key.length(); i++) {
			j += key[i];
		}
		return j % CAP;
	}

public:
	HashTable(int load) :size(0), CAP(load) {
		table = new string[CAP];
	
	}
	bool empty() {
		return size == 0;
	}
	void insertItem(string value) {
		if (size >= 0.75 * CAP) {
			cout << "HashTable is full.Cannot insert\n";
			return;
		}

		unsigned long index = hashFunction(value);

		//"" - means there is and was nothing ever
		//" " - now there is nothing but before it was occupied
		//
		while (table[index] != value && table[index] != "" && table[index] != " ") {
			//linear probing
			index++;
			index %= CAP;
		}

		if (table[index] == "" || table[index] == " ")
		{
			table[index] = value;
			size++;
		}
	}

	string deleteItem(string value){
		unsigned long index = hashFunction(value);

		while (table[index] != "")
		{
			if (table[index] == value) {
				table[index] = " ";
				size--;
			}
			index++;
			index %= CAP;
		}



	}

	void display() {
		for (int i = 0; i < CAP; i++) {
			cout << i << " -> " << table[i] << endl;
		}
	}

	bool search(string value) {
		bool found = false;
		unsigned long index = hashFunction(value);

		while (table[index] != "") {
			if (table[index] == value) {
				found = true;
			}
			index++;
			index %= CAP;
		}

		return found;
	}

};
