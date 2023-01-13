#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


int main() {
	std::list<int> ilist;
	reverse(ilist.begin(), ilist.end());  //standart global funtion
	ilist.reverse();					  //member function
}