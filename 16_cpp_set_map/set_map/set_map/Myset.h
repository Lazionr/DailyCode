#pragma once
#include "RBTree.h"

namespace stl
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::ConstIterator const_iterator;

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
		RBTree<K, const K, SetKeyOfT> _t;

	};


}