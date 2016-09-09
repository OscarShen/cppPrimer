
/// List three ways to define a vector and give it ten elements,
/// each with the value 42.
/// Indicate whether there is a preferred way to do so and why.
/// @Author Oscar Shen

#include <iostream>
#include <vector>
using std::vector;

int main() {
	vector<int> v1(10, 42);
	vector<int> v2{ 42,42,42,42,42,42,42,42,42,42 };
	vector<int> v3;
	for (decltype(v3.size()) i = 0; i < 10; i++) {
		v3.push_back(42);
	}
	std::cout << "the first is the best!" << std::endl;
}