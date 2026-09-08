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

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
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
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if(parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}

				break;
			}
			else
			{
				assert(false);
			}
			
		}
		return true;
	}

	bool Find(const pair<K,V>& kv)
	{
		Node* cur = _root;

		if (cur == nullptr) return false;

		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
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

		RNode->_bf = RNodeR->_bf = 0;

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

		RNode->_bf = RNodeL->_bf = 0;
	}

	void RotateLR(Node* RNode)
	{
		Node* RNodeL = RNode->_left;
		Node* RNodeLR = RNodeL->_right;
		int bf = RNodeLR->_bf;

		RotateL(RNodeL);
		RotateR(RNode);

		//更新平衡因子
		if (bf == 0)
		{
			RNode->_bf = 0;
			RNodeL->_bf = 0;
			RNodeLR->_bf = 0;
		}
		else if (bf == -1)
		{
			RNode->_bf = 1;
			RNodeLR->_bf = 0;
			RNodeL->_bf = 0;
		}
		else if (bf == 1)
		{
			RNode->_bf = 0;
			RNodeL->_bf = -1;
			RNodeLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* RNode)
	{
		Node* RNodeR = RNode->_right;
		Node* RNodeRL = RNodeR->_left;
		int bf = RNodeRL->_bf;

		RotateR(RNodeR);
		RotateL(RNode);

		if (bf == 0)
		{
			RNode->_bf = 0;
			RNodeR->_bf = 0;
			RNodeRL->_bf = 0;
		}
		else if (bf == -1)
		{
			RNode->_bf = 0;
			RNodeR->_bf = 1;
			RNodeRL->_bf = 0;
		}
		else if(bf == 1)
		{
			RNode->_bf = -1;
			RNodeR->_bf = 0;
			RNodeRL->_bf = 0;
		}
		else
		{
			assert(false);
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

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
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

	bool _IsBalanceTree(Node* _root)
	{
		if (_root == nullptr) return true;

		int left_height = _Height(_root->_left);
		int right_height = _Height(_root->_right);
		
		int diff = right_height - left_height;

		if (abs(diff) >= 2)
		{
			cout << _root->_kv.first << ":" << "高度差异常" << endl;
			return false;
		}
		
		if (_root->_bf != diff)
		{
			cout << _root->_kv.first << ":" << "平衡因子异常" << endl;
			return false;
		}

		return _IsBalanceTree(_root->_left) &&
			_IsBalanceTree(_root->_right);

	}


	Node* _root = nullptr;
};

