#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include <functional>

using namespace std;
/*
//Random Number Engines
template<typename T>
void func(T x) {
	cout << "sizeof(x):" << sizeof x << '\n';
}
int main() {
	cout<<typeid(mt19937).name()<<'\n';  //class std::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253>
	mt19937 eng{ 724876u };
	//derleyici deðiþse de olusan sayilar asla degismez.ancak dagilim siniflari degisir.
	for (int i{}; i < 10; i++) {
		cout << eng() << ' ';  //class std::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253>
	}
	//default_random_engine eng2 = mt19937 eng2;;

	cout << "sizeof(mt19937):" << sizeof mt19937;  //sizeof:5000
	(void)eng(); // functor class operator(): return generated value
	//kopyalamanýn ciddi maliyeti var.paramtere olarak kullanma 5000 byte
	
	func(eng); //sizeof(x) : 5000
	func(ref(eng)); //reference wrapper: kopyalamayý onler.sizeof(x) : 8

	//seed(): seed deðerini deðiþtirir
	eng.seed(); //default seed value
	eng.seed(12352); //

	//discard():engine 99999 iþlem yapmýs pozisyona gelir
	mt19937 eng1;
	eng1.discard(999'999);
	cout<<eng1()<<'\n'; // 1 milyonuncu islem sonucu:1063718465
	//min():return min generated value (static)
	//max():return max generated value (static)
	cout << mt19937::min()<<'\n';
	cout << mt19937::max()<<'\n';

	//operator<< operaator>> for serialization

	stringstream ss;
	ss << eng1; //operator<<
	mt19937 x;
	ss >> x; //operator>>

	if (eng1 == x) { //operator==
		cout << "ikisi de ayni state de\n"; //ikisi de ayni state
	}
	else {
		cout << "ikisi de farkli state de\n";

	}

	std::random_device rd; //her defasýnda farklý bir deðer retir
	//mt19937 eng2{ rd() }; //scope leakege var
	mt19937 eng2{ random_device{}()}; //temprary object lusturuldu
	for (int i{}; i < 10; i++) {
		cout << eng2() << ' ';  //her acildiginda farkli bir deger 
	} 
}
*/
/*
//Uniform int Distrubitions

int main() {
	//uniform_int_distribution uniform_int ten kalýtým yollal edilmistir.

	uniform_int<int> d1{1, 10}; 
	uniform_int<> d2{1, 10}; //template argument deduction
	uniform_int d3{1, 10}; //CTAD


	uniform_int<> dist; //default int()template argument
	mt19937 eng;
	for (int i{}; i < 10; i++) {
		cout << dist(eng) << ' ';  //2 2 4 5 4 1 9 5 8 3
	}
	cout << '\n';
	uniform_int<> dist1{-2, 7};
	for (int i{}; i < 20; i++) {
		cout << dist1(eng) << ' ';  //3 3 -2 4 7 -2 7 2 5 4 7 7 1 7 4 4 4 1 -2 -1
	}
	//param()
	auto params = dist1.param();
	cout << params.a() << '\n'; //-2
	cout << params.b() << '\n'; // 7
	dist1.param(dist.param()); //dist1 , distin state ini aldi.

}
*/
/*
* 
#include <iomanip>
//Uniform Real Distributions
int main() {
	uniform_real dist{ 0.13, 0.99 };
	mt19937 eng;
	for (int i{}; i < 10; i++) {
		cout <<setprecision(3)<< dist(eng) << ' ';  //0.247 0.848 0.963 0.32 0.395 0.601 0.292 0.984 0.987 0.962
	}
}
*/
/*
#include <iomanip>
int main() {
// Normal Distributions 
	 normal_distribution<double> dist{10, 0.3};  //ortalama 10 standart sapma 0.3
	mt19937 eng;
	for (int i{}; i < 10; i++) {
		cout <<setprecision(3)<<dist(eng) << ' ';  //9.96 10 9.44 10.1 9.94 10 9.75 10.1 10.3 10
	}
	//Bernoulli Distribution
	int true_count{};
	int false_count{};
	bernoulli_distribution distb{ 0.5 };//not template
	for (int i{}; i < 1'0000'000; i++) {
		if (distb(eng)) {
			true_count++;
		}
		else {
			false_count++;
		}
	}
	cout << true_count << '\n'; //5003167
	cout << false_count << '\n';//4996833

	discrete_distribution<int> dist{ 0.1, 0.3, 0.5, 0.1, 0.4 }; //bütün parametreler aðýrlýk
}
*/
/*
#include <algorithm>
int main() {
	const char* pdays[] = { "pazartesi", "sali", "carsamba", "persemnbe", "cuma", "cumartesi", "pazar" };
	mt19937 eng;
	shuffle(begin(pdays), end(pdays), eng); //hep ayni yere dondurucek

	for (auto p : pdays) {
		cout << p << '\t'; //cuma    pazartesi       persemnbe       sali    cumartesi       carsamba        pazar
	}
	string name{ "tevfik uluocak" };
	//shuffle():karmalaam yapar
	shuffle(begin(name), end(name), eng); //hep ayni yere dondurucek
	cout << name << '\n';  //tkfcuolviue ak

	unsigned int a[100];
	generate(begin(a), end(a), eng);//kopyalama semantigi
	generate(begin(a), end(a), ref(eng));//kopyalama semantigi
}
*/
template <typename T>
ostream& operator<<(ostream& os, vector<T> ivec) {
	os << '[';
	for (auto i : ivec) {
		os << i << ' ';
	}
	os << ']';
	return os;
}
#include <algorithm> 
int main() {  //30 tane random sayiyi vectore atan program
	mt19937 eng{ random_device{}() };
	uniform_int dist{ 1000, 1200 };
	vector<int> ivec(30);
	generate(ivec.begin(), ivec.end(), [&] {return dist(eng); });

	cout << ivec;  // [1007 1197 1085 1076 1145 1082 1158 1014 1197 1192 1088 1135 1063 1182 1172 1182 1169 1151 1179 1079 1178 1061 1062 1172 1005 1130 1079 1127 1147 1055 ]
}

