#include <iostream>

using namespace std;

class Myclass {
public:
	int x;
	int y; 
	int z;
	static int s;
	void func() {
		//this.s:: s member�na eri�emez.syntax error
	}
	static int foo();
	//static int foo2()const; //const staticklerde kullan�lamaz.
	void foo3()const {
		//x = 5; //x de�erine const nesne �zerinden de�er verilemez..
		
		s = 5; //ge�erli s bir statik �ye
	}
};

int Myclass::foo() { 
	//this::syntax error;
	//x; syntax error :statik olmayan 'Myclass::x' �yesine ba�vuru ge�ersiz
	Myclass m;
	m.x = 5; // valid nesne ile kullan�labilir.
	return 0;
}

int main()
{
	cout << sizeof(Myclass)<<endl; //12 :static olan say�lmaz
	//static sadece declerationda yap�labilir.

}