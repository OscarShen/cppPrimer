#include "quote.h"
#include "bulk_quote.h"
#include "disc_quote.h"
#include <iostream>

double print_total(std::ostream& os, const Quote& item, size_t n);

int main() {
}

double print_total(std::ostream & os, const Quote & item, size_t n)
{
	double&& res = item.net_price(n);
	os << "ISBN: " << item.isbn() << "# sold:" << n << " total due: " << res << std::endl;
	return 0.0;
}
