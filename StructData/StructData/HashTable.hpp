namespace HASH_CLOSE
{
	//#pragma once
	//
	//enum State
	//{
	//	EMPTY,
	//	EXIST,
	//	DELETE,
	//};
	//
	//template<class K>
	//class HashTable
	//{
	//public:
	//	HashTable(size_t capacity)
	//		:_capacity(capacity)
	//		,_size(0)
	//	{
	//		_tables = new K[_capacity];
	//		_states = new State[_capacity];
	//
	//		memset(_tables, K(), sizeof(K)*_capacity);
	//		memset(_states, EMPTY, sizeof(State)*_capacity);
	//	}
	//
	//	~HashTable()
	//	{
	//		delete[] _states;
	//		delete[] _tables;
	//	}
	//
	//public:
	//	bool Insert(const K& key)
	//	{
	//		if (_size == _capacity)
	//		{
	//			cout<<"HashTable Is Full"<<endl;
	//			return false;
	//		}
	//
	//		size_t pos = HashFunc1(key);
	//		while (_states[pos] == EXIST)
	//		{
	//			if (_tables[pos] == key)
	//			{
	//				return false;
	//			}
	//
	//			pos++;
	//			if(pos == _capacity)
	//			{
	//				pos = 0;
	//			}
	//		}
	//
	//		_tables[pos] = key;
	//		_states[pos] = EXIST;
	//		++_size;
	//		return true;
	//	}
	//
	//	bool Remove(const K& key)
	//	{
	//		if (_size == 0)
	//		{
	//			cout<<"HashTable Is Empty"<<endl;
	//			return false;
	//		}
	//
	//		size_t pos = HashFunc1(key);
	//		while (_states[pos] != EMPTY)
	//		{
	//			if (_states[pos] != DELETE && _tables[pos] == key)
	//			{
	//				--_size;
	//				_states[pos] = DELETE;
	//				return true;
	//			}
	//			++pos;
	//			if (pos == _capacity)
	//			{
	//				pos = 0;
	//			}
	//		}
	//
	//		return false;
	//	}
	//
	//	int Find(const K& key)
	//	{
	//		if (_size == 0)
	//		{
	//			cout<<"HashTable Is Empty"<<endl;
	//			return false;
	//		}
	//
	//		size_t pos = HashFunc1(key);
	//		while (_states[pos] != EMPTY)
	//		{
	//			if (_tables[pos] == key && _states[pos] == EXIST)
	//			{
	//				return pos;
	//			}
	//
	//			++pos;
	//			if (pos == _capacity)
	//			{
	//				pos = 0;
	//			}
	//		}
	//		
	//		return -1;
	//	}
	//
	//	// 一次探测
	//	size_t HashFunc1(const K& key)
	//	{
	//		return key % _capacity;
	//	}
	//
	//	// 二次探测
	//	size_t HashFunc2(const K& key, int i)
	//	{
	//		int key % _capacity;
	//	}
	//
	//	void Print()
	//	{
	//		for (int i = 0; i < _capacity; ++i)
	//		{
	//			printf("【K:%d, S:%d】 ", _tables[i], _states[i]);
	//		}
	//		printf("\n");
	//	}
	//
	//private:
	//	K* _tables;
	//	State* _states;
	//	size_t _capacity;
	//	size_t _size;
	//};
	//
	////template<class T>
	////void f(const T* ptr)
	////{
	////	ptr->~T(); //~int()
	////}
	//
	//void Test1()
	//{
	//	HashTable<int> ht1(10);
	//	ht1.Insert(89);
	//	ht1.Insert(18);
	//	ht1.Insert(49);
	//	ht1.Insert(58);
	//	ht1.Insert(9);
	//
	//	ht1.Print();
	//
	//	ht1.Remove(89);
	//	ht1.Remove(9);
	//	ht1.Print();
	//
	//	int pos = ht1.Find(18);
	//	pos = ht1.Find(9);
	//	pos = ht1.Find(14);
	//}


	#pragma once

	enum State
	{
		EMPTY,
		EXIST,
		DELETE,
	};

	template<class K>
	class HashTable
	{
	public:
		HashTable(size_t capacity)
			:_capacity(capacity)
			,_size(0)
		{
			_tables = new K[_capacity];
			_states = new State[_capacity];

			memset(_tables, K(), sizeof(K)*_capacity);
			memset(_states, EMPTY, sizeof(State)*_capacity);
		}

		~HashTable()
		{
			delete[] _states;
			delete[] _tables;
		}

	public:
		bool Insert(const K& key)
		{
			if ((float)_size/(float)_capacity > 0.8)
			{
				//_CheckCapacity();
			}

			if (_size == _capacity)
			{
				cout<<"HashTable Is Full"<<endl;
				return false;
			}

			size_t pos = HashFunc1(key);
			int i = 1;
			while (_states[pos] == EXIST)
			{
				if (_tables[pos] == key)
				{
					return false;
				}
				pos = HashFunc2(pos, i++);
			}

			_tables[pos] = key;
			_states[pos] = EXIST;
			++_size;
			return true;
		}

		bool Remove(const K& key)
		{
			if (_size == 0)
			{
				cout<<"HashTable Is Empty"<<endl;
				return false;
			}

			size_t pos = HashFunc1(key);
			while (_states[pos] != EMPTY)
			{
				if (_states[pos] != DELETE && _tables[pos] == key)
				{
					--_size;
					_states[pos] = DELETE;
					return true;
				}
				++pos;
				if (pos == _capacity)
				{
					pos = 0;
				}
			}

			return false;
		}

		int Find(const K& key)
		{
			if (_size == 0)
			{
				cout<<"HashTable Is Empty"<<endl;
				return false;
			}

			size_t pos = HashFunc1(key);
			while (_states[pos] != EMPTY)
			{
				if (_tables[pos] == key && _states[pos] == EXIST)
				{
					return pos;
				}

				++pos;
				if (pos == _capacity)
				{
					pos = 0;
				}
			}

			return -1;
		}

		// 一次探测
		size_t HashFunc1(const K& key)
		{
			return key % _capacity;
		}

		// 二次探测
		size_t HashFunc2(size_t lastHash, int i)
		{
			return (lastHash+2*i-1)%_capacity;
		}

		void Print()
		{
			for (int i = 0; i < _capacity; ++i)
			{
				printf("【K:%d, S:%d】 ", _tables[i], _states[i]);
			}
			printf("\n");
		}

	private:
		K* _tables;
		State* _states;
		size_t _capacity;
		size_t _size;
	};

	//template<class T>
	//void f(const T* ptr)
	//{
	//	ptr->~T(); //~int()
	//}

	void TestHashTable()
	{
		HashTable<int> ht1(10);
		ht1.Insert(89);
		ht1.Insert(18);
		ht1.Insert(49);
		ht1.Insert(58);
		ht1.Insert(9);

		ht1.Print();

		//ht1.Remove(89);
		//ht1.Remove(9);
		//ht1.Print();

		//int pos = ht1.Find(18);
		//pos = ht1.Find(9);
		//pos = ht1.Find(14);
	}
}