#include <iostream>
#include <array>
#include <string>

using namespace std;

template<typename T, std::size_t size>
struct Array {
	T a[size];
};
// array-decay: dizi ismi doðrudan kullanýldýðýnda, dizi , dizinin ilk elemanýnýn adresine dönüþüyor.
//container larda c dizisi tutamazsýnnýz. ama containerlarda array tutabilirsiniz.


template<typename T, std::size_t size>
std::ostream& operator<<(std::ostream& os, const std::array<T, size> ax) {
	if (ax.empty())
		return os << "[]";
	for (auto val : ax) {
		os << val << ',';
	}
	return os << '\n';
}
int main(){
	array<double, 10> ax{1, 4, 5, 6,2 , 5,6 , 7};
	cout << ax << '\n';  //1,4,5,6,2,5,6,7,0,0
	
	//front() & back():return referencei
	ax.front()++; 
	ax.back()++;
	cout << ax << '\n';// 2, 4, 5, 6, 2, 5, 6, 7, 0, 1,
	array<array<double, 10>,10> x{}; //[10[10] luk dizi:(array in ilk template parametresinin default constructable olmasý gerekir.
	auto ar2 = ax; //copy ctor

	array<string, 5>as{"tevfik uluocak", "betul dogan", "recep erdogan", "tayyip gulec", "nese ergin"};

	cout << as<<'\n';  //tevfik uluocak,betul dogan,recep erdogan,tayyip gulec,nese ergin,

	//c dizisinden std::array dönüþümü
	int ar[]{ 1,2, 3, 4, 5, 6, 7 };
	array<int, 7> x2;
	copy(begin(ar), end(ar), begin(x2));
	cout << x2 << '\n';  //1,2,3,4,5,6,7

}