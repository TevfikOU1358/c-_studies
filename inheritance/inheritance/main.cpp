#include <iostream>
#include <cstdio>
using namespace std;
/*
1)Name Lookup
2)Context Control
3)Access Control
*/
/*Eðer.veya->operatörünün saðýnda kalan isim, 
eðer sol taraf operandý türemiþ sýnýf nesnesi ise önce türemiþ sýnýfta aranýr.
bulunamaz ise taban sýnýfta aranýr.

Der -> Base (upcasting) örtülü dönüþüm var
Der myder;
Base *ptr = &der; geçerli
Base &r  = der;   geçerli
Base mybase = der geçerli ama tehlikeli(object slicing)
Base -> Der (downcasting) örtülü dönüþüm yok.
*/
/*
* 1
class Base {
public:
	void foo() { cout << "Base foo()\n"; }
	void func() { cout << "Base func()\n"; }
protected:
	int p_x;
};
//class Der : Base = class Der : private Base
class Der : public Base {
public:
	void foo() { cout << "Der foo()\n";
	p_}
};

int main() {
	Der der;
	der.foo();  //Der foo()
	der.func(); // önce Der classta aradý bulamadý. Sonra Base classta aradý buldu.
	//der.p_x;  //error: public yolla kalýtým edilen türemiþ sýnýf , taban sýnýfýn protected bölümünü private bölümüne alýr.Ve instance yoluyla eriþemez.

}
*/
/*
* 2
class Base {
public:
	Base() { cout << "Base ctor\n"; }
};

class Der :public Base {
public:
	Der() { cout << "Der ctor\n"; }
};
int main() {
	Der myder; //Base ctor \n Der ctor

}*/
/*
3
class Base {
public:
	virtual void foo() = 0; //sapsanal function pure virtual
	virtual void func(){}
};

class Der :public Base {
public:
	void foo() {};
	void func(int ) {}//geçerli
	//void func(int, int)override; geçersiz override olduðu için imza ve geri dönüþ türü deðiþikliði kabul etmiyor.
};
int main() {
	//Base mybase; syntax error abstract olduðu için: en az 1 pure virtual function var
}*/

/*
* 4
class Car {
public:
	virtual void start() = 0;
	virtual void run(int x = 10) = 0;

};

class BMW : public Car {
private:
	void start()override
	{
		cout << "BMW start\n";
	}
	void run(int x = 20)override
	{
		cout << "BMW run\nx = "<<x<<"\n";
	}
};
void car_game(Car* car)   //virtual dispatch  Car & car da virtual dispatch   Car car: not virtual dispatch
{
	car->start(); = car->vp[0] :virtual pointer
	car->run(); = car->vp[1] :virtual pointer  //x = 10 Çünkü varsayýlan argüman compile time da elde edilir.

}
int main() {
	car_game(new BMW());  //BMW start
	//access kotrol derleme zamanýnda yapýlmasýndan dolayý; 
	//virtual dispatch le elde edilen base nesnesi türemiþ sýnýfýn pribate bölümüne kesinlikle eriþir
	
}
*/
/*
*Bir sýnýfýn ctor u virtual olamaz.
* sýnýfýn statik üyesi virtual olamaz.
* Global fonksiyon virtual olamaz.
5
class Base {
public:
	Base() {
		//foo(); error: ctor ve destructor içinde base tabande virtual dispatch uygulanamaz.çünkü daha türemiþ sýnýf hayatta deðil:)
	}
	virtual void foo() { cout << "base foo()"; }
};

class Der :public Base {
public:
	void foo() { cout << "Der foo()"; }
};
*/

/*
5
class Car {
public:
	virtual void start() = 0;
	virtual void stop()  = 0;
	virtual void run()   = 0;

};

class BMW: public Car {
public:
	void start()override 
	{
		cout << "BMW start\n";
	}
	void stop()override
	{
		cout << "BMW stop\n";
	}
	void run()override
	{
		cout << "BMW run\n";
	}
};

class Mercedes : public Car {
public:
	void start()override
	{
		cout << "Mercedes start\n";
	}
	void stop()override
	{
		cout << "Mercedes stop\n";
	}
	void run()override
	{
		cout << "Mercedes run\n";
	}
};

class Audi : public Car {
public:
	void start()override
	{
		cout << "Audi start\n";
	}
	void stop()override
	{
		cout << "Audi stop\n";
	}
	void run()override
	{
		cout << "Audi run\n";
	}
};

void car_game(Car* car)   //virtual dispatch  Car & car da virtual dispatch   Car car: not virtual dispatch
{
	car->start();
	car->stop();
	car->run();

}
Car* create_random_car() {
	switch (rand() % 3)
	{
		case 0:	 return new BMW();
		case 1:  return new Mercedes();
		case 2:  return new Audi();
		default: return nullptr;
	}
}

int main()
{
	for (;;) {
		Car * cp = create_random_car();
		car_game(cp);
		(void)getchar();
		delete cp;
	}

}
*/

/*
6
class Der : Base (private inheritance)
struct Der: Base (public inheritance)

*/
class Base {
public:
	void pub_func();
protected:
	void pro_func();
private:
	void pri_func();
};
class Der : private Base { //upcassting implicit conversion yok
public:
	void derfunc()
	{
		pub_func(); //gecerli
		pro_func(); //geçerli
		//pri_func(); //geçersiz
		Der myder;
		Base* base_ptr = &myder;  //geçerli
		Base& base_ref = myder;  //geçerli
	}
};

int main()
{
	Der myder;
	//myder.pri_func();  //geçersiz
	//myder.pro_func();  //geçersiz
	//myder.pub_func();  //geçersiz
	Der myder;
	//Base* base_ptr = &myder;  //geçersiz
	//Base& base_ref = myder;  //geçersiz
}

//Protected inheritance : base class protected bölümü derived class protected bölüme ekleniyor.

//multilevel inheritance: class C: public B, A  (public B, private  A) 
// C de B ve A nýn ortak fonksiyonuna eriþmek istediðinde C de yok ise; ambiguity çünkü B ve A arasýnda öncelik yok.


