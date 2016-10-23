#include "WordQuery.h"
#include <string>

QueryResult WordQuery::eval(const TextQuery & t) const
{
	return t.query(query_word);
}

std::string WordQuery::rep() const
{
	return query_word;
}
