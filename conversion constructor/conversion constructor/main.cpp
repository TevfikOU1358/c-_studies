#include <iostream>
#include <stdlib.h>
using namespace std;
/*
class Myclass {
public:
	Myclass() {
		cout << "Constructor:" << "this:" << this << endl;
	}
	Myclass(int x)//conversion constructor
	{
		cout << "conversion ctor:" << this << endl;
	}
	~Myclass() {
		cout << "destructor" <<"this:"<<this<< endl;
	}
	Myclass& operator=(const Myclass&other) {
		cout << "copy assignment" << endl;
		cout << "this:" << this << endl;
		cout << "other:" << &other << endl;
		return *this;
	}
};

int main()
{
	Myclass m;
	m = 3;	//conversion constructor
}
*/
/*
Constructor:this:0000003901D7F734
conversion ctor:0000003901D7F814
copy assignment
this:0000003901D7F734
other:0000003901D7F814
destructorthis:0000003901D7F814
destructorthis:0000003901D7F734
*/


class A {

};

class B {
public:
	B(A){} //conversion constructor
};

class C {
public:
	C(B){} //conversion constructor
};

int main()
{
	A ax;

	C cx = static_cast<B>(ax);

}