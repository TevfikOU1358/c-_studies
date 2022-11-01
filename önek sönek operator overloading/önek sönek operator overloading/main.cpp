#include <iostream>
#include <conio.h>

using namespace std;

enum class Weekdays {
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

Weekdays& operator++(Weekdays& wd) {  //sonek global operator overloading
   wd = wd == Weekdays::Saturday ? Weekdays::Sunday : static_cast<Weekdays>(static_cast<int>(wd) + 1);
	return wd;
}

Weekdays operator++(Weekdays& wd, int ) {  //sonek global operator overloading
	
	Weekdays temp{ wd };
	++wd; //= operator++(wd);
	return temp;
}


std::ostream& operator<<(std::ostream& os,const  Weekdays& wd) {
	static constexpr const char* p[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return os << p[static_cast<int>(wd)];
}

int main() {
	Weekdays wd{Weekdays::Monday};
	
	for (;;) {
		cout << wd++ << " ";
		_getch();
	
	}
}