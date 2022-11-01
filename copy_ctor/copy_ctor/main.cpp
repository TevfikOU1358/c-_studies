#include <iostream>

using namespace std;

class Myclass {
public:
	Myclass() = default; //default constructor oluþma zorunluluðunu kaldýrdýk.
	Myclass(int){
		cout << "ctor" << endl;
	}
	Myclass(const Myclass& others) {
		cout << "copy ctor" << endl;
		cout << "this:" << this << endl;
		cout << "others:" << &others << endl;
	}
	~Myclass()
	{
		cout << "destructor" << endl;
	}
};
int main() {
	Myclass m{5};
	cout << "&m:" << &m<<endl;
	Myclass m2 = m;
	cout << "&m2:" << &m2 << endl;
}