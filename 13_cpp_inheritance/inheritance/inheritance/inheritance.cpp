#include <iostream>
#include <vector>

//class Student
//{
//public:
//	//身份认证
//	void identity()
//	{
//		std::cout << "void identity()" << std::endl;
//
//	}
//
//	void study()
//	{
//		std::cout << "void study()" << std::endl;
//	}
//private:
//	std::string _name;
//	int _age;
//	std::string _address;
//	std::string _tel;
//	
//	int _id; //学号
//	//...
//};

//class Teacher
//{
//public:
//	//身份认证
//	void identity()
//	{
//		std::cout << "void identity()" << std::endl;
//
//	}
//
//	void teaching()
//	{
//		std::cout << "void teaching()" << std::endl;
//
//	}
//
//private:
//	std::string _name;
//	int _age;
//	std::string _address;
//	std::string _tel;
//
//	std::string _title; //职称
//	//...
//};

class Person
{
public:
	//身份认证
	void identity()
	{
		std::cout << "void identity()" << std::endl;
	}
protected:
	std::string _name;
	int _age;
	std::string _address;
	std::string _tel;
};

class Student : public Person
{
public:
	void study()
	{
		std::cout << "void study()" << std::endl;
	}
protected:
	int _id;
};

class Teacher : public Person
{
public:
	void teaching()
	{
		std::cout << "void teaching()" << std::endl;
	}
protected:
	std::string _title;
};


//用继承实现栈
template<class T>
class stack : public std::vector<T>
{
public:
	void push(const T& x)
	{
		std::vector<T>::push_back(x);
	}

	void pop()
	{
		std::vector<T>::pop_back();
	}
 
	const T& top() const
	{
		return std::vector<T>::back();
	}

	const bool empty() const
	{
		return std::vector<T>::empty();
	}
		
};

void test_template()
{
	stack<int> st;
	
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

}

void test_conversion()
{
	Person per;
	Student stu;

	//基类对象不能赋值给派生类对象
	//error C2679: 二元“=”: 没有找到接受“Person”类型的右操作数的运算符(或没有可接受的转换)
	//stu = per;

	Person* ps = &per;
	Student* st = &stu;

	//派生类对象指针可以转换成基类对象指针
	Person* pp = st;

	//基类对象指针可以强转成派生类对象,	
	Student* ss = (Student*)ps;

}

void test_position()
{
	Person per;
	Student stu;

	std::cout << &per << std::endl;
	std::cout << &stu << std::endl;

}



int main()
{
	//test_template();
	//test_conversion();
	test_position();
	return 0;
}