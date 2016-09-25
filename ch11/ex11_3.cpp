#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, size_t> word_count;

	std::string word;
	while (std::cin >> word) {
		for (size_t i = 0; i < word.size(); ++i) {
			if (ispunct(word[i])) {
				word.erase(i, 1);
				continue;
			}
			word[i] = tolower(word[i]);
		}
		++word_count[word];
	}

	for (auto const& a : word_count)
		std::cout << a.first << " " << a.second << std::endl;
}