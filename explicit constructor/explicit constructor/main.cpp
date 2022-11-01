#include <iostream>

using namespace std;
class Myclass {
public:
	Myclass(){}
	explicit Myclass(int x) {
		cout << "Myclass(int x" << endl;

	}
	Myclass(const Myclass&) {
		cout << "const Myclass& ctor" << endl;
	}
};

int main() {
	Myclass m( 5 );  //legal
	Myclass m1{ 5 };  //legal
	//Myclass m2 = 10;  //implicit ctor conversion izin verilmiyor
}