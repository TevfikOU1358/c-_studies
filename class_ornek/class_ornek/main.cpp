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
	//m.foo(5);  //name look up yapt�. 2 sini buldu. context controlden sadece ilki ge�ti. access kontrolden 1. ge�emedi.Syntax error
}