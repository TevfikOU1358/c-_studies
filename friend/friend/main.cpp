#include <iostream>

using namespace std;

class Myclass {
	int x;
	int y;

	friend  void func() { //func() member function deðildir. global bir fonksiyondur
		Myclass m;
		m.x = 5; //friend fonksiyon olduðu için private member a eriþim var.
	}
	 friend void foo();
};

void foo() { //friend fundction olduðu için sýnýfýn tüm üyelerine eriþebilir.
	Myclass m;
	m.x = 10;
}

int main() {
	//B sýnýfý A nýn friendi olsa C de B nin friend i olsa C A nýn friend i olamaz.
	// b sýnýfý A nýn friendi olsa A sýnýfý B nin friend i olamaz.


}