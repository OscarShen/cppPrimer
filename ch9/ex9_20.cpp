#include <string>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>

using std::string;
using std::deque;
using std::iterator;
using std::list;

void main() {
	list<int> l{ 1,2,4,35,3,1,4,67,6,2,4,7,4,2,47,3,46,3 };
	auto iter = l.begin();
	deque<int> even;
	deque<int> odd;
	while (iter != l.end()) {
		if (*iter % 2 == 0)
			even.push_back(*iter);
		else
			odd.push_back(*iter);
		++iter;
	}
	auto iter1 = even.begin();
	auto iter2 = odd.begin();
	while (iter1 != even.end()) {
		std::cout << *iter1 << " ";
		++iter1;
	}
	std::cout << std::endl;

	while (iter2 != odd.end()) {
		std::cout << *iter2 << " ";
		++iter2;
	}
	std::cout << std::endl;
}