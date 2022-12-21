#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std ;


//bizim için derleyicilere kod yazdýran yapýlara template(þablon) denir

/*
1) function template
2)class template
3)variable template
4) alias template
*/

//parameters:
// type parameter
// non type parameter
// template parameter
 
//
/*
template <typename T>
void foo(T x, T y){}

template <typename T>
void func(T& x, T& y){}
int main() {
	foo(2, 2); //legal int çaðrýsý
	//foo(2, 2.4); illegalT ayný türden olmalý.implicit dönüþüm de yapýlamaz.(char -> int gibi)
	foo("ali", "can"); //legal parametrelere yapýlan çaðrý const char *;
	foo("ali", "mert"); //legal parametrelere yapýlan çaðrý const char *;
	func("ali", "can"); //Parametre dönüþümü const char[4] iki parametre için de uygun
	//func("ali", "mert"); //illegal 2 parametre karakter sayýsý uymuyor.
}

*/

//RTTI Run Time Type Information

//dynamic cast downcasting için kullanlýr.
class Base {
public:
	virtual void foo(){}
};

class Der :public Base {

};
class Tef :public Base {

};

void func(Base& mybase) {
	Der& der = dynamic_cast<Der&>(mybase);  //eðer baþka sýnýf downcast eder ise exception throw eder.Method1
}
/*
int main() {
	//1
	Der myder;
	Base* mybase = &myder;

	Der* derptr = dynamic_cast<Der*>(mybase);//legal olmasý için en az bir sanal fonksiyonu olamlý. //Downcasting(dynamic cast ile mümkün)
		//eðer dynamic cast baþka der sýnýftan elde edildiyse nullptr döner.
		//ayný þey derptr nin sublass ýn türünden ise o da dolu döner(nullptr dönmez)
		if (derptr)	cout << "evet dogru sinif\n";
	    //2

		try {
			Tef myder2;  //Bad dynamic_cast! exception throw eder.  
			Der myder2;  //legal devamkee
			func(myder2);
		}
		catch (const exception& e) {
			cout << e.what();  
		}
}
*/

//typeid
/*
template<typename T>

void func(T) {
	cout << typeid(T).name()<<"\n";
}

void f1(Base* mybase) {
	if (typeid(*mybase) == typeid(Der))
	{
		cout << "ayni nesne\n";
	}
}
int main() {
	cout<< typeid(int).name()<<"\n"; // int//Typeinfo sýnfýndan nesne döner
	cout << boolalpha;
	cout << (typeid(int) == typeid(double)); //false ayný nesneyi döndürmez

	func('a');
	func(2);
	func(2.3);
	Der myder;
	f1(&myder);  //ayni nesne

	//typeid operatoru unevaluated context
	int a = 5;
	typeid(a++);
	cout << a << "\n";
}
*/
//explicit template argument
/*
template<typename T>
void foo(T x){
	cout<<typeid(T).name()<<"\n"; 
}

int main() {
	int x = 5;
	foo<double>(x);  //explicit template argument double
	foo<char>(x);  //char
}
*/

template <typename T>
void foo(T) {
	cout<< "template called:" << typeid(T).name() << "\n";
}

void foo(int) {
	cout << "global foo cagirildi\n";

}

int main() {
	foo('a');
	foo(1.2);
	foo(1.2f);
	foo(12u);
	foo(12);



}

/*template called:char
template called:double
template called:float
template called:unsigned int
global foo cagirildi
*/