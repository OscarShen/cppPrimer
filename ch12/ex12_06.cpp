#include <iostream>
#include <vector>
using namespace std;

void input(vector<int>* v) {
	int n;
	while (cin >> n)
		v->push_back(n);
}

void print(const vector<int>* v) {
	for (int t : *v)
		cout << t << endl;
}

int main() {
	vector<int>* v = new vector<int>();
	input(v);
	print(v);
}