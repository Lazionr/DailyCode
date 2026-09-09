#include <iostream>
#include "HashTable.h"

using namespace std;

void test1()
{
	//int a[] = { 19,30,52,32,26,76,10 };
	int a[] = { 19,30,5,36,13,20,21,12,56,28 };

	HashTable<int, int> ht;
	for (auto& e : a)
	{
		ht.Insert({ e,e });
	}
	
	ht.Erase(20);
	if (ht.Find(20))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

 }



int main()
{
	test1();
	return 0;
}