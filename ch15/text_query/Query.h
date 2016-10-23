#pragma once
#ifndef QUERY_H_
#define QUERY_H_

#include "../../ch12/ex12_27.h"
#include "Query_base.h"

#include <iostream>
#include <string>

class Query {
	friend Query operator~(const Query &rhs);
	friend Query operator&(const Query &lhs, const Query &rhs);
	friend Query operator|(const Query &lhs, const Query &rhs);
public:
	Query(const std::string &s);
	// ½Ó¿Úº¯Êý
	QueryResult eval(const TextQuery &t) const;
	std::string rep() const;

private:
	Query(std::shared_ptr<Query_base> query) :q(query) {}
	std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream &os, const Query &query);
#endif // !QUERY_H_
