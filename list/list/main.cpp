#include <iostream>
#include <list>
#include <functional>
#include <bitset>

using namespace std;
//list :sequence container. contiougous deðil
template < typename T >
std::ostream& operator << (std::ostream& os, const std::list<T>& v)
{
	os << "[";
	for (typename std::list<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
	{
		os << " " << *ii;
	}
	os << "]";
	return os;
}
/*linked list :ardýþýk öðeler deðil.index eriþimi constant time da deðil.Linear complexity
* Çift yönlü hareket edebildiði için iteratorler bidirectional
*/
/*
int main() {
	list<int> ilist(5);
	ilist.push_front(10);
	ilist.pop_front();
	
	list<string> slist{ "tevfik", "osman", "uluocak", "betus", "dogan", "numan", "yasin", "ahmet", "talha" };

	cout << slist << "\n";
	auto iter = next(slist.begin(), 2);
	slist.insert(iter, "arif");
	cout << slist << "\n";//[ tevfik osman arif uluocak betus dogan numan yasin ahmet talha]

	while (!slist.empty()) {
		slist.pop_front();  //baþtan sildi
		cout << slist << "\n";
		(void)getchar();
	}
	//[tevfik osman arif uluocak betus dogan numan yasin ahmet talha]
	//[osman arif uluocak betus dogan numan yasin ahmet talha]
	//[arif uluocak betus dogan numan yasin ahmet talha]
	//[uluocak betus dogan numan yasin ahmet talha]
	//[betus dogan numan yasin ahmet talha]
	//[dogan numan yasin ahmet talha]
	//[numan yasin ahmet talha]
	//[yasin ahmet talha]
	//[ahmet talha]
	//[talha]
	//[]
	
	list<string> slist2{ "tevfik", "osman", "uluocak", "betus", "dogan", "numan", "yasin", "ahmet", "talha" };
	slist2.reverse();
	cout << slist2 << "\n";  //[ talha ahmet yasin numan dogan betus uluocak osman tevfik]

	slist2.sort();
	cout << slist2 << "\n"; //[ ahmet betus dogan numan osman talha tevfik uluocak yasin]
	slist2.sort(greater());
	cout << slist2 << "\n"; //[yasin uluocak tevfik talha osman numan dogan betus ahmet]

	slist2.remove("dogan");
	cout << slist2 << "\n";  //[ yasin uluocak tevfik talha osman numan betus ahmet]

	slist2.remove_if([](const std::string& s1) {return s1.length() == 5; });
	cout << slist2 << "\n"; //[uluocak tevfik]
	
	list<string> slist3{ "tevfik", "osman", "uluocak", "betus", "dogan", "numan", "yasin", "ahmet", "talha" };
	for (auto iter = slist3.crbegin(); iter != slist3.crend(); iter++) { //tersten dolaþtý. bidirectional olduðu için reverse iterator aktif
		cout << *iter<<"\t";  //talha   ahmet   yasin   numan   dogan   betus   uluocak osman   tevfik
	}
	cout << "\n";

	for (const auto& x : slist3) {
		cout << x << "\t";  //tevfik  osman   uluocak betus   dogan   numan   yasin   ahmet   talha
	}
	cout << "\n";

	slist3.emplace_front("naci");
	cout << slist3 << "\n"; //[naci tevfik osman uluocak betus dogan numan yasin ahmet talha]

	slist3.emplace_back("erdem");
	cout << slist3 << "\n";//// [naci tevfik osman uluocak betus dogan numan yasin ahmet talha erdem]

	

	list<string> males{ "tevfik", "osman", "uluocak" };
	list<string> females{ "hacce", "betus", "gullu" };

	males.splice(males.begin(), females);

	cout << "females.size():" << females.size() << "\n";  //0
	cout << males << " "; //[hacce betus gullu tevfik osman uluocak]

}
*/
//tekli baðlý liste:o konuma silme veya ekleme yapamayýz.
//ancak o konumdan sonrasýna yapýlabilir.

#include <forward_list>
template < typename T >
std::ostream& operator << (std::ostream& os, const std::forward_list<T>& v)
{
	os << "[";
	for (typename std::forward_list<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
	{
		os << " " << *ii;
	}
	os << "]";
	return os;
}
int main() {
	forward_list<int> ilist(8);
	ilist.insert_after(ilist.before_begin(), 5);
	cout << ilist << "\n";//[ 5 0 0 0 0 0 0 0 0]


}