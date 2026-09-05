#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}

};


template<class K, class V>
class AVLTree
{
public:
	using Node = AVLTreeNode<K, V>;

	bool Insert(const pair<K, V>& kv)
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
		if (kv.first > parent->_kv.first) parent->_right = cur;
		else parent->_left = cur;

		cur->_parent = parent;
		

		//控制平衡因子
		while (parent)
		{
			if (cur == parent->_left) parent->_bf--;
			else parent->_bf++;

			if (parent->_bf == 0) break;
			else if (parent == -1 || parent == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{

				}
				else if()

			}
			else
			{
				assert(false);
			}
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

	void RotateR(Node* RNode)
	{
		Node* RNodeL = RNode->_left;
		Node* RNodeLR = RNodeL->_right;

		Node* RNodeP = RNode->_parent;
			
		//修改孩子和父亲
		RNode->_left = RNodeLR;
		if(RNodeLR) RNodeLR->_parent = RNode;

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
			else RNode->_right = RNodeL;

			RNodeL->_parent = RNodeP;
		}

		//更新平衡因子

		RNode->_bf = RNodeL->_bf = 0;

	}

	void RotateL(Node* RNode)
	{
		Node* RNodeR = RNode->_right;
		Node* RNodeRL = RNodeR->_left;

		Node* RNodeP = RNode->_parent;

		RNode->_right = RNodeRL;
		if(RNodeRL) RNodeRL->_parent = RNode;

		RNodeR->_left = RNode;
		RNode->_parent = RNodeR;

		if (RNodeP == nullptr)
		{
			_root = RNodeR;
			_root->_parent = nullptr;
		}
		else
		{
			if (RNodeP->_left == RNode) RNodeP->_left = RNodeR;
			else RNode->_right = RNodeR;

			RNodeR->_parent = RNodeP;
		}

		RNode->_bf = RNodeR->_bf = 0;

	}

	void RotateLR(Node* RNode)
	{
		Node* RNodeL = RNode->_left;
		Node* RNodeLR = RNodeL->_right;
		int bf = RNodeLR->_bf;

		RotateL(RNodeL);
		RotateR(RNode);

		if (bf == 0)
		{
			RNodeLR->_bf = 0;
			RNode->_bf = 0;
			RNodeL->_bf = 0;
		}
		else if (bf == -1)
		{
			RNodeLR->_bf = 0;
			RNodeL = 0;
			RNode->_bf = 1;
		}
		else if (bf == 1)
		{
			RNodeLR->_bf = 0;
			RNodeL->_bf = 0;
			RNode->_bf = -1;
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

		RotateR(RNodeRL);
		RotateL(RNodeR);

		if (bf == 0)
		{
			RNodeRL->_bf = 0;
			RNode->_bf = 0;
			RNodeL->_bf = 0;
		}
		else if (bf == 1)
		{
			RNodeRL->_bf = 0;
			RNodeR->_bf = 0;
			RNode->_bf = -1;
		}
		else if (bf == -1)
		{
			RNodeRL->_bf = 0;
			RNodeR->_bf = 1;
			RNode->_bf = 0;
		}
		else
		{
			assert(false);
		}

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

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

private:
	void _Inorder(Node* _root)
	{
		if (_root == nullptr) return;

		_Inorder(_root->_left);
		cout << _root->_kv.first << ":" << _root->_kv.second << endl;
		_Inorder(_root->_right);
	}



	Node* _root = nullptr;
};


