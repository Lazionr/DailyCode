#pragma once
#include <vector>


enum State
{
	EXIST,
	EMPTY,
	DELETE
};

template<class K,class V>
struct HashData
{
	std::pair<K, V> _kv;
	State _state = EMPTY; 

};

template<class K, class V>
class HashTable
{
public:
	HashTable()
		:_tables(11)
		, _n(0)
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (Find(kv.first)) return false;

		//负载因子 >= 0.7
		if (_n * 10 / _tables.size() >= 7)
		{
			//扩容
			HashTable<K,V> newht;
			newht._tables.resize(_tables.size() * 2);

			for (auto& e : _tables)
			{
				if(e._state == EXIST) newht.Insert(e._kv);
			}
			
			_tables.swap(newht._tables);
		}
		
		size_t hash0 = kv.first % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state == EXIST)
		{
			hashi = (hash0 + i) % _tables.size();
			++i;
		}

		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_n;

		return true;
	}

	HashData<K, V>* Find(const K& key)
	{
		size_t hash0 = key % _tables.size();
		size_t hashi = hash0;
		size_t i = 0;

		while (_tables[hashi]._state != EMPTY)
		{
			//由于循环条件是非空，可能是删除或存在，因此判断是必须存在且相等
			if (_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key)
			{
				return &_tables[hashi];
			}

			hashi = (hash0 + i) % _tables.size();
			++i;
		}

		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);

		if (ret == nullptr)
		{
			return false;
		}
		else
		{
			ret->_state = DELETE;
			return true;
		}

	}

private:
	std::vector<HashData<K, V>> _tables;
	size_t _n;
};


