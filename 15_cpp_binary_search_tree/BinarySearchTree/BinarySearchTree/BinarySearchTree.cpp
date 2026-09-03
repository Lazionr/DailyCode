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

	BST() = default;

	BST(const BST& val)
	{
		Node* cur = 
		while()
	}

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
		cout << endl;
	}

	bool erase(const K& key)
	{
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
				//右孩子为空
				if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur) parent->_left = cur->_left;
						else parent->_right = cur->_left;
					}
				
					delete cur;
					return true;
				}
				else if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur) parent->_left = cur->_right;
						else parent->_right = cur->_right;
					}

					delete cur;
					return true;
				}
				else //两个孩子均不为空
				{
					//找到右子树的最左节点
					Node* RightMinP = cur;
					Node* RightMin = cur->_right;

					while (RightMin->_left)
					{
						RightMinP = RightMin;
						RightMin = RightMin->_left;
					}

					cur->_key = RightMin->_key;

					if(RightMinP->_left == RightMin) RightMinP->_left = RightMin->_right;
					else  RightMinP->_right = RightMin->_right;
					
					delete RightMin;
					return true;
				}
			}
		}

		return false;
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
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.insert(e);
	}

	t.InOrder();

	t.erase(8);
	t.InOrder();



	return 0;
}