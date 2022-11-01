#include <iostream>

using namespace std;
/*
class Myclass {
public:
	operator int() const { //typecast operator overload
		return 1;
	}
};
int main()
{
	Myclass m;
	int x = m;
	cout << x << endl; //1

	if (m) {
		cout << "implicit type conversion = user defined conversion + standart conversion  " << endl;;
	}
}*/

/*
class Myclass {
public:
	explicit operator int() const { //typecast operator overload
		return 1;
	}
};
int main()
{
	Myclass m;
	// int x = m;  invalid:implicit d�n���me izin verilmiyor.
	int x = static_cast<int>(m);  //typecast overload oldu�u i�in yap�l�yor
	cout << x << endl; //1

	
}

*/
/*
class Myclass {
public:
	operator bool() const { //typecast operator overload
		return 1;
	}
};
int main()
{
	Myclass m;
	int x = m;
	cout << x << endl; //1

	if (m) {
		cout << "implicit type conversion = user defined conversion + standart conversion  " << endl;;
	}
}*/
/*
class Myclass {
public:
	explicit operator bool() const { //typecast operator overload
		return 1;
	}
};
int main()
{
	Myclass m;
	//int x = m; //explicit oldu�u i�in class -int d�n���m� yok.
	bool x = m; //legal: explicit boola �zel ge�erli
	if (m) {  //bool typecast operator overloading oldu�u i�in direk bool a implicit d�n���m var. 
		cout << "bool direk donusum var  " << endl;;
	}
}*/

class Myclass {
public:
	operator int() const { //typecast operator overload
		return 1;
	}
};
int main()
{
	Myclass m1 , m2;
	int x = m1 + m2;  //m1 ve m2 int e �evrildi;

	auto x2 = m1;  //x2 t�r�: Myclass
	auto x3 = +m1;  //x2 t�r�: int(typecast ten dolay�)
	cout << x << endl; //2

}