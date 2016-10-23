#include "BinaryQuery.h"

BinaryQuery::BinaryQuery(const Query & lhs, const Query & rhs, std::string s)
	:lhs(lhs), rhs(rhs), opSym(s) {}

std::string BinaryQuery::rep() const 
{
	return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}
