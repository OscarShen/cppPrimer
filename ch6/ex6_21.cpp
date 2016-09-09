#include <iostream>
using std::cout;
using std::endl;

int bigger(int a, int* b) {
	return a > *b ? a : *b;
}

void main() {
	int b = 999;
	int res = bigger(100, &b);
	cout << res << endl;
}