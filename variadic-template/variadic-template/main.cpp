#include <iostream>
using namespace std;
//variadic template:birden fazla parametre girmemizi saðlayan araç seti

template <typename ...Args> //variadic template (ismi args olmak zorunda deðil.Args konvansiyonel)
class Myclass {};

template <typename ...Args> //variadic template args:template parameter pack
void foo(Args&... params) {
	//params l value reference,
}

template <typename ...Args>
void func(Args... params) {
	//parametre türleri referans olmayan türden
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