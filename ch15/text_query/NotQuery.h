#pragma once
#pragma once
#ifndef NOTQUERY_H_
#define NOTQUERY_H_

#include "Query_base.h"
#include "Query.h"
class NotQuery :public Query_base {
	friend Query operator~(const Query &rhs);
	NotQuery(const Query &q) :query(q) {};
	std::string rep() const override;
	QueryResult eval(const TextQuery &textQuery) const override;
	Query query;
};

#endif // !NOTQUERY_H_