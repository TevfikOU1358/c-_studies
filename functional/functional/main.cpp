#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class ReferenceWrapper {
public:
	ReferenceWrapper(T& r) : mp(&r){}
	operator T& () { return *mp; }
	T& get()
	{
		return *mp;
	}
	ReferenceWrapper& operator=(T& t) {
		mp = &t;
	}

private:
	T* mp;
};
/*
int main() {

	cout << plus<int>{}(10, 20)<<'\n';  //30
	cout << plus<>{}(10, 20)<<'\n';  //30
	cout << plus{}(10, 20) << '\n';  //30  (since C++17)

	vector<int> ivec;
	sort(ivec.begin(), ivec.end(), greater{});  //(since C++17)


	//referebce wrapper:(referans sarmalayýcýsý)
	//1)rebindable: baþka bir nesneye baðlanabiliyor.
	//2)stl de containerlarýn referance açýlýmý yok.

	int x = 10;
	int y = 92;
	reference_wrapper<int> r1 = x;  //l value wxpression olmak zorunda

	cout << r1 << '\n'; //10
	cout << r1.operator int &() << '\n'; //10

	reference_wrapper r2{ y };  //CTAD since C++17
	cout << r2 << '\n';  //92

	//operator=()

	r2 = x;  //reference x e baðlandý. y baðlantýsý koptu.
	cout << y << '\n';  //92
}*/
/*
template <typename Func>
void func(Func f){

}

int foo(int) { cout << "foo()\n"; return 0; }

using strref = std::reference_wrapper<std::string>;
int main() {
	string s1{ "anil" }, s2{ "Murat" }, s3{ "necati" };
	vector<strref> vec{ s1, s2, s3 };

	for (const auto& r : vec) {
		cout << r.get() << '\n';  //anil Murat necati
	}
	vec.begin()->get() += "can";

	cout << s1 << "\n";  //anilcan

	//func(cout) :iostream nesnesi non copyiable: refereancla dönülmeli
	func(ref(cout));
	reference_wrapper<int(int)> r = foo;  //fonksiyona baðlanabilir
	}
*/

//ostream_iterator
/*
* 
int main() {
	vector<int> ivec{ 1,3, 5, 6 ,7, 8, 9 };
	vector<string> svec{ "ali", "fatma", "ayse", "haci", "nurullah" };

	copy(ivec.begin(), ivec.end(), std::ostream_iterator<int>{cout});  //1356789
	copy(ivec.begin(), ivec.end(), std::ostream_iterator<int>{cout, ","});  //1,3,5,6,7,8,9,
	copy(svec.begin(), svec.end(), std::ostream_iterator<string>{cout, "\t"});  //ali     fatma   ayse    haci    nurullah
	
	cout << '\n';
	copy_if(svec.begin(), svec.end(), std::ostream_iterator<string>{cout, " "},
		[](const string& s) {return s.length() == 4; });  //ayse haci(vectordeki stringlerin uzunluðu 4 olan stringle çýkýþ akýmýna yazdýrýldý.)

	ostream_iterator<string>os{ cout };

	os = "tevfik osman uluocak\n"; //tevfik osman uluocak
}
*/

//std::bind (in <fuctional>)
/*
int func(int x, int y) {

	return x * y;
}

void print(std::ostream& os, int a, int b) {
	os << "\n[" << a << "," << b << "]\n";
}

int main() {
	int x{ 20 };
	auto f = bind(func, 10, x); //xin kopyasý gönderildiði için hiçbir zaman x in deðeri deðiþmez.Ancak ve ancak x ref(x) yapýlarak deðiþebilir.

	auto val = f();
	cout << val << '\n';  //200

	auto f1 = bind(func, 10, placeholders::_1);
	auto val2 = f1(3); //2.parametre deðeri:3
	cout << val2 << '\n';  //30

	using namespace placeholders;
	auto f3 = bind(func, _1,_2);

	cout << f3(5, 6); //func(5, 6)  30
	using namespace std::placeholders;

	//bind(print, cout, _1, _2) (10,25); sentaks hatasý :cout non copyable
	bind(print, ref(cout), _1, _2) (10,25);  //bind temporary object oluþturur deðerleri (10,25)

}
struct Functor {
	int operator()(int a, int b, int c) {
		return a * b * c;
	}
};

int main() {
	using namespace std::placeholders;

	auto f = bind(Functor{}, _1, _1, _1);  //bind 1.param: class object
	cout<<f(5)<<'\n'; //5*5*5 =125

	auto f2 = bind([](int x, int y) {return x + y; }, _1, _2);  //bind 1.param: class object

	cout << f2(10, 20)<<'\n'; //10 + 20
}

*/

//std::function
/*
struct Functor {

	int operator()(int x) {
		cout << "Functor operator()\n";
		return x;
	};
};

std::function<int(int)> bar(int x) {  //return type ya std::function olmalý ya da auto olmalý
	return [](int x) {return x * x; };
}


int foo(int x) { return x; }
int main(){
	//1
	function<int(int)> f{ foo };
	cout << f(10)<<'\n'; //10
	//2
	f = Functor{};
	f(25);//  Functor operator()
	//3
	f = [](int x) {return x * x; };
	cout<<f(12)<<'\n'; //144

	//4
	f = bar(5);
}*/
template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	cout << "[";
	for (auto iter : vec) {
		cout << iter<<",";
	}
	cout << "]\n";
	return os;
}
/*
  //not_fn:callable ýn geri dönüþ türünün deðilini verir
int main() {
	vector<int> ivec{ 10 ,2, 13, 4, 55, 46, 27, 38 };
	copy_if(ivec.begin(), ivec.end(), ostream_iterator<int>{cout, ","},
			not_fn([](int x) {return x % 2 == 0; })); //bölümü 2 ye eþit olmayan deðerleri yazdýrdý

	vector<string> svec{ "ali", "ayse", "fatma", "hayriye", "sýdýka", "gul" };
	copy_if(svec.begin(), svec.end(), ostream_iterator<string>{cout, ","},  //ali,ayse,gul
		not_fn([](const std::string& s) {return s.length() > 4; })); //uzunluðu 4 ten buyuk olmayan deðerleri yazdýrdý
}*/

	//mem_fn: oblhect member function cagýrýyor
class Myclass {
public:
	void func() {
		cout << "Myclass::func() this = " << this << '\n';
	}
};

int main() {

	Myclass m;
	cout << "&m:" << &m <<'\n';
	auto f = mem_fn(&Myclass::func);
	f(m);
	//&m:000000818DDFFB14
	//Myclass::func() this = 000000818DDFFB14
}