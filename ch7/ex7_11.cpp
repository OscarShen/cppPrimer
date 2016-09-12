#include <string>
#include "ex7_11.h"

int main() {
	Sales_data item1;
	print(std::cout, item1) << std::endl;

	Sales_data item2("123");
	print(std::cout, item2) << std::endl;

	Sales_data item3("123", 1, 20.00);
	print(std::cout, item3) << std::endl;
}