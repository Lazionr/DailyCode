#pragma once
#include <iostream>

using namespace std;

enum Color
{
	RED,
	BLACK
};


template<class T>
struct RBTreeNode
{
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Color _color;

	RBTreeNode(const T& data)
		:_kv(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}

};

template<class T, class Ref,class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	RBTreeIterator(Node* node)
		:_node(node)
	{}


	Node* _node;

	Self& operator++()
	{
		if (_node->_right)
		{
			Node* RightMin = _node->_right;
			while (Right && RightMin->_left)
			{
				RightMin = RightMin->_left;
			}
			_node = RightMin;
		}
		else
		{
			// 找 孩子是父亲左 的祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent->right = cur)
			{
				cur = patent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{
		if (_node == nullptr)
		{

		}
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator == (const Self& s)
	{
		return _node != s._node;
	}

	bool operator != (const Self& s)
	{
		return _node != s._node;
	}

};


template<class K,class T,class KeyOfT>
class RBTree
{
public:
	using Node = RBTreeNode<T>;

	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator Begin()
	{
		//最左节点
		Node* cur = _root;

		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return Iterator(cur);
	}

	Iterator End()
	{
		//最右节点的后一个，即 nullptr

		return Iterator(nullptr);
	}

	ConstIterator Begin() const
	{
		//最左节点
		Node* cur = _root;

		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return Iterator(cur);
	}

	ConstIterator End() const
	{
		return Iterator(nullptr);
	}

	RBTree() = default;

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}


	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			return true;
		}

		KeyOfT kot;
		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (kot(data) > kot(_root->data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(kot(data) < kot(_root->data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		cur->_color = RED;

		//指向+链接父亲
		if (kot(data) > kot(parent->_data))
		{
			parent->_right = cur;
		}
		else 
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//父亲出现连续红色节点
		while (parent && parent->_color == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				//     g
				//   p   u
				// c
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = parent->_parent;
				}
				else
				{
					//此时就是 uncle 不存在或者 存在且为黑
					//旋转+变色
					if (parent->_left == cur)
					{
						//     g
						//   p   u
						// c
						RotateR(grandfather);
						parent->_color = BLACK;
						grandfather->_color = RED;
					}
					else
					{
						//     g
						//   p   u
						//    c

						RotateL(parent);
						RotateR(grandfather);

						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}
			}
			else
			{
				//     g
				//   u   p
				//         c
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_color == RED)
				{	
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//此时就是 uncle 不存在或者 存在且为黑
					//     g
					//   u   p
					//         c
					if (parent->_right == cur)
					{
						RotateL(grandfather);

						grandfather->_color = RED;
						parent->_color = BLACK;
					}
					else
					{
						//     g
						//   u   p
						//     c
						RotateR(parent);
						RotateL(grandfather);

						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}

			}

		}

		_root->_color = BLACK;

		return true;
	}

	void RotateL(Node* RNode)
	{
		Node* RNodeR = RNode->_right;
		Node* RNodeRL = RNodeR->_left;

		RNode->_right = RNodeRL;
		if (RNodeRL) RNodeRL->_parent = RNode;

		Node* RNodeP = RNode->_parent;

		RNodeR->_left = RNode;
		RNode->_parent = RNodeR;

		if (RNodeP == nullptr)
		{
			_root = RNodeR;
			RNodeR->_parent = nullptr;
		}
		else
		{
			if (RNodeP->_left == RNode) RNodeP->_left = RNodeR;
			else RNodeP->_right = RNodeR;

			RNodeR->_parent = RNodeP;
		}

	}

	void RotateR(Node* RNode)
	{
		Node* RNodeL = RNode->_left;
		Node* RNodeLR = RNodeL->_right;

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
			if (RNodeP->_left == RNode) RNodeP->_left = RNodeL;
			else RNodeP->_right = RNodeL;

			RNodeL->_parent = RNodeP;
		}

	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int Height()
	{
		return _Height(_root);
	}

	int Size()
	{
		return _Size(_root);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

private:

	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
			return;

		_InOrder(_root->_left);
		cout << _root->_kv.first << ":" << _root->_kv.second << endl;
		_InOrder(_root->_right);
	}


	int _Height(Node* _root)
	{
		if (_root == nullptr) return 0;

		return max(_Height(_root->_left), _Height(_root->_right)) + 1;
	}


	int _Size(Node* _root)
	{
		if (_root == nullptr) return 0;

		return _Size(_root->_left) + _Size(_root->_right) + 1;
	}

	bool Check(Node* _root,int hb,const int refnum)
	{
		if (_root == nullptr)
		{
			if (hb != refnum)
			{
				cout << "存在黑色结点的数量不相等的路径" << endl;
				return false;
			}
			return true;
		}

		if (_root->_color == RED && _root->_parent->_color == RED)
		{
			cout << "存在连续的红色结点" << endl;
			return false;
		}

		if (_root->_color == BLACK) ++hb;

		return Check(_root->_left, hb, refnum) &&
			Check(_root->_right, hb, refnum);

	}

	bool _IsBalance(Node* _root)
	{
		if (_root == nullptr) return true;

		int refnum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_color == BLACK)
			{
				++refnum;
			}
		}

		return Check(_root, 0, refnum);
	}

	void Destroy(Node* _root)
	{
		if (_root == nullptr) return;

		Destroy(_root->_left);
		Destroy(_root->_right);

		delete _root;
	}

private:
	Node* _root = nullptr;
};