#include <iostream>
#include <any>

using namespace std;
//any:herhangi türden bir deðiþken tutar.C deki void* gibi
int main() {
	any x = 10;
	cout << any_cast<int>(x) << '\n'; // 10
	
	x = 4.3;
	cout << any_cast<double>(x) << '\n'; // 4.3

	x = "tevfik"s;
	cout << any_cast<string>(x) << '\n'; // tevfik

	try
	{
		std::cout << std::any_cast<float>(x) << '\n';
	}
	catch (const std::bad_any_cast& e)
	{
		std::cout << e.what() << '\n'; //Bad any_cast
	}
	if (auto ptr = any_cast<string>(&x)) { //adres girilirse pointer döner. Bos ise nullptr doner.
		cout << "any deger tuuyor:" << *ptr << '\n';  //any deger tuuyor:tevfik
	}
	else {
		cout << "any deðer tutmuyor nullptr:\n";
	}

	//fabrika fonksiyonu
	auto y = make_any<int>(12);
	
	//type():member function :returns the typeid of the contained value
	cout << y.type().name() << '\n'; //int
	
	//has_value(): checks if object holds a value
	any a = "betuss"s;
	if (a.has_value())
	{
		std::cout << a.type().name() << ": " << std::any_cast<string>(a) << '\n';//class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >: betuss
	}

	//reset()
	//a.reset();
	a = {}; //same previous line
	if (!a.has_value())
	{
		std::cout << "no value\n"; //no value
	}
	struct Myclass{
		Myclass(int, int, int){}

	};
	any a1{ in_place_type<Myclass>,1,1,1 };
	auto a2 = make_any<Myclass>(1, 1, 1);
	auto a3 = Myclass{ 2,2,2 };
	auto a4 = Myclass(2,2,2);

}