#include <iostream>

using namespace std;

class Myclass {
public:
	Myclass() = default;
	Myclass(int x, int y): mx{x}, my{y}{}
	Myclass(const Myclass& other) { //copy ctor
		cout << "copy ctor" << endl;
		mx = other.mx;
		my = other.my;
	}
	Myclass& operator=(const Myclass& other) {      //copy assignment
		cout << "copy assignment" << endl;
		mx = other.mx;
		my = other.my;
		return *this;
	}
	void print()const {
		cout << "mx: " << mx << endl;
		cout << "my: " << my << endl;
	}
	int mx;
	int my;
};

int main() {
	Myclass m1{10, 15};
	Myclass m2 = m1;
	m1.print();
	m2.print();
	Myclass m3;
	m3 = m1;

	m3.print();

}

/*
copy ctor
mx: 10
my: 15
mx: 10
my: 15
copy assignment
mx: 10
my: 15
*/