#include <iostream>

using namespace std;
/*
template <typename ...Args>   //variadic template
void foo(Args ...params) {
	constexpr auto n1 = sizeof...(Args);
	constexpr auto n2 = sizeof...(params);

	cout << "n1:" << n1 << "\n";
	cout << "n2:" << n2 << "\n";

}

int main() {
	foo();
	foo(1);
	foo(1, 2);
	foo(1, 2, "ali");
}


n1:0
n2:0
n1:1
n2:1
n1:2
n2:2
n1:3
n2:3
*/

template <typename ...T>
void func(T ...args) {
	//foo(args...) = foo(p1, p2, p3, p4);
	//bar(args)... = bar(p1), bar(p2), bar(p3), bar(p4)
}

template <typename T>
void print(const T& r) {
	cout << r << "\n";
}

template <typename T, typename ...Ts>
void print(const T&r, const Ts& ...args) {  //tüm elemanlarý yazan eksiltme tekniði
	print(r);
	print(args...);
}

template <typename ...Ts>
void print2(const Ts& ...args) {  //tüm elemanlarý yazan eksiltme tekniði
	(void)std::initializer_list<int>{(std::cout << args<<" ", 0)...};
}
int main() {
	int x{ 15 };
	double dval{ 3.45 };

	print(x, dval, 9L, "tefoli");  //bu fonksiyonda ilk elemaný T& kapýyor
	print2(x, dval, 9L, "tefoli");  //15 3.45 9 tefoli
	/*
	15
	3.45
	9
	tefoli
	*/
}