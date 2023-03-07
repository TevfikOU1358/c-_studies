#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>

using namespace std;

/*
class Myclass {
public:
	Myclass() {
		cout << "this adress:" << this << '\n';
	}
};

void CustomDeleter(Myclass* p) {
	cout << "adress:\t" << p << '\n';
	delete p;
}
int main() {
	{
		std::unique_ptr<Myclass, void(*)(Myclass*)> up{ new Myclass, &CustomDeleter };//ayni adres
	}
	{
		std::unique_ptr<Myclass, void(*)(Myclass*)> up{ new Myclass, CustomDeleter }; //ayni adres
	}
}*/
/*
//type_traits:compile time bir türün hakkında bilgi sahibi olmmamıza yardımcı olur.
template <typename T>
struct IsInteger
{
	static constexpr bool value = false;
};


template <typename T>
struct IsPointer
{
	static constexpr bool value = false;
};

template <typename T>
struct IsPointer<T*>
{
	static constexpr bool value = true;
};

template <>
struct IsInteger<int> //explicit specizition
{
	static constexpr bool value = true;
};

template <typename T>
void func(T x) {
	//T bir tam sayi turu mu
	cout << IsInteger<T>::value << '\n';
	cout << IsPointer<T>::value << '\n';
}
/*

int main() {

	int x{};
	double d{};
	func(x);  //1
	func(d);  //0
	func(&x);  //is pointer


	//--------------------

	integral_constant<int, 5>::type{} << '\n'; //1.template parametresi :1. template parametresi type:int gecici nesne olusturuldu
	cout << integral_constant<int, 5>::value << '\n'; //2.template parametresi :5
	cout << integral_constant<int, 5>{}() << '\n'; //fonksiyon çağrı operatoru value döner :5

	cout << boolalpha << is_integral_v<int> << '\n'; //true; v:value
	cout << boolalpha << is_pointer_v< int* > << '\n'; //true; v:value


	//is_class
	class Myclass {};
	struct Mystruct {};
	enum Myenum { on, off, hold };
	cout << is_class<Myclass>::value << '\n';  //true
	cout << is_class<Mystruct>::value << '\n'; //true
	cout << is_class<Myenum>::value << '\n'; //false
	cout << is_class_v<Myenum> << '\n'; //false  yukarıdaki ile aynı(variable template)
}
*/
/*

//Variable Template
template< typename T>
constexpr static bool IsPointer_v = std::is_pointer<T>::value;

template <typename T>
void foo(T){
	static_assert(std::is_same<int, T>::value);
}

//is same i implemente edelim.

template <typename T, typename U>
struct IsSame : std::false_type{};

template <typename T>
struct IsSame<T, T> :std::true_type {};

template <typename T, typename U>
constexpr  bool IsSame_v = IsSame<T, U>::value;


int main() {
	cout << IsPointer_v<int> << '\n';	//bizim implemente ettigimiz :false
	cout << std::is_pointer_v<int> << '\n'; //standart:  false
	
	cout << std::true_type{}<<'\n'; //1
	//static_assert
	foo(12);
	//foo(1.2); //compile time da error vericek parametre int değil
	
	//is_same
	
	cout<<IsSame_v<int, int><<'\n';  //biz yazdik
	
	cout<<is_same_v<int, int><<'\n';

}

template<typename T>
using PTR = T*;  //ptr bir tür dönüştürme şablonu

template <typename T>
void func(T x, typename std::type_identity<T>::type y){}  //2. parametre 1.parametrenin türünü alır.
int main() {
	int a{};
	PTR<int> x = &a;

	func(1, 1.2);
	func(1.5, 'a');

}
*/


	//eğer mesele derleyiciye compile time da kod seçtirmek ise:
	//sfinae
	//static_Assert
	//concept
	//tag dispatch
/*
using A = std::vector<int>;
int main() {
	A::value_type x{};
	A::pointer ptr{ &x };

}*/

//assert:doğrulama
//static_assert
//dynamic_assert :assert()

//constexpr if:Daha çok fonksiyon şablonlarında kullanılıyor.compile time if
//if bloğu doğru ise sadece o blok derlenir.
/*
template <typename T>
void foo(T x) {
	if constexpr(is_pointer_v<T>) {  // bu blok doğruysa if bloğu derlenicek.
		return *x;
	}
	else{} //yanlışsa sadece bu blok derlenicek.
}
template <typename T>
void foo2() {
	if constexpr (is_pointer_v<T>) {  // bu blok doğruysa if bloğu derlenicek.
		return *x;
	}
	else {} //yanlışsa sadece bu blok derlenicek.
}
#include <iostream>
*/
template<typename T>
void f(T s)
{
	std::cout << s << '\n';
}

int main()
{
	f<double>(1); // instantiates and calls f<double>(double)
	f<>('a');     // instantiates and calls f<char>(char)
	f(7);         // instantiates and calls f<int>(int)
	void (*pf)(std::string) = f; // instantiates f<string>(string)
}
