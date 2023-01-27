#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
//2. sequence container
//deque:dinamik dizilerin dizisi hem baþtan hem sondan ekleme yapar.constant time da indise de eriþebiliyoruz.
//burda reallocation yok.
//contigious deðil , random access iterator
using namespace std;

template < typename T >
std::ostream& operator << (std::ostream& os, const std::deque<T>& v)
{
	os << "[";
	for (typename std::deque<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
	{
		os << " " << *ii;
	}
	os << "]";
	return os;
}
//deque da ekleme  ortadan yapýlýyor ise; bütün iterator ve referanslar invalidate oluyor.
//eðer baþtan veya sondan yapýlýyor ise; iteratorler invalidate referanslar validate oluyor.

//deque da silme  ortadan yapýlýyor ise; bütün iterator ve referanslar invalidate oluyor.
//eðer baþtan veya sondan yapýlýyor ise; sadece silinen iteratorler invalidate referanslar validate oluyor.
int main() {
	deque<int> d;

	d.push_front(14); //vector de yok
	d.push_front(24); //vector de yok

	cout << d << "\n"; //[24 14]

	auto val = d[1];

	cout << val << "\n";

}