#include <iostream>

using namespace std;

class Myclass {
	int x;
	int y;

	friend  void func() { //func() member function de�ildir. global bir fonksiyondur
		Myclass m;
		m.x = 5; //friend fonksiyon oldu�u i�in private member a eri�im var.
	}
	 friend void foo();
};

void foo() { //friend fundction oldu�u i�in s�n�f�n t�m �yelerine eri�ebilir.
	Myclass m;
	m.x = 10;
}

int main() {
	//B s�n�f� A n�n friendi olsa C de B nin friend i olsa C A n�n friend i olamaz.
	// b s�n�f� A n�n friendi olsa A s�n�f� B nin friend i olamaz.


}