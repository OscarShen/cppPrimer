#pragma once
#ifndef WORDQUERY_H_
#define WORDQUERY_H_

#include "Query.h"
#include "Query_base.h"
class WordQuery :public Query_base {
	friend class Query;
	WordQuery(const std::string &s) :query_word(s) {};
	// Implement eval
	QueryResult eval(const TextQuery &t) const override;
	// Implement rep
	std::string rep() const override;
	std::string query_word;
};

#endif // !WORDQUERY_H_
