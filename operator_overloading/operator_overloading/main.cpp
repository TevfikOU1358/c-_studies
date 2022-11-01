#include <iostream>

using namespace std;
/*
using namespace std;
class Myclass {
public:
	Myclass operator+(const Myclass y)const {
		cout << "class operator overloding"<<endl;
		return *this;
	}
};

bool operator!(Myclass x) {
	cout << "global operator overloading" << endl;
	return 0;
}
int main()
{
	cout.operator<<(5).operator<<(10).operator<<(endl);
	Myclass x ,y,z;

	z = x + y;
	y.operator+(x);
	x.operator+(y);
	operator!(x);

	
}
*/



/*
510
class operator overloding
class operator overloding
class operator overloding
global operator overloading
*/

/*
class Myclass {
public:
	Myclass operator++(int x) {
		cout << "sonek operator overloading x:" << x << "\n";
		return *this;
	}

	Myclass operator++() {
		cout <<" onek operator overloading\n";
		return *this;
	}
};

int main()
{
	Myclass m;
	m++; //sönek operator overloading

	m.operator++(0); //sönek operator overloading

	++m; //önek operator overloading

	m.operator++();//önek operator overloading
}
*/
/*
sonek operator overloading x:0
sonek operator overloading x:0
 onek operator overloading
 onek operator overloading
 */

class A {
public:
	void foo() {
	}
	void bar() {
	}
};

class Myclass {
public:

	A& operator *(){
		A a;
		cout << "* overloading\n";
		return a;
	}
	A* operator ->(){
		A a;
		cout << "-> overloading\n";
		return &a;
	}
};

int main()
{
	Myclass m;
	m->bar();  
	
	m.operator->()->bar(); 
	
	(*m).foo();  

	m.operator*().foo();
}

/*

-> overloading
-> overloading
* overloading
* overloading

*/