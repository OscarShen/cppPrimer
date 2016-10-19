#include "quote.h"
#include "bulk_quote.h"

Bulk_quote::Bulk_quote(const std::string &book, double sales_price, std::size_t min_qty, double disc)
	:Disc_quote(book, sales_price,min_qty,disc) {}

double Bulk_quote::net_price(std::size_t count) const
{
	if (count >= this->quantity)
		return count * (1 - discount) * price;
	else
		return count * price;
}
