#include <vector>
#include <iostream>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int Fun(int a, int b);
vector<int(*) (const int&,const int&)> v;

int	NumAdd(const int& a, const int& b) {
	return a + b;
}

int NumSub(const int& a, const int& b) {
	return a - b;
}

int NumMul(const int& a, const int& b) {
	return a * b;
}

int NumDiv(const int& a, const int& b) {
	return a / b;
}


int main() {
	v.push_back(NumAdd);
	v.push_back(NumSub);
	v.push_back(NumMul);
	v.push_back(NumDiv);

	for (auto t : v) {
		cout << t(2, 2) << endl;
	}

	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << (*it)(2, 2) << endl;
	}
}