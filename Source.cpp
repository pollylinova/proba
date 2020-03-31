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
void init(ime** st); //pl
int empty(ime* st);

void init(ime** st) { //pl
	*st = NULL; //pl
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
	init(&start); //pl
	int num;
	int N;
	int A;
	cout << "Input number in stack: ";
	while (cin >> num)
		start = push(start, num);
	cout << "S: ";
	while (!empty(start)) { //pl тук току що извлече всичко от стека и той вече е празен, за да правиш нещо с него
		start = pop(start, num);
		cout << num << " ";
	}
	cin.clear();
	cin.ignore();
	cout << "\n Input the element number from top you want to change: ";
	cin >> N;
	cout << "\n And the new value: ";
	cin >> A;
	init(&pst); //pl
	while (!empty(start)) { //pl обедини с for. трябва да бъде 1 цикъл с проверка, дали не са свършили елементите в стека
		for(int i=N-1; i>=0; i--) { 
		    start = pop(start, num);		//pl ще доведе до грешка, щом няма проверка за край	
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
