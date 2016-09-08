#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "hello, how are you?";
	cout << str.size() << endl;
	decltype(str.size()) i;
	for (i = 0; i < str.size(); i++) {
		str[i] = 'Y';
	}
	cout << str << endl;

	i = 0;
	while (i < str.size()) {
		str[i] = 'X';
		++i;
	}
	cout << str << endl;
}