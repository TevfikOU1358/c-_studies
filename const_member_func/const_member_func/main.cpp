#include <iostream>

using namespace std;

class Myclass {
public:
	void foo() {
		func(); //valid T * -> const T* 
	};
	void func()const {
		//foo(); //invalid const T* -> T *
	};

};

class myclass {
public:
	myclass* foo1() {
		cout << "foo1:" << this << endl;
		return this;
	};
	myclass& foo2() {
		cout << "foo3:" << this << endl;
		return *this;
	};
	myclass  foo3() {
		cout << "foo2:" << this << endl;
		return *this;
	};


};

class MyClass {
public:
	MyClass& foo() {
		cout << "foo() " << endl;
		mx = 10;
		return *this;

	}
	const MyClass& foo()const {
		cout << "foo()const" << endl;
		//mx = 10; syntax error const nesne
		return *this;
	}
private:
	int mx;
};

int main()
{
	MyClass m1{};
	const MyClass m2 = m1;
	m1.foo();  //foo()
	m2.foo();	//foo()const
	myclass m;
	myclass *m_ptr = &m;
	m.foo1()->foo2().foo3();  //chaining 
	m_ptr->foo1()->foo2().foo3();	//chaining

	return 0;
}


