#include <iostream>
using namespace std;

class Myclass {
public:
	Myclass() : ax(), bx(), cx(){} //constructor
	void print()const {
		cout << "ax:" << ax << endl;
		cout << "bx:" << bx << endl;
		cout << "cx:" << cx << endl;
	}
	int ax;
	int bx;
	int cx;
};


int main()
{
	Myclass m;
	m.print();
}