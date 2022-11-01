#include <iostream>

/*
using namespace std;
// local object variable, automatic storage
class Myclass {
public:
	Myclass() {
		cout << "constructor:"<<this << endl;
	}

	~Myclass() {
		cout << "destructor:" <<this<< endl;
	}
};

void foo() {
	 Myclass m;
	 cout <<"object address" << &m << endl;
}


int main()
{
	cout << "main basladi:"<<endl;
	for(int i = 0; i < 10; i++)
		foo();
	cout << "main sona eriyor"<<endl;


	return 0;

}
*/
/*
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
constructor:000000539CAFFB64
object address000000539CAFFB64
destructor:000000539CAFFB64
main sona eriyor
*/
/*
using namespace std;
// static local object variable, static storage
class Myclass {
public:
	Myclass() {
		cout << "constructor:" << this << endl;
	}

	~Myclass() {
		cout << "destructor:" << this << endl;
	}
};

void foo() {
	static Myclass m;
	cout << "object address" << &m << endl;
}


int main()
{
	cout << "main basladi:" << endl;
	for (int i = 0; i < 10; i++)
		foo();
	cout << "main sona eriyor" << endl;


	return 0;

}
*/

/*
main basladi:
constructor:00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
object address00007FF617040180
main sona eriyor
destructor:00007FF617040180
*/
/*
using namespace std;
//  global object variable, static storage
class Myclass {
public:
	Myclass() {
		cout << "constructor:" << this << endl;
	}

	~Myclass() {
		cout << "destructor:" << this << endl;
	}
};
Myclass m;

int main()
{
	cout << "main basladi:" << endl;
	cout << "main sona eriyor" << endl;


	return 0;

}
*/
/*
constructor:00007FF60F570180
main basladi:
main sona eriyor
destructor:00007FF60F570180
*/

using namespace std;
/*
//  dynamic object variable, dynamic storage. When called delete(); called destructor.
class Myclass {
public:
	int x = 5;
	mutable int y = 10;
	Myclass() {
		cout << "constructor:" << this << endl;
	}

	~Myclass() {
		cout << "destructor:" << this << endl;
	}
	void  foo()const {
		y = 10;
		//x = 5;   non mutable const fonksiyonda çaðýrýlamaz 
	}
};

int main()
{

	cout << "main basladi:" << endl;
	Myclass * p = new Myclass; // = auto p  

	delete p;
	cout << "main devam ediyor" << endl;


	return 0;

}
*/
/*
main basladi :
constructor:00000288CF0A5560
destructor : 00000288CF0A5560
main devam ediyor
*/

/*
class Myclass {
public:
	int x = 5;
	mutable int y = 10;
	Myclass() {
		cout << "constructor:" << this << endl;
	}

	~Myclass() {
		cout << "destructor:" << this << endl;
	}
	void  foo()const {
		y = 10;
		//x = 5;   non mutable const fonksiyonda çaðýrýlamaz 
	}
};

int main()
{
	
	//Aþaðýdaki sýnýf türünden * & tür deðiþkenleri sýnýfýn deðiþkenleri olamaz.
	//O yüzden aþaðýdaki iki satýrda da ctor ve destor tabi ki çaðýrýlmaz.
	
	Myclass m;
	Myclass* ptr = &m;
	Myclass& r   = m;

	return 0;
}
*/
/*
constructor:00000056C82FF818
destructor : 00000056C82FF818
*/


/*
class Myclass {
public:
	int x = 5;
	mutable int y = 10;
	Myclass() {
		cout << "constructor:" << this << endl;
	}

	~Myclass() {
		cout << "destructor:" << this << endl;
	}
	void  foo()const {
		y = 10;
		//x = 5;   non mutable const fonksiyonda çaðýrýlamaz 
	}
};

int main()
{
	Myclass a[5]; //dizi boyutu kadar nesne çaðýrýlýr.

	return 0;
}
*/
/*
constructor:0000003A2D6FFC78
constructor:0000003A2D6FFC80
constructor:0000003A2D6FFC88
constructor:0000003A2D6FFC90
constructor:0000003A2D6FFC98
destructor:0000003A2D6FFC98
destructor:0000003A2D6FFC90
destructor:0000003A2D6FFC88
destructor:0000003A2D6FFC80
destructor:0000003A2D6FFC78
*/

class Myclass {
public:
	int x = 5;
	mutable int y = 10;
	Myclass() {
		cout << "constructor:" << this << endl;
	}
	

	~Myclass() {
		cout << "destructor:" << this << endl;
	}
	void  foo()const {
		y = 10;
		//x = 5;   non mutable const fonksiyonda çaðýrýlamaz 
	}
};

int main()
{ //default ctor çaðýran nesne bildirimleri
	Myclass m; //default init
	Myclass n{}; //value initialization
	
	//Myclass n2(); bu fonksiyon bildirimi. default ctor çaðýrmaz.
	return 0;
}

/*
	special member functions: derleyici kodunu görmediði zaman otomatik iþlediði kodlardýr.
	1)Default ctor
	2)Desctor
	3)copy ctor
	4)move ctor
	5)copy assignment
	6)move assignment
*/

