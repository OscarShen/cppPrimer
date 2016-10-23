#ifndef EX12_27_H_
#define EX12_27_H_

#include <fstream>
#include <iostream>
#include <string>;
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <sstream>

class TextQuery;
class QueryResult;

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map < std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
		:sought(s), lines(p), file(f) {}
	std::set<QueryResult::line_no>::const_iterator begin() const;
	std::set<QueryResult::line_no>::const_iterator end() const;
	std::shared_ptr<std::vector<std::string>> get_file();
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};
#endif // !EX12_27_H_