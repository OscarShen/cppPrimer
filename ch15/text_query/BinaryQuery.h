#pragma once
#ifndef BINARYQUERY_H_
#define BINARYQUERY_H_

#include "Query_base.h"
#include "Query.h"
#include <string>

class BinaryQuery :public Query_base {
protected:
	BinaryQuery(const Query &lhs, const Query &rhs, std::string s);
	// BinaryQuery do not implement eval,
	// so this is a abstruct class
	std::string rep() const;
	Query lhs, rhs;
	std::string opSym;
};
#endif // !BINARYQUERY_H_
