#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	decltype(v.size()) size = v.size();
	decltype(v.size()) j = size / 2;

	for (int i = 0; i < j; i++) {
		cout << v[i] + v[size - 1 - i] << "\t";
	}

	if (size % 2) {
		cout << v[j] << endl;
	}
	return 0;
}