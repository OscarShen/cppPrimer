#include "AndQuery.h"
#include <algorithm>
#include <iterator>
Query operator&(const Query & lhs, const Query & rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery & t) const
{
	auto left = lhs.eval(t), right = rhs.eval(t);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), 
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}