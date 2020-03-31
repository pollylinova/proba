//stek S, promqna na N-ti element sled wyrha w nowa stoinost A, kato ostanalite elementi zapazwat stoinostite si
//da se izwede sydyrjanieto na ekrana, stoinosti za A i N da se wywejdat ot potrebitelq, kakto i pyrwonachalnoto sydyrjanie na S
#include <iostream>
//#include<cstring>
//#include <stack>
using namespace std;
struct ime {
	int key;
	ime* next;
}
*start, * pst;
ime* push(ime* st, int n);
ime* pop(ime* st, int& n);
void init(ime* st);
int empty(ime* st);

void init(ime* st) {
	st = NULL;
}

int empty(ime* st) {
	if (st == NULL)
		return 1;
	else
		return 0;
}

ime* push(ime* st, int n) {
	ime* p;
	p = new ime;
	p->key = n;
	p->next = st;
	st = p;
	return p;
}

ime* pop(ime* st, int& n) {
	ime* p;
	n = st->key;
	p = st;
	st = st->next;
	delete p;
	return st;
}

void main() {
	init(start);
	int num;
	int N;
	int A;
	cout << "Input number in stack: ";
	while (cin >> num)
		start = push(start, num);
	cout << "S: ";
	while (!empty(start)) {
		start = pop(start, num);
		cout << num << " ";
	}
	cin.clear();
	cin.ignore();
	cout << "\n Input the element number from top you want to change: ";
	cin >> N;
	cout << "\n And the new value: ";
	cin >> A;
	init(pst);
	while (!empty(start)) {
		for(int i=N-1; i>=0; i--) {
		    start = pop(start, num);			
			pst = push(pst, num);
		}
	}
	cout << "P: ";
	while (!empty(pst)) {
		pst = pop(pst, num);
		cout << num << " ";
	} 
	// to be continued 
	system("pause");
}