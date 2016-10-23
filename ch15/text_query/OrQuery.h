#pragma once
#ifndef ORQUERY_H_
#define ORQUERY_H_

#include "Query.h"
#include "BinaryQuery.h"

class OrQuery :public BinaryQuery {
	friend Query operator|(const Query &lhs, const Query &rhs);
	OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
	QueryResult eval(const TextQuery &t) const;
};


#endif // !ORQUERY
