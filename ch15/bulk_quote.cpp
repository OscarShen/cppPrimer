#include "bulk_quote.h"

Bulk_quote::Bulk_quote(std::size_t min_qty, double disc) :min_qty(min_qty), discount(disc) {}

Bulk_quote::Bulk_quote(const std::string &book, double sales_price, std::size_t min_qty, double disc)
	:Quote(book, sales_price), min_qty(min_qty), discount(disc) {}

double Bulk_quote::net_price(std::size_t count) const
{
	if (count >= min_qty)
		return count*(1 - discount)*price;
	else
		return count*price;
}
