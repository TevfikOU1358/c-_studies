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
	// int x = m;  invalid:implicit dönüþüme izin verilmiyor.
	int x = static_cast<int>(m);  //typecast overload olduðu için yapýlýyor
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
	//int x = m; //explicit olduðu için class -int dönüþümü yok.
	bool x = m; //legal: explicit boola özel geçerli
	if (m) {  //bool typecast operator overloading olduðu için direk bool a implicit dönüþüm var. 
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
	int x = m1 + m2;  //m1 ve m2 int e çevrildi;

	auto x2 = m1;  //x2 türü: Myclass
	auto x3 = +m1;  //x2 türü: int(typecast ten dolayý)
	cout << x << endl; //2

}