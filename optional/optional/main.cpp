#include <iostream>
#include <optional>
#include <string>

using namespace std;
/*void func(optional<string> os) {}
//c++17
//optional:Any instance of optional<T> at any given point in time either contains a value or does not contain a value.
int main() {
	optional<int> i;

	cout << sizeof i << '\n'; //8

	optional<string> x;
	cout << (x ? "dolu" : "bos"); //bos
	x = "mustafa";
	cout << (x ? "dolu" : "bos"); //dolu
	if (x.has_value()) {
		cout << "dolu\n"; //dolu
	}
	x = nullopt; //bos hale geldi
	cout << (x ? "dolu" : "bos"); //bos
	x = "talha";
	// perator u bos ise undefined behaviour
	cout << *x << '\n';  //talha
	//value(): boþ ise exception throw ediyor.
	cout << x.value() << '\n'; ////talha
	x.value() = "tefo"; //value(): reference dondurdugu icin atama yapilabilir
	cout<<x.value_or("tevfik"); //string dondurur. reference degil
	cout << x.value() << '\n'; ////tefo

	//reset():nesne bosaltilir
	x.reset();//1
	x = {};//2
	x = nullopt;//3
	cout << x.value() << '\n'; ////bos oldugu icin exception throw etti
	func({});//valid: default contructor ý var
	func(nullopt);
	//emplace():optional nesnesinin hayatýný bitirir.yeni nesnenin hayatý baþlar.
}
*/

#include <optional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

int main()
{
	auto op1 = std::make_optional<std::vector<char>>({ 'a','b','c' });
	std::cout << "op1: ";
	for (char c : op1.value()) {
		std::cout << c << ",";
	}
	auto op2 = std::make_optional<std::vector<int>>(5, 2);
	std::cout << "\nop2: ";
	for (int i : *op2) {
		std::cout << i << ",";
	}
	std::string str{ "hello world" };
	auto op3 = std::make_optional<std::string>(std::move(str));
	cout << "\nop3: " << quoted(op3.value_or("empty value")) << '\n';
	cout << "str: " << std::quoted(str) << '\n';
	 
	//Output
	//op1: a, b, c,
	//op2 : 2, 2, 2, 2, 2,
	//op3 : "hello world"
	//str : ""
}