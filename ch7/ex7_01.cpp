#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
	string boolNo;
	unsigned units_sold = 0;
	double revenu = 0.0;
};

int main() {
	Sales_data total;
	if (cin >> total.boolNo >> total.units_sold >> total.revenu) {
		Sales_data trans;
		while (cin >> trans.boolNo >> trans.units_sold >> trans.revenu) {
			if (total.boolNo == trans.boolNo) {
				total.units_sold += trans.units_sold;
				total.revenu += trans.revenu;
			}
			else {
				cout << total.boolNo << " " << total.units_sold << " " << total.revenu << endl;
			}
		}
		cout << total.boolNo << " " << total.units_sold << " " << total.revenu << endl;
	}
	else {
		std::cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}