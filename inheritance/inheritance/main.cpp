#include <iostream>
#include <cstdio>
using namespace std;
/*
1)Name Lookup
2)Context Control
3)Access Control
*/
/*E�er.veya->operat�r�n�n sa��nda kalan isim, 
e�er sol taraf operand� t�remi� s�n�f nesnesi ise �nce t�remi� s�n�fta aran�r.
bulunamaz ise taban s�n�fta aran�r.

Der -> Base (upcasting) �rt�l� d�n���m var
Der myder;
Base *ptr = &der; ge�erli
Base &r  = der;   ge�erli
Base mybase = der ge�erli ama tehlikeli(object slicing)
Base -> Der (downcasting) �rt�l� d�n���m yok.
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
	der.func(); // �nce Der classta arad� bulamad�. Sonra Base classta arad� buldu.
	//der.p_x;  //error: public yolla kal�t�m edilen t�remi� s�n�f , taban s�n�f�n protected b�l�m�n� private b�l�m�ne al�r.Ve instance yoluyla eri�emez.

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
	void func(int ) {}//ge�erli
	//void func(int, int)override; ge�ersiz override oldu�u i�in imza ve geri d�n�� t�r� de�i�ikli�i kabul etmiyor.
};
int main() {
	//Base mybase; syntax error abstract oldu�u i�in: en az 1 pure virtual function var
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
	car->run(); = car->vp[1] :virtual pointer  //x = 10 ��nk� varsay�lan arg�man compile time da elde edilir.

}
int main() {
	car_game(new BMW());  //BMW start
	//access kotrol derleme zaman�nda yap�lmas�ndan dolay�; 
	//virtual dispatch le elde edilen base nesnesi t�remi� s�n�f�n pribate b�l�m�ne kesinlikle eri�ir
	
}
*/
/*
*Bir s�n�f�n ctor u virtual olamaz.
* s�n�f�n statik �yesi virtual olamaz.
* Global fonksiyon virtual olamaz.
5
class Base {
public:
	Base() {
		//foo(); error: ctor ve destructor i�inde base tabande virtual dispatch uygulanamaz.��nk� daha t�remi� s�n�f hayatta de�il:)
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
		pro_func(); //ge�erli
		//pri_func(); //ge�ersiz
		Der myder;
		Base* base_ptr = &myder;  //ge�erli
		Base& base_ref = myder;  //ge�erli
	}
};

int main()
{
	Der myder;
	//myder.pri_func();  //ge�ersiz
	//myder.pro_func();  //ge�ersiz
	//myder.pub_func();  //ge�ersiz
	Der myder;
	//Base* base_ptr = &myder;  //ge�ersiz
	//Base& base_ref = myder;  //ge�ersiz
}

//Protected inheritance : base class protected b�l�m� derived class protected b�l�me ekleniyor.

//multilevel inheritance: class C: public B, A  (public B, private  A) 
// C de B ve A n�n ortak fonksiyonuna eri�mek istedi�inde C de yok ise; ambiguity ��nk� B ve A aras�nda �ncelik yok.


