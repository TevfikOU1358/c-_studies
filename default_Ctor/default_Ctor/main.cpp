#include <iostream>
using namespace std;

/*
class Myclass {
public:

	int x;
	int y;
	int z;
};
int main()
{
	Myclass m{};    //implicitly declared olan default constructor sýnýfýn tüm elemanlarýný default initialize eder.Dolayýsýyla tüm deðerler 0 olur.
	//Eðer kullanýcý default constructor kendisi yazsaydý tüm deðerler çöp deðer olurdu.
	cout << m.x << endl;
	cout << m.y << endl;
	cout << m.z << endl;
}

*/
/*
class A {
	A(int);
};

class B {
public:
	A ax;
};

int main() {
	//B b{}; //Sentax hatasý B default ctor implicitly declared oldu.tim memberlarý default initialize oldu.
	//A ax nesnesinin default ctoru yok default ctor deleted oldu.
	
}
*/
/*
Bir sýnýfa copy veya move semantiði ile ilgili fonksiyonu user yazýyor ise kendisi memberlarý kendisi yazmýyor ise copy veya move olmaz.
Ya default olarak derleyici çaðýrmalý , ya da yazýlan fonksiyonda initializaiator listte iþlemler yapýlmalýdýr.

*/