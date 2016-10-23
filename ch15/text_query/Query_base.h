#pragma once
#ifndef QUERY_BASE_H_
#define QUERY_BASE_H_

#include <string>

#include "Query.h"
#include "../../ch12/ex12_27.h"

class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	// ���麯��
	virtual QueryResult eval(const TextQuery &textQuery) const = 0;
	virtual std::string rep() const = 0;
};

#endif // !QUERY_BASE_H_
