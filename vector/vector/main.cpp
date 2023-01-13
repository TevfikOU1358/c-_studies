#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <initializer_list>

using namespace std;

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
	{
		os << " " << *ii;
	}
	os << "]";
	return os;
}
//vector: dinamik bir veri yap�s�,contigious(ard���k),sondan ekleme ve sondan silme i�lemleri constant time da
//allocation new operatoru ile yap�l�r.Heap ten yer.
/*
namespace std {
	template <typename T, typename A = std::allocator<T>>  //allocator new fonksiyonu heap ten �a��r�r
		class vector{};
}*/
/*
class Tef {
public:
	Tef() { cout << "Tef ctor\n"; }
	Tef(std::initializer_list<int>) { cout << "initializer_list ctor"; }
};
void foo(int, int, int, int);

int main() {
	vector<int> ivec; //default ctor
	cout << ivec.size() << "\n";  //0

	cout << boolalpha;
	cout << ivec.empty()<<"\n"; //true

	vector<int> ivec2(10); //1)size_T parametreli ctor
	cout << ivec2.size() << "\n";  //10
	vector<Tef> tvec(10); //2)size_T parametreli ctor 10 tane tef ctor �a��r�ld�.

	vector<int> ivec3(10, 5); //3)size_T parametreli ve her biri 5 olan ctor
	for (auto s : ivec3) {
		cout << s; //5555555555
	}
	cout << "\n";
	
	//4)copy ctor	vector(const vector&)
	vector<int> xvec = ivec;
	vector<int> xvec1{ ivec };
	vector<int> xvec2(ivec);
	auto x = ivec;
	auto x2(ivec);
	auto x3{ ivec };

	//5) move ctor vector (vector&&)
	auto m_x = move(ivec3);
	cout << ivec3.size() << "\n";  //0 :kayna�� �al�nd�

	//move i�lemi initialize yap�l�rken de�il; kullan�l�rken kayna�� �al�n�r.

	//6) range ctor
	list<string> slist{ "tevfik", "osman", "uluocak", "betul", "dogan" };
	list<const char*> slist2{ "tevfik", "osman", "uluocak", "betul", "dogan" };

	vector<string> svec(slist.begin(), slist.end());  //iteratorleri ayn� de�il
	vector<string> svec2(slist2.begin(), slist2.end());//t�rleri ayn� olmak zorunda de�il


	//initializer_list: dizinin ba�lang�� ve biti� adreslerini tutar.Diziyi tutmaz.
	std::initializer_list<int> l{ 1, 3, 5, 7, 9, 11 }; //stack
	std::initializer_list<int> l1{ 1}; //stack

	cout << sizeof(l) << "\n"; //16
	cout << sizeof(l1) << "\n"; //16
	auto a{ 1 }; //a int
	auto a2 = { 1 }; //a2: initializer_list
	auto iter = l.begin();
	//*iter = 45; //sentaks error :initializer list const elemanlar� de�i�tirlemez.
	auto l3 = l1; //adresler kopyalan�r.

	cout << boolalpha << (l3.begin() == l1.begin()) << "\n";  //truw
	foo(10, 20, 40, 60);  //10 20 40 60

	//7) vector initializer_list parametreli ctor

	vector<int> iv{ 1,2 ,3 ,4,5,6 };

	Tef t{1}; //initializer_list ctor

	vector<double> dvec1(10); //size � 10 , b�t�n de�erlerii 0 olan vector
	vector<double> dvec2{10}; //size � 1 , de�peri 10 olan vector
	vector<double> dvec3(10, 2); //size � 10 , b�t�n de�erlerii 2 olan vector
	vector<double> dvec4{10, 2 }; //size � 2 , de�erler 10 ve 2 olan vector
}

void foo(int a, int b, int c, int d) {
	for (auto x : { a, b, c, d }) {
		cout << x << " ";
	}

}
*/

//Access functions
/*
int main() {
	//size capacity e e�it oldu�unda capacity 1.5 kat�na ��kar.
	//reserve() : pe�in pe�in ba�ta capasity i ay�r�r. reallocationa gerek kalmaz.
	//capacity eleman sildi�imizde k���lmez.
	//capacity nin size a oranla b�z�lmesini istersek shrink_to_fit() �a��r�lmal�d�r. Otomatik �a��r�lmaz.

	//[] operator fonksiyonu elemanlara ula��r. Ge�ersiz indis girildi�inde exception throw etmez.U.B
	//at() member fonksiyonu ayn� i�i yapar. Tek fark exception throw eder.
	vector<string> svec{"tevfik","osman", "uluocak", "betus","dogan"};
	for (int i{}; i < svec.size(); i++) {  //tevfik osman uluocak betus dogan   
		cout << svec[i] << " ";
	}
	cout << "\n";
	cout << svec << " ";
	svec.front() = "ali";  //ilk elemana rferans d�nd�r�yor.
	svec.back() += "gul";  //son elemana referns d�nd�r�yor.
	cout << "\n";
	cout << svec << " ";  //[ ali osman uluocak betus dogangul]

	svec.erase(svec.begin() + 2);
	cout << svec << "\n";
	svec.erase(svec.begin() + 1, svec.end());
	cout << svec << "\n";
}*/
/*
int main() {
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8 };
	cout << ivec << "\n";
	ivec.resize(20); //size � 20 yapar di�er lemanlar 0 olur
	cout << ivec << "\n"; //[ 1 2 3 4 5 6 7 8 0 0 0 0 0 0 0 0 0 0 0 0]
	ivec.resize(25, 5); //size � 25 yapar di�er lemanlar 5 olur
	cout << ivec << "\n"; //[ 1 2 3 4 5 6 7 8 0 0 0 0 0 0 0 0 0 0 0 0 5 5 5 5 5]
	ivec.resize(5); //size � 5 yapar.//k���ltt�k
	cout << ivec << "\n"; //[ 1 2 3 4 5]


	vector<string> svec{ "tevfik", "osman", "uluocak", "betus", "dogan" };
	string s1 = "ctecth";
	svec.push_back(s1);
	cout << svec << "\n"; //[ tevfik osman uluocak betus dogan ctecth]
	cout << s1 << "\n";  //ctecth
	svec.push_back(move(s1)); //overlodad r value reference
	cout << s1 << "\n"; //ta��nd� s1 bo�.

}
*/
/*
int main() {
	vector<int> ivec{ 1, 2, 3, 4, 5, 6 };
	vector<int> s1;
	s1 = ivec;
	cout << s1 << "\n"; //[1 2 3 4 5 6]
	s1 = { 10, 20, 30, 40, 50, 60 };
	cout << s1 << "\n"; //[ 10 20 30 40 50 60]

	//assign
	s1.assign({ 1, 2, 3 });  //initializer_list parameter
	cout << s1 << "\n";   //[ 1 2 3]

	s1.assign(5, 10);  //5 tane 10 atand�
	cout << s1 << "\n";   // [ 10 10 10 10 10]

	list<int> l{ 1, 2,3 ,4,5,6 };
	s1.assign(l.begin(), l.end()); //ayn� t�rden itarator olmak zorunda de�il
	cout << s1 << "\n";   // Range assign  [ 1 2 3 4 5 6]

	//insert(ilk parametre iterator, )	return type;insert edilmi� ilk ��e konumu
	vector<string> svec{ "tevfik", "osman", "uluocak", "betus", "dogan" };

	auto iter = svec.insert(svec.begin() + 2, "alican");
	cout << svec << "\n"; //[tevfik osman alican uluocak betus dogan] 2. konuma alican eklendi.
	cout << *iter << "\n"; //return type;insert edilmi� ilk ��e konumu
	cout << distance(svec.begin(), iter) << "\n"; //2

	svec.insert(svec.begin(), { "alaaddin", "muhiddin", "sebahattin" });
	cout << svec << "\n";//[ alaaddin muhiddin sebahattin tevfik osman alican uluocak betus dogan]

	svec.insert(svec.end(), 3, "tefoli13");
	cout << svec << "\n";//[ alaaddin muhiddin sebahattin tevfik osman alican uluocak betus dogan tefoli13 tefoli13 tefoli13]

	svec.insert(svec.end(), svec.begin(), svec.begin() + 3); //range base for loop
	cout << svec << "\n"; //[ alaaddin muhiddin sebahattin tevfik osman alican uluocak betus dogan tefoli13 tefoli13 tefoli13 alaaddin muhiddin sebahattin]

	//remove
	svec.erase(svec.begin() + 4, svec.end());
	cout << svec << "\n"; //[ alaaddin muhiddin sebahattin tevfik]

	auto iter2 = svec.erase(svec.begin() + 2);
	cout << svec << "\n"; //[ alaaddin muhiddin tevfik]
	cout << *iter2 << "\n"; //silinen ��e 2. konumda (tevfik yaz�l�r)

	//svec.pop_back() = svec.erase(svec.end()) fark� pop_back void d�ner.
	vector<string> svec2{ "tevfik", "osman", "uluocak", "betus", "dogan" };
	while (!svec2.empty()) {
		cout << svec2 << "\n";
		svec2.erase(svec2.begin()); 
	}
	//[tevfik osman uluocak betus dogan]
	//[osman uluocak betus dogan]
	//[uluocak betus dogan]
	//[betus dogan]
	//[dogan]
	
	//clear: hepsini siler
	vector<string> svec3{ "tevfik", "osman", "uluocak", "betus", "dogan" };
	//svec.erase(svec.begin(), svec.end())
	//svec.erase(&svec[0], svec.end())
	//svec.resize(0)
	//svec = {}
	//svec.assign({}) 
	cout << svec3 << "\n"; //[]

}
*/

/*
int main()
{
	vector<string> svec{ "tevfik", "osman", "uluocak", "betus", "dogan" };
	//data(); ilk eleman�n adresini d�nd�r�r.
	cout<<*svec.data()<<"\n";

	auto iter = svec.begin();
	auto citer = svec.cbegin();
	auto riter = svec.rbegin();
	
	cout << typeid(iter).name() << "\n";
	cout << typeid(citer).name() << "\n";
	cout << typeid(riter).name() << "\n";

	//class std::_Vector_iterator
	//class std::_Vector_const_iterator
	//class std::reverse_iterator

	//swap
	vector<string> svec1{ "tevfik", "osman", "uluocak" };
	vector<string> svec2{ "betul", "dogan" };

	svec1.swap(svec2); //= swap(svec1, svec2);

	cout << svec1 << "\n"; //[ betul dogan]
	cout << svec2 << "\n"; //[tevfik osman uluocak]
}*/
/*
//iterator invalidation:bir vector reallocate edildi�inde capasity artt���nda iteratorler invalid olur.
//reallocation dan sonra insert edilen �nceki iterator konumlar� etkilenmez.Sonraki iterat�rler invalid iterator
int main() {
	//emplace():gereksiz yere kopyalama ya da ta��ma yapmadan s�n�f�n ctorunu �a��rarak i�lmee al�r.
	vector<string> svec{ "tevfik", "osman", "uluocak", "betus", "dogan" };
	string s1{ "tefoli" };
	svec.push_back(move(s1));
	cout << "s1:" << s1 << "\n"; //kaynak �al�nd�

}
*/
/*
//spaceship operatoru

class Tef {
public:
	Tef() = default;
	Tef(int){}
	bool operator==(const Tef&)const { return 0; }
	auto operator <=>(const Tef&)const = default;//spaceship default
};
//iterator kar��la�t�rma durumlar�

class Myclass {
public:
	Myclass(string str, int m_x, int m_y) : m_str{str}, x{m_x}, y{m_y}{}
	std::strong_ordering operator<=>(const Myclass& other)const {  //derleyicinin yazd��� spaceship operatoru
		if (auto result = m_str <=> other.m_str; result != 0)	return result;
		if (auto result = x <=> other.x; result != 0)	return result;
		return y <=> other.y;
	}
private:
	std::string m_str;
	int x, y;
};
int main() {
	// <==> threeway comparison
	Tef x, y;
	auto result = x != y;   //C++20 operator== var ise operator!= var
	x == 25;
	25 == x;//C++20 LEGAL
	25 != x;//C++20 LEGAL


	x == y; //spaceship default declared legal

	x != y; //legal
	x > y; //legal
	x <= y; //legal

	int a{}, b{ 58 };
	constexpr auto b1 = 10 <=> 5;  //b:strong ordering

	if (a <=> b == strong_ordering::equal) { cout << "equal\n"; }
	if (a <=> b == 0) { cout << "equal\n"; } //yukar�daki ile ayn�

	Tef x1{ 10 }, x2{ 15 };

	x1 <=> x2;
}
*/
//lexicographical_compare
/*
int main() {
	vector<int> x{1, 2, 3, 4, 5};
	list<int> x2{1, 2, 3, 5, 6};
	cout << std::boolalpha;
	cout << std::lexicographical_compare(x.begin(), x.end(), x2.begin(), x2.end()) << "\n";  //x < y mi true
	cout << size(x) << "\n";  //global generic size
	

}
*/
#include <functional> //matematiksel i�lemlerin yap�ld��� standart generic header
/*
int main() {

	cout<<boolalpha<<equal_to<int>{}(2, 2)<<"\n";
	string s1{ "ahmet" };
	string s2{ "yilmaz" };
	cout << boolalpha << plus<string>{}(s1, s2) << "\n";  //temporary object ahmetyilmaz

	vector<int> ivec{ 1, 6, 89, 56 ,58, 77, 68 };
	list<int> ilist{ 1, 6, 69, 36 ,18, 43, 38 };
	transform(ivec.begin(), ivec.end(), ilist.begin(), ivec.begin(), minus<int>{});
	cout << ivec << "\n";  //[ 0 0 20 20 40 34 30]
	transform(ivec.begin(), ivec.end(), ilist.begin(), ivec.begin(), plus{});  //template argument olmak zorunda de�il
	//�st sat�r ile bire bir ayn�  transform(ivec.begin(), ivec.end(), ilist.begin(), ivec.begin(), [](int x, int y) {return x + y; });  //template argument olmak zorunda de�il
	cout << ivec << "\n";  //[ 1 6 89 56 58 77 68]
}	*/
/*
//1)sort algoritmas�: random access iterator ister.
int main(){

	
	vector<int> vec{ 51, 26, 89, 56 ,18, 77, 68 };
	sort(vec.begin(), vec.end(), greater{}); //== sort(vec.rbegin(), vec.rend())
	cout << vec << "\n";   //[89 77 68 56 51 26 18]
	sort(vec.begin(), vec.end(), less{});
	cout << vec << "\n"; //[18 26 51 56 68 77 89]
	sort(vec.begin(), vec.end(), [](int x, int y) {return x < y; });
	cout << vec << "\n"; // [ 18 26 51 56 68 77 89]

}*/
//2)partial_sort: k�smi arama (daha h�zl�)
/*
int main() {

	vector<int> ivec{ 51, 26, 89, 56 ,18, 77, 68,13, 45, 7, 11, 6, 89 };

	partial_sort(ivec.begin(), ivec.begin() + 5, ivec.end());  //ilk 5 ��e k���kten b�y��e s�raland� di�erleri serbest
	cout << ivec << "\n";   //[ 6 7 11 13 18 89 77 68 56 51 45 26 89]
	partial_sort(ivec.begin(), ivec.begin() + 5, ivec.end(), greater{}); 
	cout << ivec << "\n";   //[ 89 89 77 68 56 6 7 11 13 18 45 26 51]
}
*/

//is_sorted:parametre forward iterator
//is_sorted_until:s�ra nerde bozuldu
/*
int main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	int b[] = { 11, 22, 33, 42, 21, 6, 7 };
	cout << boolalpha << std::is_sorted(begin(a), end(a)) << "\n"; //true

	auto iter = is_sorted_until(begin(b),end(b));//21 say�s�nda bozuldu

	cout << *iter<<"\n";  //21

}*/

//nth_element
//partition
//stable_partition
//partition_point
//partition_copy

/*
int main() {

	//partition
	vector<string> svec{ "tevfik", "osman", "uluocak", "betus", "dogan" , "tarik", "terim" };

	cout << svec << "\n";  //[ tevfik osman uluocak betus dogan tarik terim]
	partition(svec.begin(), svec.end(), [](const string& s) {return s.front() == 't'; });
	cout << svec << "\n";  //[tevfik terim tarik betus dogan uluocak osman]
	auto iter = partition(svec.begin(), svec.end(), [](const string& s) {return s.length() == 5; });  //uzunlu�u 5 olanlar� partition yapt�m
	cout << svec << "\n";  //[ osman terim tarik betus dogan uluocak tevfik]
	cout << *iter << "\n";  //uluocak (partition buradan itibaren ba�lad�)
	cout << distance(svec.begin(), iter) << "\n";  //5 : partition uzunlu�u


	//partition_copy
	vector<string> svec1{ "tevfik", "osman", "uluocak", "betus", "dogan" , "tarik", "terim", "alican", "remzi", "muhammed", "ali"};
	vector<string> prime;
	vector<string> non_prime;
	auto p = partition_copy(svec.begin(), svec.end(), back_inserter(prime), back_inserter(non_prime), [](const string & s) {return s.front() == 't'; });
	cout << prime << "\n";  //[ terim tarik tevfik]
	cout << non_prime << "\n"; //[osman betus dogan uluocak]
	//p bir pair:  std::pair<std::back_insert_iterator<std::vector<std::string>>, std::back_insert_iterator<std::vector<std::string>

	//partition_point:ko�ulu sa�lamayanlar�n ilkinin konumunu buluyorum.
	vector<string> svec2{ "tevfik", "osman", "uluocak", "betus", "dogan" , "tarik", "terim", "alican", "remzi", "muhammed", "ali"};
	auto ip = partition_point(svec2.begin(), svec2.end(), [](const string& s) {return s.length() == 5; });
	cout << *ip << "\n";  //muhammed

	//nth_element
	vector<int> ivec{ 3, 5, 2, 17, 12, 15, 58, 48, 26, 19, 98, 77, 56, 82 };
	nth_element(ivec.begin(), ivec.begin() + 8, ivec.end());// medyan bulmak i�in 2. parametre size �n yar�s� olmak zorunda
	cout << ivec << "\n";  //[ 2 3 5 12 15 17 19 26 48 56 58 77 82 98]
}
*/

//heap: her de�er kendi a�ac�n�n en b�y��� veya en k����� olmal�
//make_heap: vectoru heap hale getiriyor
/*
int main(){
	vector<int> ivec{ 10, 4, 25, 26, 74, 56, 46, 78, 90, 19, 81, 54, 62 };
	cout << ivec << "\n";
	make_heap(ivec.begin(), ivec.end(), greater{}); 
	cout << ivec << "\n";// [4 10 25 26 19 54 46 78 90 74 81 56 62]
	make_heap(ivec.begin(), ivec.end());  
	cout << ivec << "\n";//[ 90 81 62 78 74 56 46 4 26 19 10 54 25]

	sort_heap(ivec.begin(), ivec.end());
	cout << ivec << "\n";// [ 4 10 19 25 26 46 54 56 62 74 78 81 90]
	while (!ivec.empty()) {
		pop_heap(ivec.begin(), ivec.end());  //en b�y��� en sona ald�
		ivec.pop_back();
		cout << ivec << "\n";

	}
	//[10 4 25 26 74 56 46 78 90 19 81 54 62]
	//[90 81 62 78 74 56 46 4 26 19 10 54 25]
	//[81 78 62 26 74 56 46 4 25 19 10 54]
	//[78 74 62 26 54 56 46 4 25 19 10]
	//[74 54 62 26 19 56 46 4 25 10]
	//[62 54 56 26 19 10 46 4 25]
	//[56 54 46 26 19 10 25 4]
	//[54 26 46 4 19 10 25]
	//[46 26 25 4 19 10]
	//[26 19 25 4 10]
	//[25 19 10 4]
	//[19 4 10]
	//[10 4]
	//[4]
	//


	//is_heap
	//is_heap_until
	vector<int> ivec1{ 100, 98, 90, 85, 73, 88, 56, 50, 30, 40, 20, 69 ,72 };
	vector<int> ivec2{ 100, 98, 90, 85, 73, 88, 56, 50, 30, 40, 90, 69 ,72 };

	cout << boolalpha << is_heap(ivec1.begin(), ivec1.end());  //true
	auto iter = is_heap_until(ivec2.begin(), ivec2.end()); //heap olsa idi end konumu d�necekti
	if (iter == ivec2.end()) {
		cout << "is heap\n";
	}
	else {
		cout << *iter << "\n"; //90
	}
}	*/

//silme algoritmalar� 

//remove
//remove_if
//unique:veri yap�s�nda ard���k ayn� yap�lar� tek e indirmek
/*
int main() {

	vector<int> ivec{ 0, 1, 2, 1, 2, 1, 2, 1, 3, 4, 1, 2 ,3 ,1 , 1, 2 , 3, 0, 1, 1, 2, 3, 4,2 ,3 , 0, 2, 1 };
	cout << "ivec size():" << ivec.size() << "\n"; //28
	auto log_end = remove(ivec.begin(), ivec.end(), 2); //fiziki olarak silinmedi. boyut k���lmedi.
	cout << "ivec size():" << ivec.size() << "\n";//28

	cout << ivec << "\n";

	cout << "silinmemis ogeler sayisi:" << distance(ivec.begin(), log_end)<<"\n"; //20
	cout << "silinmis ogeler sayisi:" << distance(log_end, ivec.end())<<"\n"; //8

	//ger�ek silme i�lemi

	ivec.erase(log_end, ivec.end()); 
	cout << "ivec size():" << ivec.size() << "\n"; //28

	cout << ivec << "\n";  //[ 0 1 1 1 1 3 4 1 3 1 1 3 0 1 1 3 4 3 0 1]

	//remove erase idiom
	ivec.erase(remove(ivec.begin(), ivec.end(), 1), ivec.end());
	cout << ivec << "\n";  //[ 0 3 4 3 3 0 3 4 3 0]

	cout<<std::erase(ivec, 3)<<"\n";   //5 tane 3 silindi		global erase() since C++20
	cout << ivec << "\n";  //[ 0 4 0 4 0]


	string str{ "babam ankaradan ardahana yanimiza pazartesi geldi" };

	str.erase(remove(str.begin(), str.end(), 'a'), str.end()); ////remove erase idiom
	cout << str << "\n";  //bbm nkrdn rdhn ynimiz pzrtesi geldi
	
	string str2{ "babam ankaradan ardahana yanimiza pazartesi geldi" };
	erase(str2, 'a');  //global erase since C++20 
	cout << str << "\n"; //bbm nkrdn rdhn ynimiz pzrtesi geldi
	
	//erase_if
	vector<string> svec{ "tevfik", "osman", "uluocak", "betus", "dogan" , "tarik", "terim" };
	erase_if(svec, [](const string& s) {return s.find('t') != std::string::npos; });
	cout << svec<<"\n";  //[ osman uluocak dogan]


	//unique
	vector<int> ivec1{ 0, 1, 2, 1, 2, 1, 2, 1, 3, 4, 1, 2 ,3 ,1 , 1, 2 , 3, 0, 1, 1, 2, 3, 4,2 ,3 , 0, 2, 1 };
	ivec1.erase(unique(ivec1.begin(), ivec1.end()), ivec1.end());
	cout << ivec1 << "\n"; //[ 0 1 2 1 2 1 2 1 3 4 1 2 3 1 2 3 0 1 2 3 4 2 3 0 2 1]
	
	vector<int> ivec2{ 0, 1, 2, 1, 2, 1, 2, 1, 3, 4, 1, 2 ,3 ,1 , 1, 2 , 3, 0, 1, 1, 2, 3, 4,2 ,3 , 0, 2, 1 };
	sort(ivec2.begin(), ivec2.end());
	ivec2.erase(unique(ivec2.begin(), ivec2.end()), ivec2.end());
	cout << ivec2 << "\n";  //[ 0 1 2 3 4]


	vector<string> svec2{ "tevfo", "osman", "uluocak", "betus", "dogan" , "tarik", "terim" };

	svec2.erase(unique(svec2.begin(), svec2.end(), [](const string& s1, const string& s2) {return s1.length() == s2.length(); }), svec2.end());
	cout << svec2 << "\n";  //[ tevfo uluocak betus]   :yanyana ayn� uzunluktaki 2 string silindi.
}
*/

void foo(string&){}
void foo(const string&){} //overloading

void func(char*){}
void func(const char*){}  //overloading

void bar(int){}
//void bar(const int){}  //redecleration call by value

//const * veya & p olmayan parametre bildiriminde kullanma


int main() {
	//replace():belirli de�erleri istedi�in de�er yap

	vector<int> ivec{ 1,1, 2, 1, 3, 4,1, 5 };

	replace(ivec.begin(), ivec.end(),1,8 );
	cout << ivec << "\n"; //[ 8 8 2 8 3 4 8 5]
	
	replace_if(ivec.begin(), ivec.end(), [](int a) {return a % 2 == 1; },19); //

	cout << ivec << "\n"; //[ 8 8 2 8 19 4 8 19]
}