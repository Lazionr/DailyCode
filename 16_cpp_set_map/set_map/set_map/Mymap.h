#pragma once
#include "RBTree.h"

namespace stl
{
	template<class K,class V>
	class map
	{
	public:
		struct MapKeyOfT()
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<const K,V>, MapKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K,V>, MapKeyOfT>::ConstIterator const_iterator;

		iterator begin()
		{
			_t.Begin();
		}

		iterator end()
		{
			_t.End();
		}

		const_iterator begin() const
		{
			_t.Begin();
		}

		const_iterator end() const
		{
			_t.End();
		}


	private:
		RBTree<K, pair<const K,V>, MapKeyOfT> _t;
	};
}