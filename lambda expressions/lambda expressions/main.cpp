#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
[](int x, int y) mutable{}
[](int x, int y) constexpr{}
[](int x, int y) noexcept{}
[](int x, int y)-> int{}
*/

//lambda expr: create temporary object
/*
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
*/
/*

class Functor {
public:
	int operator()(int x)const { return x * 2; }
};
int main() {
	vector<int> vec{ 1, 2, 4, 56, 77, 68, 96, 57 };
	vector<int> destvec(vec.size());

	copy_if(vec.begin(), vec.end(), destvec.begin(), [](int x) {return x % 2 == 0; });
	for (auto iter = destvec.begin(); iter != destvec.end(); ++iter) {
		cout << *iter << " ";  //2 4 56 68 96 0 0 0
	}

	cout << "\n";
	vector<int> ivec(vec.size());
	transform(vec.begin(), vec.end(), ivec.begin(), [](int x) {return x * x; });
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter << " ";  //1 4 16 3136 5929 4624 9216 3249  transform():istediðim stl i alýp istediðim dönüþüme çevirdim(lambda ifadesi ile)
	}
	cout << "\n";
	transform(vec.begin(), vec.end(), ivec.begin(), Functor{}); //Functor class  transform()1. overload
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter << " ";  //2 4 8 112 154 136 192 114  transform():istediðim stl i alýp istediðim dönüþüme çevirdim(Functor class ile)
	}

	cout << "\n";
	vector<string> name{ "tefvik", "betus", "yahya", "erdem" };
	vector<string> surname{ "uluocak", "dogan", "saglam", "emin" };

	vector<string> dest(4);

	transform(name.begin(), name.end(), surname.begin(), back_inserter(dest),
		[](std::string s1, std::string s2) {return s1 + ' ' + s2; });
	for (auto iter = dest.begin(); iter != dest.end(); ++iter) {
		cout << *iter << " ";  //    tefvik uluocak betus dogan yahya saglam erdem emin  transform():2.overload	}

}

*/

//for_each()
/*
int main() {
	vector <string> s{ "tevfik", "osman", "uluocak", "betus", "dogan" };
	for_each(s.begin(), s.end(), [](std::string& s1) {  cout << s1 + "can"<<"\n"; });  //son parametre callable
	//tevfikcan
	//osmancan
	//uluocakcan
	//betuscan
	//dogancan
}
*/

	//[]capture close: Classtaki private data memberýnýn o deðerle initialize olduðunu ifade eder.
/*
int main() {
	int x = 15, y = 22;
	cout<<[](int a, int b) {return a * b; }(x, y); //330 IIFE(Immediately Invoked Function Expression)
	cout << "\n";
	int a = 10;
	auto f = [a]()mutable {a *= 20; };  //copy capture
	f();
	cout << a << "\n";

	int b = 10;
	auto f1 = [&b]() {b *= 20; }; //reference capture //calllable mutable olmasýna gerek yok.Çünkü const üye fonksiyon referans deðiþkenleri deðiþtirebilir.
	f1();  
	cout << b << "\n";   //200  //f1() çaðýrýldýðý için b deðiþti.

	auto f2 = [=]() {}; //copy capture all valriable
	auto f2 = [&]() {}; //reference capture all variable
	auto f2 = [&, x]() {}; //reference capture all variable and x copy capture
	auto f2 = [=, &x]() {}; //all variable copy capture and x reference capture
	//capture close :yerel deðiþken ve statik olmamalý.
}*/


int main() {
	auto f = [](int a) {return a * a; };
	int x{ 10 };
	int(*fp) (int) = f; //f stateless olduðu için legal
	auto f2 = [x](int a) {return a * x; };
	//int(*fp2) (int) = f2	; //f stateful  olduðu için legal deðil
	auto f3 = [](int a) {return a * a; }; //f closure type
	auto f4 = +[](int a) {return a * a; }; //f function pointer
	cout<<typeid(f3).name() << "\n";
	cout<<typeid(f4).name() << "\n";
	//class `int __cdecl main(void)'::`2'::<lambda_3>
	//int(__cdecl*)(int)

	auto f5 = [](auto x) {return x * x; }; 
	
}