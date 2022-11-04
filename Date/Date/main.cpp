#include <iostream>
#include "Date.h"
using namespace std;
int main()
{
	Date d1(1, 12, 1996);
	Date d2(2, 11, 1995);
	++d1.wd;
	d1.wd--;
	cout << static_cast<int>(d1.wd) << endl;
	cout << d1 - d2 << endl;

	Date d3{ 12,12,2000 };
	Date d4( 10 + d3);
	Date d5(d3 + 10);
	cout << d4 << endl;
	cout << d5 << endl;


}