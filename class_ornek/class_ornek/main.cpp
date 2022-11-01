#include <iostream>

using namespace std;

class Myclass {
	void foo(int);
public:

	void foo(int, int);
};
int main()
{
	Myclass m;
	//m.foo(5);  //name look up yaptý. 2 sini buldu. context controlden sadece ilki geçti. access kontrolden 1. geçemedi.Syntax error
}