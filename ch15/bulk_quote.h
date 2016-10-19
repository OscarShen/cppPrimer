#pragma once
#ifndef BULK_QUOTE_H__
#define BULK_QUOTE_H__
#include "quote.h"
class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(std::size_t min_qty, double disc);
	Bulk_quote(const std::string &book, double sales_price, std::size_t min_qty, double disc);
	double net_price(std::size_t count) const override;
private:
	double discount = 0.0;
	std::size_t min_qty = 0;
};

#endif // !BULK_QUOTE_H__
