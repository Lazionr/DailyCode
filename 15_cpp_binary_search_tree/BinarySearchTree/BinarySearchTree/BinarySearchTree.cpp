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
private:
			
};

int main()
{

	return 0;
}