#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using std::string;

int main() {
	std::ifstream ifs("E:/demo.txt");
	std::istream_iterator<string> in(ifs), eof;
	std::vector<string> v;
	while (in!=eof)
	{
		v.push_back(*in++);
	}
	for (auto it = v.cbegin(); it != v.cend(); ++it)
		std::cout << *it << std::endl;
}
