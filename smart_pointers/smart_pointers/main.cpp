#include <iostream>
#include <memory>
#include <vector>


using namespace std;

//smart pointers:pointer gibi kullanýlan kaynaklar. amacý kaynaklarýn yaþamni kontrol eder
// raw pointer mý
//  hangi storage da 
// delete edilmeli mi edilmedi mi
//  ayný kaynraðý gösteren baþka pointerlar var mý
// exception safety
//  sorunlarýný çözer.


//1)unique_ptr:bu kaynaðý gösteren tek pointer ým.exclusive ownership(tek sahiplik stratejisi)
//2)shared_ptr(bir kaynaðý birden fazla pointer gösterir.)
/*class Myclass {
public:
	Myclass() {
		cout << "Myclass ctor\n";
	}
	~Myclass() {
		cout << "Myclass destructor\n";
	}
};
int main() {
	std::unique_ptr <string> uptr; //default init
	std::unique_ptr <string> uptr2{}; //value init
	std::unique_ptr <string> uptr3{nullptr};
	std::unique_ptr <string> uptr4{new string};
	cout << sizeof(uptr) << '\n';  //8
	cout << sizeof(int*) << '\n'; //8 fark yok

	//operator bool()
	cout << boolalpha << uptr.operator bool() << '\n'; //false:pointer boþ
	cout << boolalpha << uptr4.operator bool() << '\n'; //true:pointer dolu
	
	cout << "Main basladi\n";
	{
		std::unique_ptr <Myclass> up {new Myclass}; //default init
	}
	cout << "Main devam ediyor\n";
	//Main basladi
	//Myclass ctor
	//Myclass destructor
	//Main devam ediyor
	
	//* operator:nesneye eriþtirir.
	std::unique_ptr <string> up{new string{"tevfik"}}; 
	cout << *up << '\n'; //tevfik: boþ olsa idi u.b

	Myclass m1;
	//std::unique_ptr <Myclass> up1 {&m1}; //T* parametreli ctor dinamik ömürlü olmak zorunda legal deðil
	
	auto up2 = make_unique<string>("tevfik uluocak");  //up2 now unique_ptr

}*/
/*
using namespace std;
class Person {
public:
	Person() = default;
	Person(std::string name) :m_name{move(name) } {};
	friend std::ostream& operator<<(std::ostream& os, const Person& per) {
		return os << per.m_name<<"\n";
	}
private:
	string m_name;

};

int main() {
	unique_ptr<Person> uptr{ new Person("ahmet selim") };
	//unique_ptr<Person> upx{ uptr }; copy constructor deleted

	cout << "uptr:" << (uptr ? "dolu" : "bos") << '\n';  //dolu
	unique_ptr<Person> upx{move(uptr) };  //move ctor legal  //kaynak upx e verildi. uptr in önceden kaynaðý varsa; o kaynaðý býrakýr
	cout << "uptr:" << (uptr ? "dolu" : "bos") << '\n';  //bos

	//uptr = new Person("tevfik osman"); //sentaks hatasý const T* operator = () yok
	
	//reset()
	
	uptr.reset(new Person("tevfik osman")); //legal
	
	cout << *uptr;  //tevfik osman
	//aþaðýdakilerin hepsi ayný
	uptr.reset(); 
	uptr.reset(nullptr);
	uptr = nullptr;
	uptr = unique_ptr< Person>{};

	//release()
	unique_ptr<Person> uptr2{ new Person("ahmet selim") };

	auto ptr = uptr2.release(); //ahmet selim release oldu

	delete ptr; //ancak bu þekilde ahmet selim hayatý biter

	//get()
	unique_ptr<Person> uptr3{ new Person("ahmet selim") };
	unique_ptr<Person> uptr4{ new Person("fatih sultan") };

	auto p = uptr3.get(); //adresini döndürür.

	//swap()
	cout << *uptr3 << " - " << *uptr4 << '\n'; //ahmet selim - fatih sultan

	uptr3.swap(uptr4);
	cout << *uptr3 << " - " << *uptr4 << '\n';// fatih sultan - ahmet selim
}
*/

//unique_ptr gibi algoritmalar kopyalamaya karþý kapalý olduðu için, copy gibi algoritmalar çalýþmaz. bunun yerine move algoritmasý kullanýlýr.
/*
class Nec {
public:
	Nec() = default;
	Nec(const Nec&) {
		cout << "Nec copy constructor\n";
	}
	Nec(Nec&&) {
		cout << "Nec move constructor\n";
	}
};

//Tef class copy ctor ve copy assigment implicitliy deleted.Cunku veri elemaný non copyable
class Tef {

private:
	std::unique_ptr<string> up;
};

int main() {

	using StringPtr = std::unique_ptr<string>;

	vector<StringPtr> svec;
	svec.emplace_back( new string{ "tevfik osman" });
	svec.emplace_back( new string{ "betusum uluocak" });
	svec.emplace_back( new string{ "yavuz selim" });

	cout << *svec[0] << '\n';  //"tevfik osman"
	vector<StringPtr> destvec(3);

	//copy(svec.begin(), svec.end(), destvec.begin());  //error non copyable unique_ptr
	std::move(svec.begin(), svec.end(), destvec.begin()); //svec kaynaðý destvec e taþýndý

	vector<Nec> myvec(10);
	auto iter = myvec.begin();
	std::move_iterator<vector<Nec>::iterator> miter{ myvec.begin() };
	auto x = *iter;  //Nec copy constructor
	auto y = *miter; //Nec move constructor
	auto z = *make_move_iterator(myvec.begin());  //Nec move constructor make_move_iterator:return move_iterator

	Tef t1;
	//auto t2 = t1; //class ýn non copyable elemani var. O yüzden error
	auto t2 = move(t1); //legal
}*/

/*
*
class Foo {
public:
	Foo() { cout <<"this adresi:"<<this<< "\tFoo constructor\n"; }
	~Foo() { cout << "this adresi:" << this << "\tFoo destructor\n-----------------------------------------\n"; }

};

struct Deleter
{
	void operator()(Foo* fp)const {
	cout << "fp functor class  siliniyor\n";
	delete fp;
	};
};

auto fp = [](Foo *fp) {
	cout << "fp lambda  siliniyor\n";
	delete fp;
};

void fdel(Foo* fp) {
	cout << "fp function pointer  siliniyor\n";
	delete fp;
}

int main() {
	{
		unique_ptr<Foo, decltype(fp)> up{ new Foo{}, fp };
	}
	{
		unique_ptr<Foo, void(*)(Foo*)> up2{ new Foo{}, &fdel };
	}
	{
		unique_ptr<Foo, Deleter> up3{ new Foo{}};
	}
	//this adresi:00000135EFF4DD40    Foo constructor
	//fp lambda  siliniyor
	//this adresi : 00000135EFF4DD40    Foo destructor
	//---------------------------------------- -
	//this adresi : 00000135EFF4DD40    Foo constructor
	//fp function pointer  siliniyor
	//this adresi : 00000135EFF4DD40    Foo destructor
	//---------------------------------------- -
	//this adresi : 00000135EFF4DD40    Foo constructor
	//fp functor class  siliniyor
	//this adresi :00000135EFF4DD40    Foo destructor
	//---------------------------------------- -
}
*/

/*
class Deleter {
public:
	void operator()(const std::string* p) {
		cout << p << "adresi siliniyor\n";
		delete p;
	}
};

int main() {
	std::unique_ptr<std::string, Deleter> uptr{ new string{"tevfik uluocak"} };  //000001B21BD4F7C0adresi siliniyor

	auto fdel = [](const std::string* p) {cout << p << "adresi siliniyor\n";
	delete p; };

	std::unique_ptr<std::string, decltype(fdel)> up{ new string{"ahmet selim"} };  //0000021EDECF5250adresi siliniyor

	auto fdeleter = [](Person* p) {delete[]p; };
	unique_ptr<Person, decltype(fdeleter)> up2{new Person[5]};
	unique_ptr<Person, decltype([](Person* p) {delete[]p; })> up3{new Person[5]}; //since C++20

	unique_ptr<Person[]> up4{new Person[5]};  //partial_specializatiar
	//up4.operator[2];//bu partial spec. ýn operator[] fonksiyonu var.

}*/
  //unique_ptr nin fonksiyon parametresi olamsý
/*
void func(std::unique_ptr<string> uptr) {

}

std::unique_ptr<string> foo() {
	return nullptr;
}

unique_ptr<string> bar(unique_ptr<string>) {
	return nullptr;
}

int main() {
	//func(new string{ "necati ergin" }); error: explicit constructor var

	std::unique_ptr<string> up{ new string{ "tefoli13"} };
	cout << up.get() << '\n';  //adres döner
	cout << up<< '\n';  //yukarý ile ayný adresi dönen bir inserter var.
	//1
	func(std::move(up));//r value expr.
	//2
	func(unique_ptr<string>{new string{ "betusum uluocak" }}); //create temporaru object
	//3
	func(make_unique<string>("tefoliteftef"));//create fabrication

	auto p = foo();

}*/

//shared_ptr:deleter template parametresi deðil.hem copyable hem movable
/*
int main() {
	shared_ptr<string> sp( new string{"tefoli13"} );
	shared_ptr<string> sp2{ sp }; //copyable
	shared_ptr<string> sp3{ move(sp2) }; //moveable

	cout << "sp.use_count():" << sp.use_count() << '\n';  //2 adet sp yi gösteren shared_ptr var
	sp3.reset();
	cout << "sp.use_count():" << sp.use_count() << '\n';  //sp3 reset edildi. sp yi gösteren 1 adet shared_ptr var
	auto sp4 = make_shared < string>("tefoli13");
	
	auto custom_deleter = [](string* s) {cout << *s << "nesnesi siliniyor\n"; delete s; };
	{
		shared_ptr<string> sptr{ new string{"tevfik ulu"}, custom_deleter };//shared_ptr constructor ýna custom deleter eklendi 
	}
	cout << "main devam ediyor.\n";

	//tevfik ulunesnesi siliniyor
	//main devam ediyor.
	using StringPtr = std::shared_ptr<string>;

	StringPtr p1 {new string{"tevfik osman"}};
	StringPtr p2{ new string{"tevfik osman"}};

	cout << boolalpha << (p1 == p2) <<"\t"<< (*p1 == *p2) << '\n';  //false   true

	p2 = p1;
	auto p3 = p1;
	auto p4 = p1;
	cout << "p1.use_count():" << p1.use_count() << '\n';  //4
	cout << "p2.use_count():" << p2.use_count() << '\n';  //4
	cout << "p3.use_count():" << p3.use_count() << '\n';  //4
	cout << "p4.use_count():" << p4.use_count() << '\n';  //4
	
	p1.reset();


	cout << "p1.use_count():" << p1.use_count() << '\n';  //0
	cout << "p2.use_count():" << p2.use_count() << '\n';  //3
	cout << "p3.use_count():" << p3.use_count() << '\n';  //3
	cout << "p4.use_count():" << p4.use_count() << '\n';  //3
}
*/

//CRTP(Curiously Recurring Template Pattern): bir sýnýfý bir taban sýnýfýn þablonu ile kullanma mekanizmasý
/*
template <typename T>
class Nec {
public:
	void cry() { static_cast<T*>(this)->make_sound(); }  //downcast
};

class Myclass :public Nec<Myclass> {
public:
	void make_sound() { cout << "Myclass make sound:\n"; }
};

int main() {
	Myclass m1;
	m1.cry();  //Myclass make sound:
}
*/
//weak_ptr:shared_ptr den oluþur.dereference edilemez
//varlik nedeni shared_ptr yi gozlemlemek.
int main() {
	auto sptr = make_shared<string>("tefoli13");
	
	weak_ptr<string> wptr(sptr);

	if (wptr.expired())//return bool expr.
	{
		cout << "shared_ptr omru bitmis\n";
	}
	else {
		cout << "shared_ptr omru devam ediyor\n";  //shared_ptr omru devam ediyor
	}


	sptr.reset();
	if (wptr.expired())//return bool expr.
	{
		cout << "shared_ptr omru bitmis\n";   //shared_ptr omru bitmis
	}
	else {
		cout << "shared_ptr omru devam ediyor\n";  
	}

	//lock():shared_ptr dondurur. Nesne hayatta mý anlasilir

	shared_ptr<string> sp = wptr.lock();
	
	//auto sp = wptr.lock(); //yukaridaki ile ayni
	//if(auto sp = wptr.lock()) //asagýdaki ile ayni
	if (sp) { cout << "nesne hayatta\n"; }
	else    { cout << "nesne hayatta degil\n"; } //nesne hayatta degil
	try
	{
	shared_ptr<string> sp1{ wptr };  //wptr boþ olduðu icin shared ptr exception throw etti

	}
	catch (const std::exception& ex)
	{
		cout << "Exception is:" << ex.what() << '\n';  //Exception is:bad_weak_ptr
	}

	
}
