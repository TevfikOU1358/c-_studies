#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;



template<typename Key, typename Value, typename Comp = std::less<Key>, typename Alloc = std::allocator<std::pair<Key, Value>>>
void print(const map<Key, Value, Comp, Alloc>& mymap) {
	cout << "[\n";
	for (const auto& i : mymap)
	{
		cout <<"key:"<<i.first<<" value:"<<i.second<<"\n";
	}
	cout << "]\n";
}

template<typename T>
void print(const vector<T>& myvector) {
	cout << "[";
	for (const auto& i : myvector)
	{
		cout << i<< " ";
	}
	cout << "]\n";
}

template<typename T, typename U>    //map in pair olan iteratorleri için inserter fonksiyonu
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
	return os<<"["<<p.first<<", "<<p.second<<"]";
}

/*
int main() {
	map<int, string,greater<>> imap{ {1,"tevfik" }, { 2, "betus"}, {3, "uluocak"}};
	print(imap);
	//[
	//	key:3 value : uluocak
	//	key : 2 value : betus
	//	key : 1 value : tevfik
	//]
	map<int, string> imap2{ {1,"tevfik" }, { 2, "betus"}, {3, "uluocak"}};
	print(imap2);
	//[
	//	key:1 value : tevfik
	//	key : 2 value : betus
	//	key : 3 value : uluocak
	//]
	for (auto& iter : imap2) {  
		cout << iter << "\n";  //pair inserter function
	}
	for (auto& [key, value] : imap2) {
		cout << key<<", " << value << "\n";  
	}

	//eklerken pair ile; ararken key ile yapılır
	pair<int, string> px{ 5, "seyfettin" };
	imap2.insert(px);
	imap2.emplace(7, "zakire");

	print(imap2);
	//[
	//	key:1 value : tevfik
	//	key : 2 value : betus
	//	key : 3 value : uluocak
	//	key : 5 value : seyfettin
	//	key : 7 value : zakire
	//]
	
	
	
	//yeni usül key i değiştirme

	if (auto iter = imap2.find(7); iter != imap2.end()) {
		cout << "value is:" << iter->second <<"\n";  //value is:zakire
		auto handle = imap2.extract(iter);
		handle.key() = 15;
		handle.mapped() = "melahat";

		imap2.insert(std::move(handle));
	}
	print(imap2);
	//[
	//	key:1 value : tevfik
	//	key : 2 value : betus
	//	key : 3 value : uluocak
	//	key : 5 value : seyfettin
	//	key : 15 value : melahat
	//]


}
*/

/*

//mapin köşeli parantez oprator fonksiyonu
int main() {
	map<int, string> imap{ {1,"tevfik" }, { 2, "betus"}, {3, "uluocak"}, {6, "hasan"}, {9,"ahmet"},{4, "elif"}, {21,"tahsin"}};


	cout << imap[3] << "\n";  //uluocak
	imap[3] = "erdem";
	print(imap); 

	//mapi value ya göre sıralama

	vector<pair<int, string>> pvec{ imap.begin(), imap.end()};

	sort(pvec.begin(), pvec.end(), [](const auto& p1, const auto& p2) {return p1.second > p2.second; }); //value ları büyükten küçüğe doru sıraladım

	for (auto& iter : pvec) {
		cout << iter;  //[1, tevfik][21, tahsin][6, hasan][3, erdem][4, elif][2, betus][9, ahmet]  
	}

}
*/

//STL ALGORİTHMS
int main() {
	set<string> x{"ahmet", "mehmet", "ali", "veli", "ramazan","bilal"};
	set<string> y{ "recep", "bilal", "tekin", "ahmet", "ayse", "nazli" };
	vector <string> svec;
	set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(svec));  //ortak küme
	print(svec); //[ahmet bilal ]
	
	svec.erase(svec.begin(), svec.end()); 
	set_symmetric_difference(x.begin(), x.end(), y.begin(), y.end(), back_inserter(svec));  ////ortak elmanlar hariç tamamı
	
	print(svec);//[ali ay■e mehmet nazli ramazan recep tekin veli ]

	//merge

	vector<string> males{ "ali", "veli", "ahmet", "mehmet", "tahsin" };
	vector<string> females{"ayse","nese","zehra","sena"};
	sort(males.begin(), males.end());
	sort(females.begin(), females.end());
	vector <string> destvec;

	merge(males.begin(), males.end(), females.begin(), females.end(), back_inserter(destvec));
	print(destvec);  //[ahmet ali ayse mehmet nese sena tahsin veli zehra ]
}