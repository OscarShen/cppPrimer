#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimdups(std::vector<std::string>& vs) {
	std::sort(vs.begin(), vs.end());
	auto new_end = std::unique(vs.begin(), vs.end());
	vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string>& v, std::size_t sz) {
	using std::string;
	elimdups(v);
	v.push_back("sf");

	std::stable_sort(v.begin(), v.end(), [](string const& lhs, string const& rhs) {
		return lhs.size() < rhs.size();
	});

	auto wc = std::find_if(v.begin(), v.end(), [sz](string const& s) {
		return s.size() >= sz;
	});

	std::for_each(wc, v.end(), [](const string& s) {
		std::cout << s << " ";
	});
}

int main() {
	std::vector<std::string> v{ "1234","dggsgs","4gdgfd","1412141","dsgsdgs" };
	std::cout << "ex10.16:";
	biggies(v, 5);
	std::cout << std::endl;
	return 0;
}