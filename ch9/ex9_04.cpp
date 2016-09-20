#include <vector>
#include <iterator>
#include <iostream>
#include <array>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::iterator;
using std::array;

bool findNum(vector<int>& v, int n);
vector<int>::iterator findIterOfNum(vector<int>& v, int n);

int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9,0,12,11,13,14,16 };
	auto b = findIterOfNum(v, 15);
	if (b != v.end())
		cout << *b << endl;
	array<int, 5> arr = { 1,2,3,4,5 };
	cout << arr[2] << endl;
}

bool findNum(vector<int>& v, int n) {
	auto iter = v.begin();
	auto end = v.end();
	while (iter != end) {
		if (*iter == n)
			return true;
		++iter;
	}
	return false;
}

vector<int>::iterator findIterOfNum(vector<int>& v, int n) {
	auto iter = v.begin();
	auto end = v.end();
	while (iter != end) {
		if (*iter == n)
			return iter;
		++iter;
	}
	return end;
}