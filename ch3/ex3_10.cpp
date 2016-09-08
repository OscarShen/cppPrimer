#include <string>
#include <iostream>
using namespace std;

int main() {
	while (getline(cin, str)) {
		for (auto i : str) {
			if (!ispunct(i))
				cout << i;
		}
		cout << endl;
	}
	return 0;
}