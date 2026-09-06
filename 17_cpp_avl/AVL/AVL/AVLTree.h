#include <iostream>
#include <assert.h>

using namespace std;


template<class K,class V> 
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;

	AVLTreeNode(const pair<K,V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{ }
};

template<class K,class V>
class AVLNode
{
public:
	using Node = AVLTreeNode<K, V>;

	bool Insert(const pair<K,V>& kv)
	{
		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur == nullptr)
			{
				cur = new Node(kv);
				_root = cur;
			}
			else
			{
				if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if(kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
		}

		cur = new Node(kv);

		if (cur->_kv.first > parent->_kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent)
		{
			if (parent->_left == cur) parent->_bf--;
			else parent->_bf++;


			if (parent->_bf == 0)
			{
				break;
			}
			else if(parent->_bf == -1 || parent->_bf == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if(parent->_bf == -2 || parent->_bf == 2)
			{
				//旋转
				
			}
			else
			{
				assert(false);
			}
		}
		

	}

	
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void RotateL(Node* RNode)
	{
		Node* RNodeR = RNode->_right;
		Node* RNodeRL = RNodeR->_left;

		RNode->_right = RNodeRL;
		if (RNodeRL) RNodeRL->_parent = RNode;

		Node* RNodeP = RNode->_parent;

		RNodeR->_left = RNode;
		RNode->_left = RNodeR;

		if (RNodeP == nullptr)
		{
			_root = RNodeR;
			RNodeR->_parent = nullptr;
		}
		else
		{
			if (RNodeP->_left == RNode) RNode->_left = RNodeR;
			else RNode->_right = RNodeR;
		}

		RNode->_bf = RNodeR->_bf = 0;

	}

	void RotateR(Node* RNode)
	{
		Node* RNodeL = RNode->_left;
		Node* RNodeLR = RNodeR->_right;

		RNode->_left = RNodeLR;
		if (RNodeLR) RNodeLR->_parent = RNode;

		Node* RNodeP = RNode->_parent;

		RNodeL->_right = RNode;
		RNode->_parent = RNodeL;

		if (RNodeP == nullptr)
		{
			_root = RNodeL;
			_root->_parent = nullptr;
		}
		else
		{
			if (RNodeP->_left == RNode) RNode->_left = RNodeL;
			else RNodeP->_right = RNodeL;
		}

		RNode->_bf = RNodeL->_bf = 0;
	}

	void RotateLR()
	{

	}

	void RotateRL()
	{

	}

private:

	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
			return;

		InOrder(_root->_left);
		cout << _root->_kv.first << ":" << _root->_kv.second << endl;
		InOrder(_root->_right);
	}

	Node* _root = nullptr;
};

