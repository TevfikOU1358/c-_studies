#include <iostream>

using namespace std;

class Myclass {
public:
	int x;
	int y; 
	int z;
	static int s;
	void func() {
		//this.s:: s memberýna eriþemez.syntax error
	}
	static int foo();
	//static int foo2()const; //const staticklerde kullanýlamaz.
	void foo3()const {
		//x = 5; //x deðerine const nesne üzerinden deðer verilemez..
		
		s = 5; //geçerli s bir statik üye
	}
};

int Myclass::foo() { 
	//this::syntax error;
	//x; syntax error :statik olmayan 'Myclass::x' üyesine baþvuru geçersiz
	Myclass m;
	m.x = 5; // valid nesne ile kullanýlabilir.
	return 0;
}

int main()
{
	cout << sizeof(Myclass)<<endl; //12 :static olan sayýlmaz
	//static sadece declerationda yapýlabilir.

}