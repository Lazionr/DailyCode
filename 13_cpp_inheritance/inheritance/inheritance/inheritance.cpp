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


class Animal
{
protected:
	std::string _name = "a";
};

class Dog : public Animal
{
public:
	void Print()
	{
		std::cout << "_name:" << _name << std::endl;
		std::cout << "_feature:" << _feature << std::endl;
	}
protected:
	std::string _name = "xxx"; //同名成员,隐藏基类_name
	std::string _feature = "run";
};

void test_hidden()
{	
	Dog d;
	d.Print();
}



namespace stl
{
	class Person
	{
	public:
		Person(const char* name = "zhangsan")
			:_name(name)
		{
			std::cout << "Person()" << std::endl;
		}

		Person(const Person& per)
			:_name(per._name)
		{
			std::cout << "Person(const Person& per)" << std::endl;
		}

		Person& operator=(const Person& per)
		{
			std::cout << "Person& operator=(const Person& per)" << std::endl;
			if (this != &per)
			{
				_name = per._name;
			}

			return *this;
		}

		~Person()
		{
			std::cout << "~Person()" << std::endl;
		}

	protected:
		std::string _name;
	};

	class Student : public Person
	{
	public:
		//调用基类的构造函数
		Student(const char* name, std::string stuid)
			:Person(name)
			, _stuid(stuid)
		{
			std::cout << "Student(const char* name,std::string stuid)" << std::endl;
		}

		Student(const Student& stu)
			//显示调用基类的拷贝构造,初始化基类成员
			:Person(stu)
			, _stuid(stu._stuid)
		{
			std::cout << "Student(const Student& stu)" << std::endl;
		}

		Student& operator=(const Student& stu)
		{
			std::cout << "Student& operator=(const Student& stu)" << std::endl;
			if (this != &stu)
			{
				//指定类域显示调用
				Person::operator=(stu);//将基类成员进行赋值重载
				_stuid = stu._stuid;
			}

			return *this;
		}

		~Student()
		{
			std::cout << "~Student()" << std::endl;
			//派生类析构之后自动调用基类的析构函数
		}

	protected:
		std::string _stuid;
	};

	//class Base final
	//{
	//private:
	//	//Base()
	//	//{
	//	//	//...
	//	//}
	//protected:
	//	int a = 1;
	//};

	//class Derive : public Base
	//{
	//public:
	//	Derive()
	//		:Base()
	//	{
	//		//...
	//	}
	//protected:
	//	int b = 2;
	//};


	void test_memberfunc()
	{
		Student s1("zhangsan", "111");
		Student s2("lisi", "222");
		Student s3("wangwu", "333");

		s1 = s3;
	}

	//在友元声明中出现的类名，在之前必须有一个前向声明
	class BenZ;

	class Car
	{
	public:
		friend void ShowMsg(const Car* car, const BenZ* benz);
	protected:
		std::string _name = "car";
	};

	class BenZ : public Car
	{
		// 派生类不加友元就会报错
		// error C2248: “stl::BenZ::_feature”: 无法访问 protected 成员(在“stl::BenZ”类中声明)
	public:
		friend void ShowMsg(const Car* car, const BenZ* benz);
	protected:
		std::string _feature = "comfortable";
	};

	void ShowMsg(const Car* car, const BenZ* benz)
	{
		std::cout << car->_name << std::endl;
		std::cout << benz->_feature << std::endl;
	}

	void test_friend()
	{
		Car car;
		BenZ benz;

		ShowMsg(&car, &benz);
	}


	class Animal
	{
	public:
		std::string _name = "a";
		static int _nums;
	};

	int Animal::_nums = 10;

	class Dog : public Animal
	{
	protected:
		std::string _feature = "run";
	};

	void test_static()
	{
		Animal aim;
		Dog dog;

		//判断静态成员地址是否一致
		std::cout << &(aim._nums) << std::endl;
		std::cout << &(dog._nums) << std::endl;
	}


}

namespace tst
{
	//class food
	//{
	//public:
	//	std::string _category = "food";
	//};

	//class vegetable : public food
	//{
	//public:
	//	std::string _feature = "green";
	//};

	//class fruit : public food
	//{
	//public:
	//	std::string _name = "fruit";
	//};

	//class tomato : public vegetable ,public fruit
	//{
	//protected:
	//	int nums = 10;
	//};


	class food
	{
	public:
		std::string _category = "food";
	};

	class vegetable : virtual public food
	{
	public:
		std::string _feature = "green";
	};

	class fruit : virtual public food
	{
	public:
		std::string _name = "fruit";
	};

	class tomato : public vegetable, public fruit
	{
	protected:
		int nums = 10;
	};

	void test_binary()
	{
		tomato to;
		
		//error C2385: 对“_category”的访问不明确
		//to._category = "fruit";

		//显示指定访问哪个基类的成员可以解决二义性问题，但数据冗余无法解决
		//to.vegetable::_category = "vegetable";
		//to.fruit::_category = "fruit";

		to._category = "food";

	}


	
}


int main()
{
	//test_template();
	//test_conversion();
	//test_position();

	//test_hidden();

	//stl::test_memberfunc();

	//stl::test_friend();
	//stl::test_static();

	tst::test_binary();

	return 0;
}