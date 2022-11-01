#include <iostream>
#include <stdlib.h>
#include "tevfik.h"

using namespace std;
int f(int*);
int f(int * const)
{
	cout << "int*" << endl;
	return 0;
}
int f(const int *) {
	cout << "low level int*" << endl;
	return 0;

}


int main()
{
// int x = 5;
	//f(&x);

	const int x = 5;
	constexpr int y = 5;
	decltype(x) r1 = 10;
	return 0;
}
