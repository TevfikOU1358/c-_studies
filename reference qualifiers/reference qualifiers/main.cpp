#include <iostream>
using namespace std;

class Myclass {
public:
	void func()&{} //L value reference qualifiers
	void foo()&&{} //R value reference qualifiers
};
int main() {
	Myclass{}.foo(); // Myclass():r value . sadece foo çaðýrýlýr.
	//Myclass().func() invalid

	Myclass m;
	m.func(); //m l value sadece func() çaðýrýlýr.
	//m.foo() :syntax error

	move(m).foo(); //move(m): r value
}