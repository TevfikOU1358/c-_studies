#include <iostream>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

//associative containers: binary search tree
//set:bir tane ayný key buulnabilirken multisette birden fazla bulunabilir
//template <typename Key, typename Comp = std::less<Key>, typename A = std::allocator<Key>>;

template<typename T>
void print(set<T> myset){
	cout << "[";
	for (auto ii : myset)
	{
		cout << " " << ii;
	}
	cout << "]\n";
}

template<typename T>
void print(multiset<T> myset) {
	cout << "[";
	for (auto ii : myset)
	{
		cout << " " << ii;
	}
	cout << "]\n";
}
/*
int main() {
	set<int> myset{ 5, 1, 9, 7, 3, 12 };  //bidirectional iterator default olarak less{}
	vector<int> ivec{ 5, 1, 9, 7, 3, 12, 2, 13, 314, 14, 33, 22, 22 ,11, 23 , 21 };
	print(myset); //[ 1 3 5 7 9 12]

	set<int> iset(ivec.begin(), ivec.end());  //bidirectional iterator default olarak less{}
	print(iset);  //[ 1 2 3 5 7 9 11 12 13 14 21 22 23 33 314]
	//insert()
	set<string> sset{ "ali", "ayse", "hayriye" };
	auto p = sset.insert("fatma"); //pair eklendi  

	if (p.second) { cout << "deger eklendi\n"; }  //de­ger eklendi
	//find()
	if (sset.find("hayriye") != sset.end()) {
		cout << "distance:" << distance(sset.begin(), sset.find("hayriye")) << "\n";  //distance:3
		cout << "deger bulundu\n";  //deger bulundu
	}
	//count()
	if (sset.count("tefo") == 0) { cout << "bulunamadi\n"; }  //bulunamadi
	//erase()
	sset.erase("ayse");
	print(sset);  //[ ali fatma hayriye]

	if (auto [iter, succeed] = sset.insert("tefo"); succeed) {
		cout << "ekldendi\n";  //eklendi.
	}
	set<string> myset2;
	myset2.insert("tefoli13");


	//3 tane arama yöntemi

	if (myset2.contains("tefoli13")) { cout << "evet iceriyor\n"; }  //1


	if (auto iter = myset2.find("tefoli13"); iter != myset2.end()) { //2
		cout << "bulundu\n";
	}

	if (myset2.count("tefoli13")) {  //3
		cout << "bulundu\n";
	}
	
}*/
//lower_bound
//upper_bound
//equal_range

int main() {
	multiset<int> myset{ 1, 2, 3, 4, 4, 2, 3, 1, 3, 2, 0, 0, 3, 2, 1, 2,3 ,0, 2, 1, 2,3, 4, 2 };
	print(myset);

	auto iter_lower = myset.lower_bound(3);//15
	cout <<"index:"<< distance(myset.begin(), iter_lower)<< "\n";
	auto iter_upper = myset.upper_bound(3);
	cout <<"index:"<< distance(myset.begin(), iter_upper)<< "\n";
	
	cout<<"equal range:"<<distance(iter_lower, iter_upper) << "\n";  //6

	auto [iter_lower2, iter_upper2] = myset.equal_range(1);
}