#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <sstream>
using std::ifstream;
using std::string;
using std::iostream;
void word_transform(ifstream& map_file, ifstream& input) {
	auto trans_map = build_map(map_file);
	string text;
	while (getline(input, text)) {
		std::istringstream stream(text);
		string word;
		bool first_word = true;
		while (stream >> word) {
			if (first_word)
				first_word = false;
			else
				std::cout << " ";
			std::cout << trans_word(word, trans_map);
		}
		std::cout << std::endl;
	}
}

string& trans_word(string& word, std::map<string, string>& trans_map) {
	auto map_it = trans_map.find(word);
	if (map_it != trans_map.cend())
		return map_it->second;
	else
		return word;
}

std::map<string, string> build_map(ifstream& map_file) {
	std::map<string, string> trans_map;
	string key;
	string value;

	while (map_file >> key&&getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value;
		else
			throw std::runtime_error("no rule for " + key);
	return trans_map;
}


int main() {
}
