#include <iostream>
using namespace std;

void foo(int*);
void foo(int const);// func redecleration



int main() {
	int x = 5;
	int y{};
	const int cx = x;
	//constexpr int c_x = x; //syntax error ifade sabit de�er almal�
	constexpr int c_x = 5; 
	constexpr int* ptr = &x; //top level const 
	*ptr = 10;
	//ptr = &y; ba�ka bir de�i�kene atayamazs�n�z;
	return 0;
}