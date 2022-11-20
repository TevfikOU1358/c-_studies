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
�a��r�lan kaynaklar otomatik �m�rl� oldu�u i�in stack unwinding ger�ekle�ti.
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
//Dinamik �m�rl� oldu�u i�in kaynak geri verilmedi.
0000024C6E6290B0adresinde kaynak cagirildi.
0000024C6E6290F0adresinde kaynak cagirildi.
0000024C6E629130adresinde kaynak cagirildi.
*/
/*
3
Unique_ptr:Destructor �a��r�lmas�ndan kendisi sorumlu.Ve kaynakgeri verildi.

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

//Throw:Ayn� nesne bir daha �a��r�l�r.Nesnenin kendisi g�nderilir.TThrow statement catch blo�unda olmas� zounlu de�il
//throw ex: exception copy ctor u �a���r�r.


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

//yukar�daki foo() i�in destructor �a��r�lmaz.��nk� nesne hayata gelmedi.
//bir nesnenin hayata gelebiliyor olmas� i�in ctor() blo�unun tamamlanabilmesi gerekmektedir.
*/

//Operator new den sonra olu�an exception da destructor �a��r�lmasa da delete �a��r�l�r.(bu konuda endi�eniz olmas�n)
//bir destructor hi� exception  handle edilmemeli.

//e�er stack unwinding ger�ekle�ti�i i�in �a��r�lan destructor terminate ediyor.

//noexcept specifier: ()i�i sabit olmak zorrunda
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
//Destructor yeni kurallara g�re etsenz de etmeseniz de noexcept tan�mlan�r.
//Noexception garatisi ta��yan fonksiyonun exception throw edilirse catch() una bakamdan abort() �a��r�l�r.
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
	auto c = noexcept(foo());  // foo() i�i �a��r�lmad� .��nk� unevaluated contexts
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
	//virtual void func()  ;error	'void Der::func(void)' : ge�ersiz k�lan sanal i�levde 'void Base::func(void) 
	//noexcept' taban s�n�f� sanal �ye i�levinden daha az k�s�tlay�c� �zel durum belirtimi var	
	void func()noexcept;
	void foo()noexcept;  // legal :k�s�tlay�c� durumun t�remi� s�n�fta olmas� herhangi bir s�k�nt� te�kil etmez.
	const char* what() const override;  //normalde error gcc derleyicisi error vermesi laz�m. what() tan�ml� oldu�u exception taban s�n�f�
	//tan�m�da what() k�s�tlay�c� noexcept specifier �na sahip
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
		Tef t;  //exception caught:hata ... : member �n i�indeki hata funtion try block sayesinde ctor da exception yakaland�. Program yine sonland�.
	}
	catch (exception& ex) {
		cout << "exception caught in  main" << ex.what() << "\n";  //bunun �ap��r�lma sebebi derleyici ctor un catch blo�unda rethrow statement yaz�yor.
	}

}
*/
/*
func(Tef x)  //funtion try block kesinlikle parametre olarak �a��r�lan copy ctorun i.�indeki extion u yakalayamaz.
try {

}
catch(const exception &ex) {

}
*/

/*
Resource leakage :
Memory de bir alan allocate edildi.Exception yakaland�.
Kaynak geeri verilmiyor.
Bu duruma resource leak olur.
*/

/*
Exception safety:
Basic quarantee:Nesne hala kullan�labilir olacak.Statinde herhangi bir de�i�iklik olabilir
Strong Quarantee:Nesne hala kullan�labilir ve state i de asla de�i�emez.
*/
