#include <string>
#include <deque>
#include <iostream>
#include <iterator>

using std::string;
using std::deque;
using std::iterator;

void main() {
	deque<string> d;
	string s;
	while (std::cin >> s) {
		d.push_back(s);
	}

	auto iter = d.begin();
	while (iter != d.end()) {
		std::cout << *iter << std::endl;
		++iter;
	}
}