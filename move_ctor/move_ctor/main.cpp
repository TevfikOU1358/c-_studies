#include <iostream>

using namespace std;

class Myclass {
public:
	Myclass() = default;
	Myclass(const Myclass& other) {
		cout << "copy constructor" << endl;
	}

	Myclass(Myclass&& other) {
		cout << "move constructor" << endl;
	}

	Myclass& operator=(const Myclass& other) {
		cout << "copy assignment" << endl;
		return *this;
	}

	Myclass& operator=(Myclass&& other) {
		cout << "move assignment" << endl;
		return *this;
	}

};

int main() {
	Myclass mx, mz; 
	Myclass my = mx;    //my:: copy constructor
	mz = mx;		    //mz:: copy assignmet 
	Myclass ma = std::move(mx); //ma = move constructor std::move r value reference
	ma = std::move(my);	//move assginment       std::move:: r value reference
}

