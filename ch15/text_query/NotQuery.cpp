#include "Query.h"
#include "NotQuery.h"
#include <memory>
#include "../../ch12/ex12_27.h"
std::string NotQuery::rep() const
{
	return "~(" + query.rep() + ")";
}

QueryResult NotQuery::eval(const TextQuery & textQuery) const
{
	auto result = query.eval(textQuery);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = ret_lines->begin(), end = ret_lines->end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n) {
			ret_lines->insert(n);
		}
		else if (beg != end)
			++beg;
	}
}

Query operator~(const Query & rhs)
{
	return std::shared_ptr<Query_base>(new NotQuery(rhs));
}
