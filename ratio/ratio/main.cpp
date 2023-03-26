#include <iostream>
#include <ratio>

//The class template std::ratio provides compile-time rational arithmetic support
using namespace std;
int main() {
	//num ve den 2 adte static constxpr member
	cout << ratio<3, 17>::num << '\n';  //pay:3
	cout << ratio<3, 17>::den << '\n';	//payda:17
	cout << ratio<3>::den << '\n';	//payda:1

	cout << ratio<32, 18>::num << '\n';	//payda:16
	cout << ratio<32, 18>::den << '\n';	//payda:9


	using r1 = ratio < 3, 5>;
	using r2 = ratio < 7, 5>;
	using result = typename ratio_add<r1, r2>::type;
	cout<<result::num<<'\n'; //2
	cout<<result::den<<'\n'; //1

	//type():ratio nun kendisi
	cout << ratio<3, 5>::type::type::type::type::den << '\n';//5

	//int x = 5;
	//int y = 5;
	//ratio<x, y>; //deðiþkenler constexpr olmalý
	constexpr int x = 5;
	constexpr int y = 5;
	ratio<x, y>;  //legal
}