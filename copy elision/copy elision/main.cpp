#include <iostream>
using namespace std;

class Myclass
{
public:
	Myclass(const char* str = "\0") //default constructor
	{
		cout << "Constructor called" << endl;
	}

	Myclass(const Myclass& Myclass) //copy constructor
	{
		cout << "Copy constructor called" << endl;
	}
};
Myclass foo() {
	return Myclass{};
}
int main()
{
	Myclass m1 = "copy me"; //copy elias oldu�u i�in derleyici optimizasyon i�in kopyalamay�p default init edicek.
	Myclass m2 = foo(); 
	return 0;
}
