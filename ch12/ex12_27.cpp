
#include "ex12_27.h"

TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>) {
	std::string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " 
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}

void runQueries(std::ifstream& infile) {
	TextQuery tq(infile);
	while (true) {
		std::cout << "enter a word" << std::endl;
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending) {
	return ctr > 1 ? word + ending : word;
}

std::set<QueryResult::line_no>::const_iterator QueryResult::begin() const
{
	return lines->cbegin();
}

std::set<QueryResult::line_no>::const_iterator QueryResult::end() const
{
	return lines->cend();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file()
{
	return file;
}
