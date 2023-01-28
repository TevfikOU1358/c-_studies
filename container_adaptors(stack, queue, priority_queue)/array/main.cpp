#include <array>
#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <queue>

template<typename T, typename C = std::deque<T>>
class Stack {
public:
	void push(const T& t) { c.push_back(t); }
	void push(T&& t) { c.push_back(std::move(t)); }


protected:
	C c;
};

using namespace std;
/*
container adaptors: stack, queue, priority queue
bunlar bir adaptor deðil.member olarak container alýr.
Stack:LIFO:
Queue:FIFO:2.parametre vector kullanýlamaz
Priority Queue: En yüksek önceliðin çýktýðý mekanizma:2.parametre random_access_iterator:list alamaz
*/

//stack
/*
int main() {
	deque<int> x{ 2, 6, 7, 8, 12 };
	stack mystack(x);  //CTAD;
	stack<int, vector<int>> s{ x.begin(), x.end() }; //range base constructor since C++23
	stack<int, list<int>> s1{ x.begin(), x.end() }; //range base constructor since C++23

}
*/


/*
//queue
int main() {
	queue <string> q;  //2.parametre default olarak deque
	queue < string, vector<string> q1;  //2.parametre vector olamaz. queue FIFO olduðu için vectro de push_front() u yok

}
*/

//priority_queue:2.parametre default olarak vector kullanýyor

int main() {

	priority_queue<int, vector<int>> x1;
	priority_queue<int, deque<int>> x2;
	//priority_queue<int, list<int>> x3; legal ama üye fonksiyonlarla iþlemler yapýlamaz.2. parametre random access iterator
	priority_queue<int, vector<int>, greater<int>> x4;
	x4.push(10);
}