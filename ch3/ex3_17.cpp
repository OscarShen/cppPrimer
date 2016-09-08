#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	string temp;
	vector<string> v;
	while (getline(cin, s)) {
		v.push_back(s);
	}

	for (auto& str : v) {
		for (auto& c : str) {
			c = toupper(c);
		}
	}

	for (decltype(v.size()) i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}