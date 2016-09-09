#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;

int main() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (auto it = v.begin(); it != v.end(); it++) {
		*it *= 2;
		cout << *it << endl;
	}
}