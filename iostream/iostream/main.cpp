#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
int main() {
	cout.operator<<(35);
	int x{ 10 };
	cout.operator<<(&x); //350000003E7BB1F914 //void * parametre kullanýldý

	cout << "tevfik\n"; //global cout tevfik
	operator<<(cout, "tevfik\n"); //global cout tevfik
	cout.operator<<("tevfik\n");//member function cout void * parametre çagirilir

	cout.setf(ios_base::boolalpha);
	cout << true << '\n'; //true
	cout.unsetf(ios_base::boolalpha);
	cout << true << '\n'; //1
	cout.setf(ios::hex, ios::basefield);
	cout.setf(ios::uppercase | ios::showbase);
	cout << 58 << '\n'; //0X3A
	
	double d{ 1.23412312324243 };

	cout.precision(4);
	cout << d << '\n'; //1.234

}
*/
/*
//iostream manipulator
std::ostream& Hex(std::ostream& os) {  //cout un geri dönüþ deðeri ve parametresi ostream olan funtion pointer member functionu
	os.setf(std::ios::hex, std::ios::basefield);
	return os;
}
std::ostream& Dec(std::ostream& os) {  //cout un geri dönüþ deðeri ve parametresi ostream olan funtion pointer member functionu
	os.setf(std::ios::dec, std::ios::basefield);
	return os;
}
std::ostream& Oct(std::ostream& os) {  //cout un geri dönüþ deðeri ve parametresi ostream olan funtion pointer member functionu
	os.setf(std::ios::oct, std::ios::basefield);
	return os;
}
std::ostream& Boolalpha(std::ostream& os) {  //cout un geri dönüþ deðeri ve parametresi ostream olan funtion pointer member functionu
	os.setf(std::ios::boolalpha);
	return os;
}

std::ostream& NoBoolalpha(std::ostream& os) {  //cout un geri dönüþ deðeri ve parametresi ostream olan funtion pointer member functionu
	os.unsetf(std::ios::boolalpha);
	return os;
}

std::ostream& tefos(std::ostream& os) {  //kendi ihtiyacým icin olusturduðum manipulator
	os.setf(ios::boolalpha | ios::showbase);
	os.setf(ios::left, ios::adjustfield);
	os.setf(ios::hex, ios::basefield);
	os.setf(ios::fixed, ios::floatfield);
	os.precision(12);

	return os;
}

int main() {
	int ival = 0xBABA;
	//bizim oluþturduðumuz ostream manipulatorleri
	cout << ival << " " << Hex << ival << '\n';  //47802 baba
	cout << ival << " " << Dec << ival << '\n';  //baba 47802
	cout << ival << " " << Oct << ival << '\n';  //	47802 135272
	cout << true << Boolalpha << true << NoBoolalpha << false<<'\n'; //1true0

	//default manipulatorler
	cout << dec << 10 << hex << 10 << '\n';  //10a

}
*/
/*
std::ostream& Endl(std::ostream& os) {  //endl implementation
	os.put('\n');
	os.flush();
	return os;
}
std::ostream& starline(std::ostream& os) {  //endl implementation
	os << "\n*********************\n";
	return os;
}
// <iomanip> :parametreli manipulator
#include <iomanip>

int main()
{
	cout << 25 << starline << 35 << '\n'; 
	//25
	//*********************
	//35
}
int main() {
	cout << "bir tam sayi girin:\n";
	int x;
	cin >> hex >> x;  //istream manipulator:hex
	cout << "x:" << x << '\n'; //2f:47

}
*/
/*
//ios::iostate:hata yoksa 0
int main() {
	if (cin.good()) {
		cout << "akim iyi durumda\n";
	}
	//2.method
	if (cin) { //operator bool();
		cout << "akim iyi durumda\n";
	}
	//Hata durumlarý:
	//format uyumsuzluðu
	//sistemde karakter kalmamasi

	if (cin.eof()) {
		cout << "stream eof durumunda\n";//cin control z ise
	}
	cin.clear();//state good durumuna gelir.
}
*/ 
#include <bitset>
#include <sstream>
#include <vector>

/*
int main() {
	ostringstream oss;
	string name{ "tevfik osman uluocak" };
	int age{27};
	string place{ "sivas" };
	oss << name << '-' << age << '-' << place<<'\n';
	auto s = oss.str();
	cout << s;  //s:tevfik osman uluocak-27-sivas 

	string str{ "13 25 48 69 78 89 112 235 456 567 678 789 864 962" };
	istringstream iss{ str };
	int ival;
	while (iss >> ival) {
		cout << ival << ' '; //13 25 48 69 78 89 112 235 456 567 678 789 864 962
	}
	string str1{ "13 25 48 69 78 89 112 235 456 567 678 789 864 962" };
	istringstream iss1{ str1 };
	vector<int> ivec{ istream_iterator<int>{iss1}, {} }; //vector range ctor: iterator constructor ý ilk parametre stream, 2.parametre default end ctor
		cout <<"\n---------------------\n";
	for (auto val : ivec) {
		cout << val << ' ';  //13 25 48 69 78 89 112 235 456 567 678 789 864 962
	}
		cout <<"\n---------------------\n";


	string str2{ "istanbul ankara izmir sivas antalya manisa" };
	istringstream iss2{ str2 };
	string s2;
	while (iss2 >> s2) {
		cout << s2 << ' ';  //istanbul ankara izmir sivas antalya manisa
	}
}
*/

//ifstream
#include <fstream>
#include <algorithm>
/*
int main() {
	//1.örnek
	ifstream ifs{ "output.txt" };
	if (!ifs) {
		cout << "dosya acilamadi";
	}
	vector<int> ivec{ istream_iterator<int>{ifs}, {} }; //vector range ctor
	cout << "\n---------------------\n";
	for (auto val : ivec) {
		cout << val << ' ';  //13 24 56 78 89 56 78 35 24 56 78 23 67 24 123 58 //output.txt den okundu
	}
	cout << "\n---------------------\n";

	//2. örnek : tek statement da girilen sayilardan en byukunu bul
	cout<<*max_element(istream_iterator<int>{cin}, {});
	//girilen sayilar:12 24 45 56 12 13 143 12 145678 2435465 1233456 12345 7896754
	//en buyuk:7896754 

	//3. örnek
	istringstream iss{ "12345678" }; 
	char c;
	while (iss.get(c) ) {
		cout << c << ' '; //1 2 3 4 5 6 7 8
	}

	
}
*/
/*
//#fstream: ifstream , ofstream, fstream yazildigi kutuphane
//ofstream sadece yazmak icin
//ifstream sadece okumak icin
//fstream hem yazma hem okumak icin
int main() {
	//fstreamlerde constructor da open iþlemi yapiliyor.
	//bir obje birden fazla dosyaya baðlanabilir.
	string filename{ "osman.txt" };
	ofstream ofs1{filename.c_str()};//eski kodlarda string parametreleri ctor yoktu.böyle yaziliyordu
	//ofstream ofs{ "tefo.txt", ios::out | ios::trunc }; //asagýdaki ile ayni trunc:dosya var ise siler. yeniden olusturur.Default olarak gelir.
	ofstream ofs{ "tefo.txt" };
	ofs << "tevfik osman uluocak"; //tefo.txt ye tevfik osman uluocak yazýldý
	cout << boolalpha << ofs.is_open()<<'\n'; //true :dosyayý ctor acti.
	//dosya acýldý mý kontrolu
	if(ofs.fail()){}
	if(!ofs){}
	
	//ifstream ifs{ "ahmet.txt", ios::in};//asagidaki ile ayni
	ifstream ifs{ "ahmet.txt" }; //2.parametre default ios:in
	//ios:::ate :cursor position at end:(sonunda olucak).

	ifs.clear(); // akýmý good state getirir. oyüzden bir dosyada okuma islemi bittikten sonra tekrardan islem yapilebilmesi icin clear() cagirilmalidir.

	//to ifs2 = ifs; //error: fstream non copyable but movable;
	auto ifs2 = std::move(ifs); //legal
	cout << "file pointer vale:" << ifs2.tellg() << '\n'; //tellg: file pointer value

	vector<string> svec{ "sivas", "ankara", "edirne", "istanbul", "malatya", "kayseri", "agri", "adana", "amasya", "afyon", "bursa"};
	copy_if(svec.begin(), svec.end(), ostream_iterator<string>{cout, "\n"}, [](const string& s) {return s.length() == 5; });  //uzunluðu 5  olan þehirleri cýkýs akimina yazdi.
	copy_if(svec.begin(), svec.end(), ostream_iterator<string>{ofs, "\n"}, [](const string& s) {return s.length() == 5; });  //uzunluðu 5  olan þehirleri ofs nin baðlý olduðu dosyalara yazdi.

	// dosya text modda ise; son karakter 13 10 CRLF
	// dosya binary  modda ise; son karakter  10 LF
}*/

int main() {
	{
		ofstream ofs{ "primes.txt" };
		if (!ofs) {
			cerr << "cannot create file!\n";
		}
		int prime_count{};
		ofs << left << hex << uppercase;
		while (prime_count < 1'000) {
			ofs << prime_count << ' ';
			prime_count++;
		}
		if (!ofs) {
			cout << "cannot open file!\n";
		}
	}
	ifstream ifs{ "primes.txt" };
	char ch;
	//1. okuma yöntemi
	while (ifs.get(ch)) {
		cout << ch;
	}
	cout << '\n';
	ifs.clear();//return good state
	ifs.seekg(0, ios::beg);
	//2. okuma yöntemi
	int val;
	while ((val = ifs.get()) != EOF) {
		cout << val;
	}
	cout << '\n';
	//3.okuma
	ifstream ifs2{ "output.txt" };
	string sline;
	while (getline(ifs2, sline, '\n')) { //3.param:delimiter default:'\n'
		cout << sline << ' ';  //tevfik osman uluocak betus dogan
	}

	//write()
	{ofstream ofs{ "tefo.dat", ios::binary };
	int x{};
	while (x < 100) {
		ofs.write(reinterpret_cast<char*>(&x), sizeof(int));
		x++;
	}
	//read()
	}
	cout << "\n----------------------------\n";
	int i{};
	ifstream ifs3{ "tefo.dat", ios::binary};
	//seekg():position belirledi
	ifs3.seekg(static_cast<streampos>(85 * sizeof (int)));  //85.indisten itibaren okunmaya basladi
	cout << "\n----------------------------\n";
	cout << "tellg"<<ifs3.tellg() << '\n';
	while (ifs3.read(reinterpret_cast<char*>(&i), sizeof(int))) {
		cout << i;  //858687888990919293949596979899
	}
	cout << "tellg"<<ifs3.tellg() << '\n'; //bitince -1

	ifs3.close(); //silmeden once kapattim
	//remove()
	if (remove("tefo.dat")) {  //basarili olsursa 0 doner
		cerr << "dosya silinemedi";
	}


}