#include <iostream>
#include <vector>
#include <new>

using namespace std;

//dynamic ömür: istediðimiz zaman baþlattýðýmýz istediðimiz zaman bitirdiðimiz nesneler
//türleri run-time da belli oluyor.
/*
class A {
public:
	A(int){}
	unsigned char buffer[1024];
};
int main() {

	//operator new:> baþarýsýz olursa exception throw eder.
	cout << "sizeof(A):" << sizeof(A) << '\n'; //1024

	auto p = new A(12);
	auto p2 = new A{ 2 };

	constexpr size_t size = 1024 * 1024;
	vector<void*> pvec;
	int cnt{};

	try {
	for (;;) {
		pvec.push_back(operator new(size));  //new operatoru baþarýsýz olursa exception throw eder
		cout << cnt++ << '\n';
	}
	}
	catch (const std::exception& ex) { 
		cout << "exception caught:" << ex.what() << '\n'; 
		cout << cnt++ << '\n';  
	}
}
*/

void my_new_handler() {
	cout << "my_new_handler\n";
}
/*
int main() {

	set_new_handler(my_new_handler);  //bundan sonra her new oeratorunden sonra my_new_handler çaýrýlýcak
	auto fp = get_new_handler();

	if (fp == nullptr) { cout << "evet dogru\n"; }
	else { cout << "hayir yanlis\n"; }

	cout << "fp:" << fp << '\n';
	cout << "my_new_handler:" << my_new_handler << '\n';
	int* fp2 = new int;
	
//	hayir yanlis
//	fp:00007FF750781447
//	my_new_handler:00007FF750781447
//	

}
*/
struct A {
	A() {
		cout << "C this:" << this << '\n';
	}
	~A() {
		cout << "D this:" << this << '\n';
	}

	unsigned char a[16];
};

struct Tef {
	void* operator new(size_t sz) {
		//this; yazýlmasada statik üye fonksiyon olduðu için this çaðýrýlamaz
		cout << "operator new (size_t)\n";
		auto vp = std::malloc(sz);
		if (!vp) {
			throw std::bad_alloc{};

		}
		return vp;
	}
	void operator delete(void *vp){
		cout << "operator delete(void *vp)\n";
		std::free(vp);
	}
};

int main() {
	set_new_handler(my_new_handler); 
	//array new
	auto p = new A[5];
	delete[]p;

	//16 16 artýyor adres
	//C this : 0000023F3B5C5138
	//C this : 0000023F3B5C5148
	//C this : 0000023F3B5C5158
	//C this : 0000023F3B5C5168
	//C this : 0000023F3B5C5178
	//D this : 0000023F3B5C5178
	//D this : 0000023F3B5C5168
	//D this : 0000023F3B5C5158
	//D this : 0000023F3B5C5148
	//D this : 0000023F3B5C5138

	//placement new

	unsigned char storage[sizeof(A)];
	auto p2 = new (storage)A;  // p2 afresi storage n adresi oldu.
	cout << "adres:" << static_cast<void*>(storage)<<'\n';
	cout << "adres p2:" << p2<<'\n';
	
	p2->~A();  //mecburi olarak destructoru biz yazdýk
	//adres:000000E9D10FF8A8
	//adres p2 : 000000E9D10FF8A8
	//D this:0000005CBE0FFB28

	//nothrow:exception throw etmeyen new
	new(nothrow) A;  //baþarýsýz olursa exception yerine nullptr döndürüyor

	auto tp = new Tef;  //operator new (size_t)
	delete tp; //operator delete(void *vp)
}