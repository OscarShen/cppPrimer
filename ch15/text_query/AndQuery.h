#pragma once
#ifndef ANDQUERY_H_
#define ANDQUERY_H_

#include "Query.h"
#include "BinaryQuery.h"
class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &lhs, const Query &rhs);
	AndQuery(const Query &lhs, const Query &rhs) :BinaryQuery(lhs, rhs, "&") {}
	QueryResult eval(const TextQuery &t) const override;
};

#endif // !ANDQUERY_H_
