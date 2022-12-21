#include <iostream>
using namespace std;
//variadic template:birden fazla parametre girmemizi sa�layan ara� seti

template <typename ...Args> //variadic template (ismi args olmak zorunda de�il.Args konvansiyonel)
class Myclass {};

template <typename ...Args> //variadic template args:template parameter pack
void foo(Args&... params) {
	//params l value reference,
}

template <typename ...Args>
void func(Args... params) {
	//parametre t�rleri referans olmayan t�rden
	constexpr auto n = sizeof ...(Args);
	cout << "n:" << n << "\n";

}
int main() {
	/*

	func();
	func(1);
	func(1, 2);
	func(1, 2, "tefoli13");
	
*/}