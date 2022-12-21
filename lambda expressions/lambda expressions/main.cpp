#include <iostream>

using namespace std;
/*
[](int x, int y) mutable{}
[](int x, int y) constexpr{}
[](int x, int y) noexcept{}
[](int x, int y)-> int{}
*/

//lambda expr: create temporaru object
int main() {
	auto f = [](){return 5; };
	cout << f() << endl;  //5
	
	auto f1 = []() ->int {return 5; };
	cout << f1() << endl;  //5

	auto f2 = [] {return 5; }; //parametre yok böyle de yazýlabilir.
	cout << f2() << endl;  //5

	auto f3{[](int x) {return x * x; }};
	cout << f3(8) << endl;//64

	cout << typeid(f).name() << endl; //class `int __cdecl main(void)'::`2'::<lambda_1>
	cout << typeid(f1).name() << endl; //class `int __cdecl main(void)'::`2'::<lambda_2>
	auto f4 = f3; // legal: copy ctor mevcut
	
	decltype(f3)f5{}; //illegal default ctor yok.  //legal 2020 standartlarý ile
}