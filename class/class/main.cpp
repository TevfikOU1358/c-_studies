#include <iostream>

using namespace std;

class MyClass {
private:
	int x;
public:
	int foo(int x) {
		x =  this->x;
		return 0;
	}
};

int main()
{
	MyClass myclass;
	myclass.foo(2);
	return 0;

}