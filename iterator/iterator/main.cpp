#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
//category aþaðý gittikçe özelliði artýyor.
/*
iterator category:
input operator output oterator
forward iterator
bidirectional iterator: list/multiset , map/ multimap
random access iterator: vector, deque, string, array
*/
/*
int main() {
	list <int> mylist(100);

	auto iter1 = mylist.begin();
	auto iter2 = mylist.begin();

	++iter1;
	auto b = iter1 == iter2;
	auto b2 = iter1 != iter2;
	--iter1;
	//iter2 - iter1; illegal
	///iter1 + 3;//illegal
	vector<int> myvec(100);

	auto iter3 = myvec.begin();
	auto iter4 = myvec.begin();

	iter4 - iter3; //legal
	iter3 + 1; // legal value category

}
*/
/*
using iter_t = std::vector<int>::iterator;
using iter_t2 = std::list<int>::iterator;

int main() {
	cout<<typeid(iter_t::iterator_category).name() << endl; //struct std::random_access_iterator_tag
	cout<<typeid(iter_t2::iterator_category).name() << endl; //struct std::bidirectional_iterator_tag
}*/


//std::copy :herhangi bir containerdan containere copy edilebilen class

/*
int main() {
	int a[10]{ 1, 2, 3,4 , 5 ,6 , 7, 8, 9 };
	int b[10];

	auto x = std::copy(std::begin(a), std::end(a), b);  //a b ye kopyalandý.x in türü int *
	cout<< b[6] << "\n";

	list<int> ilist{100};

	//sort(ilist.begin(), ilist.end());//hata:parametre random iterator parametresi
	cout << distance(ilist.begin(), ilist.end());  //2 iterator arasýndaki farký gösterir.
}
*/
/*
aþaðýdaki iþlemlerin her bireri u.b oluþturur.
(yani exception throw etmez.)
	1)sizden range isteyen bir algoritmaya geçerli bir range verilmeli.Aksi halde undefined behaviour.
	2)asla end konumunu dereference etmiycez.Tanýmsýz davranýþ
	3)boþ bir iteratorun begin ini dereference etmiyoruz.
*/

/*predicate: bool döndüren bir callable
unary predicate: tek parametreli
binary predicate: çift parametreli
*/

//find_if: belirli koþulu saðlayan ilk adresi döndürür.3.parametre function parameter
/*
template <typename InIter, typename Pred>
InIter FindIf(InIter first, InIter last, Pred f) {
	while (first != last) {
		if (f(*first))	return first;

		++first;
	}
	return last;
}

	int main() {
	vector<string> svec{"tevfik", "osman", "uluocak", "betus", "dogan", "sakarya", "otokar"};
	auto iter = min_element(svec.begin(), svec.end());
	auto iter2 = max_element(svec.begin(), svec.end());
	auto iter4 = max_element(svec.rbegin(), svec.rend());

	auto iter3 = minmax_element(svec.begin(), svec.end());
	cout <<"min element:" << * iter << "\n";
	cout << "max element:" << *iter2 << "\n";

	cout << "min element:" << *iter3.first << "max element" << *iter3.second << "\n";
}
*/

/*

int main() {
	vector <int> ivec{30, 15, 45, 60, 20};
	cout<<typeid(ivec.begin()).name() << endl;
	cout<<typeid(ivec.rbegin()).name() << endl;
	//class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int> > >
	//class std::reverse_iterator<class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int> > > >
	auto begin = ivec.rbegin();
	auto end = ivec.rend();

	while (begin != end) {
		cout << *begin++ << " ";  //20 60 45 15 30

	}
}
*/
/*
int main() {
	vector<int> ivec{ 12, 56, 81, 3, 8, 7 };

	vector<int>::iterator iter = ivec.begin();

	iter++;
	*iter = 50;
	vector<int>::const_iterator citer = ivec.begin();

	citer++;
	//*citer = 50; illegal;

	auto citer2 = ivec.cbegin(); //const iterator;
	auto citer3 = ivec.cend(); //const iterator;
}

*/

//stl deki bazý global fonksiyonlar iteatorleri manipule emteye yönelik
/*
advance
distance
next
prev
iter_swap
*/

/*
int main() {
	vector<int> ivec{ 1,5,8,2,4,3,9 };
	auto iter = ivec.begin();
	//iter += 4;	//random-iterator olduðu için kategori legal
	cout << *iter << "\n"; //1
	advance(iter, 2); //8  :iteratorun kendisi artýrýyor. advance parametresi(call by reference iteratorun kendisi deðiþimþ oluyor)
	cout << *iter << "\n";
	advance(iter, -1); //5
	cout << *iter << "\n";

	cout << distance(ivec.begin(), iter) << endl;  //iterator baþtan bir ileride:1
	cout << distance(iter, ivec.begin()) << endl;  //iterator baþtan bir geride:-1

	vector<int> vec{ 1,5,8,2,4,3,9 };
	auto iter2 = vec.begin();
	cout << *iter2 << "\n";
	cout<<*next(iter2, 5)<<"\n"; //next()iter + 5 in adresini döner.iter deðiþmez.
	cout<<*next(iter2, 5)<<"\n"; //next()iter + 5 in adresini döner.iter deðiþmez.
	cout << *iter2 << "\n";

	cout<<*prev(vec.end(), 2) << "\n";//3 //sondan 2 önce(yani 1 önce yi)in adresini döner.iter deðiþmez.
	cout << *iter2 << "\n";//1

	auto iter_1 = vec.begin();
	auto iter_2 = vec.end() - 1;

	cout << *iter_1 << "  " << *iter_2 << "\n";  //1 9
	swap(iter_1, iter_2);
	cout << *iter_1 << "  " << *iter_2 << "\n";  //9 1
}
*/

/*
Algoritmalar(Parametre deðiþkenleri iterator olan fonksiyonlar), o iterator konumlarýndaki nesnelerini deðiþtirebilirlwe ancak 
asla ve asla nesne ekleyemez ve silemezler.
*/


int main() {

	vector<int> ivec{1, 2, 3, 4, 5, 6};
	vector<int> dest;
	copy(ivec.begin(), ivec.end(), back_inserter(dest));  // dest doldurdu
	

}