#include <iostream>

using namespace std;

template<class K>
struct BSTNode
{
	BSTNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{ }

	BSTNode<K>* _left;
	BSTNode<K>* _right;
	K _key;
};

template<class K>
class BST
{
public:
	using Node = BSTNode<K>;

	bool insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}	

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//相等就不能插入
				return false;
			}
		}

		cur = new Node(key);
		if (key > parent->_key) parent->_right = cur;
		else parent->_left = cur;
		return true;
	}

	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key) cur = cur->_left;
			else if (key < cur->_key) cur = cur->_right;
			else return true;
		}

		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:

	void _InOrder(Node* root)
	{
		if (root == nullptr) return;
		
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	BSTNode<K>* _root = nullptr;
};

int main()
{
	BST<int> t;
	int a[] = { 1,6,8,5,7,0,4,2 };
	for (auto e : a)
	{
		t.insert(e);
	}

	t.InOrder();

	return 0;
}