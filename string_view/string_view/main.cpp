#include <iostream>
#include <string_view> //string nesnesi icerisinde var

using namespace std;
/*template <typename T>
void func(T x){}
int main() {
	string str(100'000, 'A');

	auto s = str.substr(20'000, 15'000);

	string_view sv;
	cout << sv.size()<<'\n';  //0
	cout << sv.length()<<'\n';  //0
	cout << boolalpha<<sv.empty()<<'\n'; //true

	string s2{"tevfik uluocak"};
	string_view sv2{s2};
	//ayni adresi gönderir
	cout << static_cast<const void*>(s2.data())<<'\n';  //0000004C1CCFF6E0
	cout << static_cast<const void*>(sv2.data())<<'\n'; //0000004C1CCFF6E0

	string str3{ "betus" };
	string_view sv3{ str3 };

	str3[1] = 'i';

	cout << sv3 << '\n'; //bitus
	str3 += "tefoli13"; 
	cout << sv3 << '\n'; //sv3 dangling pointer eski pointerý gösteriyor pointer deðisti bitus
	cout << str3;

	func("ahmet");  //const char*
	func("ahmet"s); //string
	func("ahmet"sv); //string_view
}*/

int main() {
	string str{ "tevfik osman uluocak" };
	string_view sv{ str };
	cout << sv << '\n';

	sv.remove_prefix(6);
	cout << sv << '\n';  // osman uluocak
	sv.remove_suffix(7);
	cout << sv << '\n'; //uluocak
}