#include <iostream>
#include <string>


using namespace std;

int main()
{
	/*
	* 1
	string str1("tevfik");
	cout << static_cast<const void*>(str1.data()) << "\n";
	cout.operator<<(str1.data());

	0000002CB2AFFBD0
	0000002CB2AFFBD0
	*/
	/*
	* 2
	//string s( 'a' ); //error char ctor yok
	string s{ 'a' };//geçerli

	string s1("tevfik");  // cstring
	string s2{ 'o', 's', 'm', 'a', 'n' }; //initializer_list
	string s3(49, 'A');
	string s4{ 49, 'A' };

	cout << "s1:" << s1<<"\n";
	cout << "s2:" << s2<<"\n";
	cout << "s3:" << s3<<"\n";
	cout << "s4:" << s4<<"\n";

	//cout <<"s:"<< s1[15] << "\n"; undefined behaviour
	//cout << s1.at(30) << "\n"; exception throw eder

	s1:tevfik
	s2 : osman
	s3 : AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	s4 : 1A
	*/

	/*
	3:String Traverse



	string s{ "tevfik osman uluocak" };

	for (size_t i{}; i < s.size(); i++) { //1
		cout << s[i] << " ";
	}
	cout << "\n";

	for (auto iter = s.begin(); iter != s.end(); ++iter) { //2
		cout << *iter << " ";
	}

	cout << "\n";

	for (auto c : s) {  //3
		cout << c << " ";
	}
	t e v f i k   o s m a n   u l u o c a k
	t e v f i k   o s m a n   u l u o c a k
	t e v f i k   o s m a n   u l u o c a k
	*/

	/*
	cstring -> string örtülü dönüþüm var
	string ->  cstring örtülü dönüþüm yok. str.c_string() var
	*/
	/*
	* 4
	string s{ "tefoli" };
	cout << s.front() << "\n";  //front(): ilk elemaný döndürür. t
	cout << s.back() << "\n";  //back(): son elemaný döndürür.   i

	// hepsi ayný adres
	char* p1 = &s[0];
	char* p2 = &*s.begin();
	char* p3 = s.data();  //c++17 char * öncesinde const char *
	const char* p4 = s.c_str();
	cout.operator<<(p1);
	cout << endl;

	cout.operator<<(p2);
	cout << endl;

	cout.operator<<(p3);
	cout << endl;

	cout.operator<<(p4);
	cout << endl;

	/*
	000000A0A50FFB40
	000000A0A50FFB40
	000000A0A50FFB40
	000000A0A50FFB40
	*/
	/*
	* 5
	string s("tevfik");
	cout << "s:" << s << "\n";
	cout << "size:" << s.size() << "\n";
	cout << "capacity:" << s.capacity() << "\n";

	s.resize(3); //size günceller karakter silmek için de kullanýlýr. capacity azalmaz.
	cout << "s:" << s << "\n";
	cout << "size:" << s.size() << "\n";
	cout << "capacity:" << s.capacity() << "\n";

	s.resize(20, 'A');
	cout << "s:" << s << "\n";
	cout << "size:" << s.size() << "\n";
	cout << "capacity:" << s.capacity() << "\n";


	s:tevfik
	size:6
	capacity:15
	s:tev
	size:3
	capacity:15
	s:tevAAAAAAAAAAAAAAAAA
	size:20
	capacity:31
	*/
	/*
	6
	string s("osman");
	s = 'c'; //geçerli char parametrel, ctor yok ama operator=(char ) var.

	s.assign(10, '!');  //fill (5)	string& assign(size_t n, char c);
	cout << "s:" << s << "\n";

	string s1 = "tevfik osman uluocak ";

	s1.assign(s1, 7);  //string& assign (const string& str, size_t subpos, size_t sublen = npos);

	cout << "s1:" << s1 << "\n";  //s1:osman uluocak

	s1.assign(s1, 6, 7);  //string& assign (const string& str, size_t subpos, size_t sublen = npos);

	cout << "s1:" << s1 << "\n"; //s1:uluocak

	s1.assign("tevfik"); //string& assign (const char* s);

	cout << "s1:" << s1 << "\n"; //s1:tevfik

	s1.assign("tevfik" , 3, 2);  //buffer (4)	string& assign(const char* s, size_t n);
	cout << "s1:" << s1 << "\n"; //s1:fi

	string s2 = "tevfik";
	s2.assign(s2.begin(), s2.end());  // range:template <class InputIterator>   string& assign (InputIterator first, InputIterator last);

	cout << "s2:" << s2 << "\n"; //s2:tevfik

	s2.assign({ 'a', 'b', 'c' });  //initializer list(7)	string& assign(initializer_list<char> il);
	cout << "s2:" << s2 << "\n"; //s2:abc

	s2.assign(move(s1)); //move (8)	string& assign(string&& str) noexcept;
	cout << "s2:" << s2 << "\n"; //s2:fi
	*/

	/*

	7
	string s{ "tefo" };
	s.append("li");
	cout << s << "\n";

	cout << s.find('i') << "\n";	//5. indiste buldu.
	cout << s.find('u') << "\n";	// bulamazsa npos(string sýnýfýnýn static data member ýný döner)

	string s1{ "tevfik osman uluocak" };
	s1.erase(7);  //7. indisten itibaren siler
	cout << s1 << "\n";  //s1:tevfik

	string s2{ "tevfik osman uluocak" };

	s2.erase(7, 6); //index
	cout << s2 << "\n";  //s2:tevfik uluocak

	s2.erase(s2.begin(), s2.end());  //range --- hepsini siler
	cout << s2 << "\n";
	*/

	/*
	string s{ "tevfik osman uluocak" };
	reverse(s.begin(), s.end());  //kacoulu namso kifvet

	cout << s << "\n";

	string s1{ "tevfik osman uluocak" };

	s1.insert(s1.begin(), '!');
	cout << s1 << "\n";  //!tevfik osman uluocak

	s1.insert(s1.begin(), 5, 'x');
	cout << s1 << "\n";  //xxxxx!tevfik osman uluocak

	s1.insert(s1.end(), s1.begin() + 6, s1.begin() + 12);  //xxxxx!tevfik osman uluocaktevfik (parametreler string deðil cstr olacak)

	s1.erase(12);
	s1.erase(0, 6);
	cout << s1 << "\n"; //s1:tevfik

	const char* p = "osman";

	s1.insert(s1.end(), p, p + 5);
	cout << s1 << "\n";  //tevfikosman

	s1.insert(3, 5, 'A');
	cout << s1 << "\n";  //tevAAAAAfikosman

	s1.erase(s1.begin());
	cout << s1 << "\n"; // evAAAAAfikosman

	//compare fonksiyonu()  eþitse 0 posiitive ise ilk string negatifse ikinci string büyüktür.
	*/
	/*
	8

	string s("alivelizilli");
	cout << s._Starts_with("ali") << endl; //return 1

	s.replace(2, 2, "abcd");  //1. hangi indis 2.kaç karakter silinecek 3.yerine ne yazýlacak
	//s.replace(2, 2, s.c_str()); olur

	cout << s << endl;		 //alabcdelizilli
	s.replace(0, s.size(), 5, 'A'); //0. indisten uzunluk kadar silindi. yerine 5 tane 'A' karakteri yazýldý.
	cout << s << endl;		//AAAAA
	*/
	/*
	* Numeric conversion
	* 10
	string str{ "12345betul" };
	cout << stoi(str) << endl;  //12345
	size_t idx{};

	stoi(str, &idx);
	cout << idx << endl; //5.indis

	cout << to_string(idx) << endl;  //karakter 5
	*/
	/*
	const char* p = "ahmet";
	cout << p << endl;
	operator<<(cout, p); //global operator <<()
	cout.operator<<(p);  //00007FF72F1DAC24: member operator<<() parametre void * o yüzden adres yazýyor.

	string str{ "osman" };

	cout << str << endl;	//osman
	operator<<(cout, str);	//osman global operator<<()

	//cout.operator<<(str);//error string& void * implicit dönüþüm yok
	cout.operator<<(str.c_str());  //char* -> void * implicit conversion
	*/
	
}