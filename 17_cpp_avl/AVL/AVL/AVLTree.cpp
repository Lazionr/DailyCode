#include <iostream>

using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	pair<K,V> _kv;
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;

	AVLTreeNode(const pair<K,V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}

};


template<class K, class V>
class AVLTree
{
public:
	using Node = AVLTreeNode<K, V>;

	bool Insert(const pair<K,V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		//找到合适位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		return true;
	}

	bool Find(const K& key)
	{
		if (_root == nullptr) return false;

		//找到合适位置
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_kv.first) cur = cur->_right;
			else if (key < cur->_kv.first) cur = cur->_left;
			else return true;
		}
		return false;
	}

	bool Erase(const K& key)
	{
		if (_root == nullptr) return false;

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				if (cur->_right == nullptr)
				{
					Node* child = cur->_left;

					if (parent == nullptr) _root = cur->_left;
					else
					{
						if (key > parent->_kv.first) parent->_right = cur->_left;
						else parent->_left = cur->_left;
					}

					if (child) child->_parent = parent;

					delete cur;
					return true;
				}
				else if (cur->_left == nullptr)
				{
					Node* child = cur->_right;

					if (parent == nullptr) _root = cur->_right;
					else
					{
						if (key > parent->_kv.first) parent->_right = cur->_right;
						else parent->_left = cur->_right;
					}

					if (child) child->_parent = parent;

					delete cur;
					return true;
				}
				else
				{
					Node* RightMin = cur->_right;
					//RightMinP如果初始化为nullptr，如果RightMin没有左孩子，循环不会进行
					//赋值之后直接 RightMinP-> 导致空指针访问
					Node* RightMinP = cur;

					//找右子树的最左节点
					while (RightMin->_left)
					{
						RightMinP = RightMin;
						RightMin = RightMin->_left;
					}

					cur->_kv = RightMin->_kv;

					//删除替代节点前判断与父节点的链接关系
					//RightMin的左孩子为空，右孩子可能为空
					Node* child = RightMin->_right;

					if (RightMinP->_left == RightMin) RightMinP->_left = RightMin->_right;
					else RightMinP->_right = RightMin->_right;

					if (child) child->_parent = RightMinP;

					delete RightMin;
					return true;
				}
			}
		}
		return false;
	}

private:
	Node* _root = nullptr;
};


void test_insert()
{
	AVLTree<string, int> dict;

	dict.Insert(make_pair("sort", 1));
	dict.Insert(make_pair("string", 1));

	cout << dict.Find("sort") << endl;
	cout << dict.Find("vector") << endl;

}



int main()
{
	test_insert();
	return 0;
}