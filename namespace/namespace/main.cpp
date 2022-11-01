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
	using A::foo;  //A nýn foo() bu scope a enjekte edildi
	using B::foo;	//B nýn foo() bu scope a enjekte edildi
	foo(1); //geçerli
	foo(1, 1); // geçerli

	//foo(); geçersiz bu blokta name lookup yaptý foo() buldu. Ama parametre uygun deðil. Ýlk bulduðu yerde name lookup biter.
	::foo(); //geçerli

	using ::foo;
	foo(); //foo nun bulunduðu global namespace bildirildi. Artýk foo() geçerli
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
	using namespace A; //A namespace içinde her üye bu bildirimde geçerli
	a = 1;
	b = 1;
	foo();
}
*/

/*
ADL: Eðer bir fonksiyon parametresi bir namespace içerisinde belirtilmiþ ise;
o fonksiyon namespace içinde aranýr.Bir daha namespace:: belirtilmesine gerek yoktur.
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
	A::func(m); //bu da geçerli

	
}
*/
/*
namespace { //unnamed namespace:inline dýr. Baþka dosyada çaðýrýlmaaz.

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
	//B namespace i inline olduðu için otomatik görülür
	A::x; 
	A::y;
	
	namespace sms = A; //namespace alias

	sms::x;
	sms::y;
}
*/