#include <iostream>

using namespace std;
/*
class Myclass {
public:
	Myclass(int x) {
		cout << "x = " << x << endl;
	}
	Myclass(int x, int y) {
		cout << "x = " << x <<"   int y = "<<y<< endl;
	}
};

int main()
{
	Myclass m1(10);  //direct init
	Myclass m2{ 8 }; //direct list init
	Myclass m3 = 6 ; //copy init

	Myclass m4(5, 10);
	Myclass m5{ 15, 20 };
	Myclass m6 = { 25, 30 };

	return 0;
}
*/
/*
x = 10
x = 8
x = 6
x = 5   int y = 10
x = 15   int y = 20
x = 25   int y = 30
*/
//ctor init. list: sýnýfýn statik olmayan data memberlarý için ilk deðer verme yöntemidir.
class Myclass {
public:
	//Myclass() :mx(), my(); hata:ana blok olmak zorunda
	Myclass() :my{}, mx()
	{
		cout << "mx:" << mx <<"\n" << "my:" << my <<"\nmz:"<<mz<< endl;
	}
	int mx;
	int my;
	int mz; //default initialzie edildi
	//int &r ::hata :reference default init edilemez.

};

int main()
{
   
	Myclass m;
	return 0;
}

/*
mx:5
my:2
mz:-858993460
*/