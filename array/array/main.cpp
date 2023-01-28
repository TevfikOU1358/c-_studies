#include <iostream>
#include <array>

using namespace std;

template<typename T, std::size_t size>
struct Array {
	T a[size];
};

int main(){
	array<double, 20> ax;
}