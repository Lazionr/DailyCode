#include <iostream>

using namespace std;


class Person
{
public:
	virtual void BuyTicket() { cout << "买票->全价" << endl; }
};

class Student : public Person
{
public:
	virtual void BuyTicket() { cout << "买票->半价" << endl; }
};

void Func(Person* ptr)
{
	ptr->BuyTicket();
}

void test1()
{
	Person ps;
	Student st;

	//多态
	//派生类指针可以隐式类型转换成基类指针
	Func(&ps);
	Func(&st);

}



int main()
{
	test1();
	return 0;
}