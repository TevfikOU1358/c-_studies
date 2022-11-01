#include <iostream>
#include <vector>

/*
Using bildirim
*/
/*
namespace A {
	int foo(int) {
		return 0;
	}
}

namespace B {
	int foo(int, int) { return 0; }
}
int foo() { return 0; }

int main() {
	using A::foo;  //A n�n foo() bu scope a enjekte edildi
	using B::foo;	//B n�n foo() bu scope a enjekte edildi
	foo(1); //ge�erli
	foo(1, 1); // ge�erli

	//foo(); ge�ersiz bu blokta name lookup yapt� foo() buldu. Ama parametre uygun de�il. �lk buldu�u yerde name lookup biter.
	::foo(); //ge�erli

	using ::foo;
	foo(); //foo nun bulundu�u global namespace bildirildi. Art�k foo() ge�erli
}
*/


/*
Using namespace bildirimi
*/
/*
namespace A{
	int a;
	int b;
	void foo(){}
}
int main() {
	using namespace A; //A namespace i�inde her �ye bu bildirimde ge�erli
	a = 1;
	b = 1;
	foo();
}
*/

/*
ADL: E�er bir fonksiyon parametresi bir namespace i�erisinde belirtilmi� ise;
o fonksiyon namespace i�inde aran�r.Bir daha namespace:: belirtilmesine gerek yoktur.
*/
/*
namespace A {
	
	class Myclass {

	};
	void func(Myclass) {}
}

int main() {
	A::Myclass m;
	func(m); //ADL func direk namespace de bulundu.
	A::func(m); //bu da ge�erli

	
}
*/
/*
namespace { //unnamed namespace:inline d�r. Ba�ka dosyada �a��r�lmaaz.

}*/

/*

namespace tevfik::osman::uluocak {
	int x = 10;
}

int main(){
	tevfik::osman::uluocak::x;

	using namespace tevfik;
	osman::uluocak::x;

	using namespace osman;
	uluocak::x; 
	
	using namespace uluocak;
	x;
}
*/

//namespace ali::veli:: inline can::x = 5;	since C++ 20
/*
namespace A {
	inline namespace B {
		int x;
		int y;
	}
}


int main()
{
	//B namespace i inline oldu�u i�in otomatik g�r�l�r
	A::x; 
	A::y;
	
	namespace sms = A; //namespace alias

	sms::x;
	sms::y;
}
*/