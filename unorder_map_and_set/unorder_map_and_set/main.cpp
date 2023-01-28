#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>


using namespace std;

struct DateHasher {
	size_t operator()(const DateHasher&)const {
		return 0;
	}
};

int main() {
	unordered_set<int, DateHasher> us;  //ilk parametrenin hasherý olmalý ve de == operator fonksiyonu da olmalý

	auto fhasher = []() {};  //stateles lambda since C++20

	unordered_multiset<int> s;
	for (int i{}; i < 100; i++) {
		s.insert(5);
	}
	cout << "size:" << s.size()<<'\n';  //100
	cout << "bucket size:" << s.bucket_count() << '\n'; //512

	cout << "load factory:" << s.load_factor() << '\n';  //0.195312

}