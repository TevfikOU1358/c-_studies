#include <iostream>
#include <tuple>
#include <string>

using namespace std;
//tuple runtime da elemanlarý artamaz veya eksilemez.
/*
int main() {
	tuple<int, string, double>tx{13, "tefoli13", 5.4};  //variadic template

	cout << get<0>(tx) << '\n';  //13
	cout << get<1>(tx) << '\n';  //tefoli13
	cout << get<2>(tx) << '\n';  //5.4

	auto tx2 = make_tuple(13, "tefoli13", 5.4 );
	cout << typeid(tx2).name() << '\n';  //class std::tuple<int,char const * __ptr64,double>
	
	auto tx3 = make_tuple(13, "tefoli13"s, 5.4 );
	cout << typeid(tx3).name() << '\n';  //class std::tuple<int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,double>

	tuple x{ 1, 1.2f, 1.3, "ahmet" }; // CTAD: since C++17
	get<0>(x)++; //reference
	cout << get<0>(x) << '\n';  //2
	cout << get<char * __ptr64>(x) << '\n';  //ahmet

}
*/
/*
std::tuple<int, double, float, string>foo() {
	return { 12, 41.5, 1.2f, "abdullah" };
}


int main() {

	int i{};
	double d{};
	float f{};
	string name{};

	//1
	tuple<int&, double&, float&, string&> tx{ i, d, f, name };

	get<0>(tx) = 58;
	get<3>(tx) = "tevfik";

	cout << i << '\n';  //58
	cout << name << '\n'; //tevfik

	//2:tie()
	tie(i, d, f, name) = foo();  //tie(): return with tuple reference val
	cout << i << '\n';  //12
	cout << name << '\n'; //abdullah

	//3:structure binding
	auto [age, temperature, value, name2] = foo();

	cout << temperature << '\n';  //41.5
}*/

//structure binding öge sayýsý eþit olmak zorunda

int main() {

	int a[] = { 1, 3, 5, 7 };

	auto &[x, y, z, t] = a;  //reference
	x = 45;

	cout << a[0] << '\n';  //45

	tuple d1{ 1,12,1996 };
	tuple d2{ 15,1,1997 };


	cout<<boolalpha<< (d1 < d2) << '\n';  //true :ilk parametreden baþlýyarak karþýlaþtýrma yapar.Tarih karþýlaþtýrmalarý için yapýlabilir.

	int q{ 70 };
	int w{ 80 };

	tie(w, q) = tuple{ q, w };  //swap iþlemi
	cout << q << '\n';  //80
}