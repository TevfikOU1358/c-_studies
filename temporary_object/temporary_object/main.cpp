#include <iostream>

using namespace std;
class Myclass{
public:
	Myclass() {
		cout << "default ctor" << endl;
	}
	~Myclass() {
		cout << "destreuctor" << endl;
	}
	void foo() {
		cout << "foo()" << endl;
	}
};

int main() {
	/*Myclass&& x = Myclass();  //valid
	const Myclass& y = Myclass(); //valid
	//Myclass& y = Myclass(); //invalid 
	*/
	/*
	cout << "main basladi" << endl;
	Myclass().foo();
	cout << "main devam ediyor" << endl;
	main basladi
default ctor
foo()
destreuctor
main devam ediyor
*/


	cout << "main basladi" << endl;
	if (1) {
		Myclass&& r = Myclass();  //Myclass temporary object r value referanca baðlandýðý için reference ömrü bitince obje ömrü biter. Bu duruma life extension denir.

	    cout << "main devam ediyor" << endl;
		Myclass().foo();
	}
	cout << "main sona erdi" << endl;
	/*
	main basladi
default ctor
main devam ediyor
default ctor
foo()
destreuctor
destreuctor
main sona erdi
*/
}