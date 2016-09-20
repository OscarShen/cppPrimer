#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool more_than_five(const std::string& str) {
	return str.size() >= 5;
}

int main() {
	std::vector<std::string> v{ "asdjfksjd","dkgjkajd","dkgh","sdfks","aa","ddddddddd","a","123","44" };
	auto pivot = std::partition(v.begin(), v.end(), more_than_five);
	for (auto it = v.cbegin(); it != pivot; ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	return 0;
}