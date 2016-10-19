#pragma once
#ifndef BULK_QUOTE_H__
#define BULK_QUOTE_H__
#include "quote.h"
#include "disc_quote.h"
class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price, std::size_t min_qty, double disc);
	double net_price(std::size_t count) const override;
};

#endif // !BULK_QUOTE_H__
