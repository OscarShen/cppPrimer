#include<iostream>
using std::cout;
using std::endl;

void exchange(int*&a, int*&b) {
	int* temp = a;
	a = b;
	b = temp;
}

void main() {
	int a = 100;
	int b = 99;
	int* pa = &a;
	int* pb = &b;
	exchange(pa, pb);
	cout << *pa << endl;
	cout << *pb << endl;
}