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
	Myclass m{};    //implicitly declared olan default constructor s�n�f�n t�m elemanlar�n� default initialize eder.Dolay�s�yla t�m de�erler 0 olur.
	//E�er kullan�c� default constructor kendisi yazsayd� t�m de�erler ��p de�er olurdu.
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
	//B b{}; //Sentax hatas� B default ctor implicitly declared oldu.tim memberlar� default initialize oldu.
	//A ax nesnesinin default ctoru yok default ctor deleted oldu.
	
}
*/
/*
Bir s�n�fa copy veya move semanti�i ile ilgili fonksiyonu user yaz�yor ise kendisi memberlar� kendisi yazm�yor ise copy veya move olmaz.
Ya default olarak derleyici �a��rmal� , ya da yaz�lan fonksiyonda initializaiator listte i�lemler yap�lmal�d�r.

*/