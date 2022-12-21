#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
template <typename Iter>
void print_array(Iter beg, Iter end) {
	while (beg != end) {
		cout << *beg++ << " ";
	}
	cout << "\n--------------------------\n";
}

int main() {
	int a[]{ 1, 2, 3, 4, 5, 6, 7, 8 };
	double d[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	print_array(a, a + 6);
	print_array(d, d + 4);
	
	1 2 3 4 5 6
	--------------------------
	1.1 2.2 3.3 4.4
	--------------------------
	
}
*/

int main() {
	vector ivec{ 1, 2, 3, 4, 5, 6, 7, 8 };
	vector ivec2{ 7, 5, 9, 1, 6, 4, 2};
	auto iter = ivec.begin();

	cout << *iter << "\n";	//1
	iter++;
	cout << *iter << "\n";	//2

	reverse(ivec.begin(), ivec.end());
	iter = ivec.begin();
	cout << *iter << "\n";	//8 (ters çevirildi)

	sort(ivec2.begin(), ivec2.end());
	iter = ivec2.begin();
	cout << *iter << "\n";	//1 (düz sýralandý)


}