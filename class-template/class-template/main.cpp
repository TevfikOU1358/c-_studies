#include <iostream>
#include <vector>

//class template is not a class.
//vector string bir class deðil , class template
//template kod çaðýrýlmaz ise object kodda yer almaz.
using namespace std;
/*
template <typename T>
class Myclass {
public:
	Myclass<T>() { //= Myclass () ayný template sýnýfý tanýmý içerisinde olduðu için
		cout<<"type t is:"<< typeid(T).name()<<"\n"; //int
		cout<<"type class is:"<< typeid(Myclass).name()<<"\n"; //Myclass<int>

	}
	Myclass(T){}
	bool operator==(const Myclass& r);

};

template <typename T>
bool operator ==(const Myclass<T>& r1, const Myclass<T>& r2) { return false; }

template<typename T>
bool Myclass<T>::operator==(const Myclass& r) //class operator function parametreye <specialization> zorunlu deðil ama return type da zorunlu
{
	return false;
}
int main() {
	Myclass<int> m1; 
	Myclass m{ 10 };  //CTAD: template T parametreli ctor olduðu için legal
	//m1 == m2;
}
//template class lar ve üyeleri çaðýrýlmadýkça object dosyada yer almazlar.
*/

/*
template <typename T>
class Myclass {
public:
	void foo(T&&);//R value reference 
	template<typename U>
	void func(U&&);//Universal reference = forwarding reference
};

int main() {
	Myclass<int> i1;
	Myclass<double> d1;
	//i1 = d1;//error farklý class atanýyor
}
*/

//pair
/*//class Myclass {};
int main() {
	pair <int, int> x;  //default initalize
	cout << x.first << endl;
	cout << x.second << endl;
	pair <int, Myclass> x2;//Myclass default initalize

	pair x3{ 1, 1.2 }; //CTAD özelliðinden dolayý specitializationa gerek yok //since C++17

	x3 = x; //legal pair özelliði template member özelliði sayesinde tabi ki türler dönüþtürülebilir olmalý.

}
*/

/*
template <typename T, typename U>
std::ostream&	operator<<(std::ostream& os, const std::pair<T, U>& p) {
	return os << '[' << p.first << "," << p.second << ']';
}
int main() {
	pair p{ 1,2 };
	cout << p << "\n";
	pair <string, string> p2{"tevfik osman", "uluocak"};
	cout << p2 << "\n";  //[tevfik osman,uluocak]
	
}
*/
/*
template<typename T>
using ptr = T*;

template<typename T>
using ipvec = std::vector<std::pair<T, T>>;
int main() {

	int x = 80;
	ptr<int> p = &x;
	ipvec<string> vec;
}
*/
//explicit specitialization için primary template tanýmý veya bildirimi olmak zorundadýr.
/*
template <typename T>
void func(T) {
	cout << "primary specialization\n";
}

template <>
void func(int) {
	cout << "fully specialization\n"; 
}


template <typename T>
class Myclass {
public:
	Myclass() {
	cout << "primary specialization\n";
	}
};

template <>
class Myclass<int> {
public:
	Myclass(){
	cout << "fully specialization\n"; 
		
	}
};
int main() {
	func("assa");
	func(2.3);
	func(2.3f);
	func(2);

	Myclass<string>();
	Myclass<float>();
	Myclass<double>();
	Myclass<int>();


		primary specialization
		primary specialization
		primary specialization
		fully specialization
		primary specialization
		primary specialization
		primary specialization
		fully specialization
}		*/


/*
template <int N>
struct Tef : Tef<N - 1>
{
	Tef() {
		cout << N << " ";
	}

};

template<>
struct Tef<0>{};

int main() {
	Tef<100> x; //print (1,100)
}
*/

//Default Template Arguments
//1)deduction
//2)explicit template argument
//3)default template argument
/*
template <typename T = int>
struct Myclass{
	Myclass() {
		cout<<typeid(T).name()<<"\n";
}

};

int main() {
	Myclass<double> x1;  //double
	Myclass<int> x2;	//int
	Myclass x3;	//int

}
*/
/*
//perfect forwarding(argumanlarý ferfect forward etme: L value arg -> L value param, const L value arg -> const L value param, R value arg -> R value param)
struct Myclass{};
void func(Myclass&) {
	cout << "L value reference\n";
}

void func(const Myclass&) {
	cout << "const L value reference\n";
}

void func(Myclass&&) {
	cout << "R value reference\n";
}
template <typename T>
void call_func(T&& x) {  //perfect forwarding
	func(std::forward<T>(x));
}

int main() {
	Myclass m1;
	const Myclass m2;
	func(m1);
	call_func(m1);

	func(m2);
	call_func(m2);

	func(Myclass{});
	call_func(Myclass{});
}
*/
