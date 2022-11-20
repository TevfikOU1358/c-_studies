#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;
/*
* 1
class Tef {
public:
	Tef() {
		cout << this << "adresinde kaynak cagirildi.\n";
	}
	~Tef() {
		cout << this << "adresinde kaynak geri verildi.\n";
	}
};


void f3() {
	Tef tef;
	throw 1;
}
void f2() {
	Tef tef;
	f3();
}
void f1() {
	Tef tef;
	f2();
}
int main()
{
	try {
		f1();
	}
	catch (int ) {
	}
}
*/
/*
Çaðýrýlan kaynaklar otomatik ömürlü olduðu için stack unwinding gerçekleþti.
00000021DFB6F8D4adresinde kaynak cagirildi.
00000021DFB6F7B4adresinde kaynak cagirildi.
00000021DFB6F674adresinde kaynak cagirildi.
00000021DFB6F674adresinde kaynak geri verildi.
00000021DFB6F7B4adresinde kaynak geri verildi.
00000021DFB6F8D4adresinde kaynak geri verildi.

*/
/*
* 2

class Tef {
public:
	Tef() {
		cout << this << "adresinde kaynak cagirildi.\n";
	}
	~Tef() {
		cout << this << "adresinde kaynak geri verildi.\n";
	}
};


void f3() {
	auto p = new Tef;
	throw 1;
	delete p;
}
void f2() {
	auto p = new Tef;
	f3();
	delete p;
}
void f1() {
	auto p = new Tef;
	f2();
	delete p;
}
int main()
{
	try {
		f1();
	}
	catch (int) {
	}
}
//Dinamik ömürlü olduðu için kaynak geri verilmedi.
0000024C6E6290B0adresinde kaynak cagirildi.
0000024C6E6290F0adresinde kaynak cagirildi.
0000024C6E629130adresinde kaynak cagirildi.
*/
/*
3
Unique_ptr:Destructor çaðýrýlmasýndan kendisi sorumlu.Ve kaynakgeri verildi.

class Tef {
public:
	Tef() {
		cout << this << "adresinde kaynak cagirildi.\n";
	}
	~Tef() {
		cout << this << "adresinde kaynak geri verildi.\n";
	}
};


void f3() {
	auto up = std::make_unique<Tef>();
	throw 1;
}
void f2() {
	auto up = std::make_unique<Tef>();
	f3();
}
void f1() {
	auto up = std::make_unique<Tef>();
	f2();
}
int main()
{
	try {
		f1();
	}
	catch (int) {
	}
}

000001419FD390B0adresinde kaynak cagirildi.
000001419FD390F0adresinde kaynak cagirildi.
000001419FD39130adresinde kaynak cagirildi.
000001419FD39130adresinde kaynak geri verildi.
000001419FD390F0adresinde kaynak geri verildi.
000001419FD390B0adresinde kaynak geri verildi.
*/
/*
void func() {
	throw std::out_of_range{"out_of_range error"};
}

void foo() {
	try {
		func();
	}
	catch (const exception& ex) {
		cout << "in foo Exception is:" << ex.what() << endl;
		cout << &ex<<"\n";
		throw;  //rethrow
	}
}
int main() {
	try {
		foo();
	}
	catch (const exception& ex) {
		cout << "in main Exception is:" << ex.what() << endl;
		cout << &ex<<"\n";
		
	}
}


* Same object address
in foo Exception is:out_of_range error
0000006CF5AFF8B8
in main Exception is:out_of_range error
0000006CF5AFF8B8

*/
/*
void func() {
	throw std::out_of_range{ "out_of_range error" };
}

void foo() {
	try {
		func();
	}
	catch (const exception& ex) {
		cout << "in foo Exception is:" << ex.what() << endl;
		cout << &ex << "\n";
		throw ex;
	}
}
int main() {
	try {
		foo();
	}
	catch (const exception& ex) {
		cout << "in main Exception is:" << ex.what() << endl;
		cout << &ex << "\n";

	}
}
//Different Address throww ex sayesinde
in foo Exception is : out_of_range error
0000008BCDEFF928
in main Exception is : out_of_range error
0000008BCDEFFA78

*/

//Throw:Ayný nesne bir daha çaðýrýlýr.Nesnenin kendisi gönderilir.TThrow statement catch bloðunda olmasý zounlu deðil
//throw ex: exception copy ctor u çaðýýrýr.


/**

class Tef {
public:
	Tef() {
		//
		if (true)
			throw std::runtime_error{ "tef exception" };
	}
	~Tef() {
		cout << "destructor" << endl;
	}
};
void foo() {
	Tef x;

}
int main() {
	try {
		foo();
	}
	catch (const exception& ex) {
		cout << "exception caught:" << ex.what() << "\n";
	}
}

//yukarýdaki foo() için destructor çaðýrýlmaz.çünkü nesne hayata gelmedi.
//bir nesnenin hayata gelebiliyor olmasý için ctor() bloðunun tamamlanabilmesi gerekmektedir.
*/

//Operator new den sonra oluþan exception da destructor çaðýrýlmasa da delete çaðýrýlýr.(bu konuda endiþeniz olmasýn)
//bir destructor hiç exception  handle edilmemeli.

//eðer stack unwinding gerçekleþtiði için çaðýrýlan destructor terminate ediyor.

//noexcept specifier: ()içi sabit olmak zorrunda
void f1(); //exception throw edebilir
void f2()noexcept(false);//exception throw edebilir
void f3()noexcept;//exception throw etmeme garantisi var.
void f4()noexcept(true);//exception throw etmeme garantisi var.


//noexcept operatoru
void foo();
void foo2()noexcept;

constexpr bool b = noexcept(foo());  //false;
constexpr bool b2 = noexcept(foo2()); //true
void func()noexcept(noexcept(foo)); //foo() except etmeme garantisi varsa func() da except  etmeme garantisi var.
//Destructor yeni kurallara göre etsenz de etmeseniz de noexcept tanýmlanýr.
//Noexception garatisi taþýyan fonksiyonun exception throw edilirse catch() una bakamdan abort() çaðýrýlýr.
//unevaluated contexts:
//1 sizeof()
//2 decltype();
//3 noexcept();

/*t foo3() {
	cout << "foo() cagirildi:" << endl;
	return 1;
}
int main() {
	int x = 1;
	sizeof(x++);
	decltype(++x);
	cout << x<<"\n"; // x = 1 unevaluated context
	auto c = noexcept(foo());  // foo() içi çaðýrýlmadý .Çünkü unevaluated contexts
	int (*fp)() = foo3;  //function pointer;
	//int (*fp)()noexcpet = foo; syntax error noexcept olmayan fonksiyonun adresi noexcept olan adrese atanamaz.
}
*/
/*
class Base {
public:
	virtual void func()noexcept;
	virtual void foo();
};

class Der : public Base , public exception {
public:
	//virtual void func()  ;error	'void Der::func(void)' : geçersiz kýlan sanal iþlevde 'void Base::func(void) 
	//noexcept' taban sýnýfý sanal üye iþlevinden daha az kýsýtlayýcý özel durum belirtimi var	
	void func()noexcept;
	void foo()noexcept;  // legal :kýsýtlayýcý durumun türemiþ sýnýfta olmasý herhangi bir sýkýntý teþkil etmez.
	const char* what() const override;  //normalde error gcc derleyicisi error vermesi lazým. what() tanýmlý olduðu exception taban sýnýfý
	//tanýmýda what() kýsýtlayýcý noexcept specifier ýna sahip
};
*/
/*
//Function Try Block
void func(int x)
try {
	if (x == 0)	throw 1;
}
catch(int) {
	cout << "exception caught\n";
}

class Member {
public:
	Member() {
		throw runtime_error{ "hata ..." };
	}
};

class Tef {

public:
	Tef()
		try {

	}
	catch (exception& ex) {
		cout << "exception caught in  ctor " << ex.what()<<"\n";
	}
private:
	Member mx;
};

int main() {
	func(0); //exception caught
	try {
		Tef t;  //exception caught:hata ... : member ýn içindeki hata funtion try block sayesinde ctor da exception yakalandý. Program yine sonlandý.
	}
	catch (exception& ex) {
		cout << "exception caught in  main" << ex.what() << "\n";  //bunun çapðýrýlma sebebi derleyici ctor un catch bloðunda rethrow statement yazýyor.
	}

}
*/
/*
func(Tef x)  //funtion try block kesinlikle parametre olarak çaðýrýlan copy ctorun i.çindeki extion u yakalayamaz.
try {

}
catch(const exception &ex) {

}
*/

/*
Resource leakage :
Memory de bir alan allocate edildi.Exception yakalandý.
Kaynak geeri verilmiyor.
Bu duruma resource leak olur.
*/

/*
Exception safety:
Basic quarantee:Nesne hala kullanýlabilir olacak.Statinde herhangi bir deðiþiklik olabilir
Strong Quarantee:Nesne hala kullanýlabilir ve state i de asla deðiþemez.
*/
