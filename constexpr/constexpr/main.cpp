#include <iostream>
using namespace std;

void foo(int*);
void foo(int const);// func redecleration



int main() {
	int x = 5;
	int y{};
	const int cx = x;
	//constexpr int c_x = x; //syntax error ifade sabit deðer almalý
	constexpr int c_x = 5; 
	constexpr int* ptr = &x; //top level const 
	*ptr = 10;
	//ptr = &y; baþka bir deðiþkene atayamazsýnýz;
	return 0;
}