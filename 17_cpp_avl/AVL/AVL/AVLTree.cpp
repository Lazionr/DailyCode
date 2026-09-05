#include "AVLTree.h"


void test_insert()
{
	AVLTree<string, int> dict;

	dict.Insert(make_pair("sort", 1));
	dict.Insert(make_pair("string", 1));
	
	dict.Inorder();

}



int main()
{
	test_insert();
	return 0;
}