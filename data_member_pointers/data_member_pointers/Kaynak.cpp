#include <iostream>
#include <functional>

using namespace std;


class Myclass {
public:
	static void func(int x) {
		cout << "Myclass::func(int x):" << x << '\n';
	}
	void foo(int x) {
		cout << "Myclass::foo(int x):" << x << '\n';
	}
	void bar(int x)const {
		cout << "Myclass::bar(int x):" << x << '\n';
	}
	int faa(int x, int y) {
		cout << "Myclass::faa(int x, int y):" << x << y << '\n';
		return x + y;
	}
	void a() {
		(this->*FPTR)(12, 25);
	}
private:
	int (Myclass::*FPTR)(int, int) = &Myclass::faa;
};

//Typedef bildirimi
typedef int(Myclass::*FPTR2)(int, int);
using FPTR3 = int(Myclass::*)(int, int);
using FPTR4 = decltype(&Myclass::faa);
/*
int main() {
	void(*fp)(int) = Myclass::func; 
	//void(*fp)(int) = &Myclass::func; //üst satýrla ayný
	fp(24); //Myclass::func(int x):24

	auto p = &Myclass::foo;  // non static member function için  adres ifadesi & ile yapýlýr.
	void(Myclass:: * fp2)(int) = &Myclass::foo; //non-static atama

	void(Myclass:: * fp3)(int) const= &Myclass::bar; //non-static const  atama


	//.* , ->* opeartorleri:sýnýf nesnesiyle fonksiyonun adresi çaðrýlýr. sað operand non-static olmalýdýr
	Myclass m1;
	(m1.*fp2)(5); //Myclass::foo(int x):5
	(m1.*fp3)(10);  //Myclass::bar(int x):10

	auto pd = new Myclass{};
	(pd->*fp2)(58);  //Myclass::foo(int x):58

	void(Myclass::*fp4)(int)const = &Myclass::bar;
	
	m1.a();  //Myclass::faa(int x, int y):1225
}
*/

//invoke():<functional>
class Tef {
public:
	int y{33};
};

int foo(int x, int y) { return x + y; }
int main() {
	Myclass m1;
	cout<<"std::invoke(foo, 10, 20):" << std::invoke(foo, 10, 20) << '\n'; //std::invoke(foo, 10, 20):30
	invoke(&Myclass::foo, m1, 5);  //Myclass::foo(int x):5


	//data member pointer
	Tef tef;
	//int* p2 = &Tef::y; //y non static data member :error
	int Tef::* p2 = &Tef::y; 
	cout << tef.*p2 << '\n'; //33
}