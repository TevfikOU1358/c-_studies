#include <iostream>
using namespace std;

class Myclass {
public:
	void func()&{} //L value reference qualifiers
	void foo()&&{} //R value reference qualifiers
};
int main() {
	Myclass{}.foo(); // Myclass():r value . sadece foo �a��r�l�r.
	//Myclass().func() invalid

	Myclass m;
	m.func(); //m l value sadece func() �a��r�l�r.
	//m.foo() :syntax error

	move(m).foo(); //move(m): r value
}