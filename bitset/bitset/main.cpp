#include <iostream>
#include <bitset>

using namespace std;

//bitset mekanizmalarý assignable deðil

int main() {
	bitset<8> bx;
	cout << bx << "\n";  //00000000
	
	bitset<8> by(15);
	cout << by << "\n";  //00001111

	bx.set(); //bütün bitler set edildi.
	cout << bx << "\n";  //11111111
	
	bx.reset(); //bütün bitler reset

	cout << bx << "\n";  //00000000

	if (bx.test(3)) { cout << "3. bit set\n"; }
	if (bx.any()) { cout << "en az bir set var\n"; }
	if (bx.none()) { cout << "hepsi reset\n"; }
	if (bx.all()) { cout << "hepsi set\n"; }

	bx.flip(2); //2. bit toggle
	cout << bx << "\n";  //00000100
	bx.flip(); //bütün bitler  toggle
	cout << bx << "\n";  //11111011

	bx[4] = 0;
	bx[0] = false;
	cout << bx << "\n";  //11101010

	bx[4] = bx[2];
	bx.operator[](3).operator=(bx.operator[](2));  //3. bite 2 nin deðeri atandi

	cout << (bx >> 5)<<'\n'; //00000111
	
}