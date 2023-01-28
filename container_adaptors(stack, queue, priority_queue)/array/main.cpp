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
bunlar bir adaptor de�il.member olarak container al�r.
Stack:LIFO:
Queue:FIFO:2.parametre vector kullan�lamaz
Priority Queue: En y�ksek �nceli�in ��kt��� mekanizma:2.parametre random_access_iterator:list alamaz
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
	queue < string, vector<string> q1;  //2.parametre vector olamaz. queue FIFO oldu�u i�in vectro de push_front() u yok

}
*/

//priority_queue:2.parametre default olarak vector kullan�yor

int main() {

	priority_queue<int, vector<int>> x1;
	priority_queue<int, deque<int>> x2;
	//priority_queue<int, list<int>> x3; legal ama �ye fonksiyonlarla i�lemler yap�lamaz.2. parametre random access iterator
	priority_queue<int, vector<int>, greater<int>> x4;
	x4.push(10);
}