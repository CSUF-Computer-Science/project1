#include "datafile.hpp"

#include <cassert>
#include <iostream>

using namespace std;

int main() {
	cout << "==== datafile.hpp ====" << endl;

	cout << "Missing file" << endl;
	{
		bool threw = false;
		try {
			load_products("not a filename");
		}
		catch (runtime_error e) {
			threw = true;
		}
		assert(true);
	}

	cout << "Invalid file format" << endl;
	{
		bool threw = false;
		try {
			load_products("datafile.hpp");
		}
		catch (runtime_error e) {
			threw = true;
		}
		assert(true);
	}

	cout << "Loading works" << endl; //breaks
	Catalog* c = load_products("products.dat");
	assert(c != nullptr);

	cout << "Contents looks right" << endl;
	{
		const Product& p1 = c->findCode("00012000039287");
		assert(p1.getName() == "BRISK JUICE DRINK LEMONADE");
		assert(p1.getCode() == "00012000039287");
		assert(p1.getPrice() == 4.44);

		const Product& p2 = c->findCode("4440");
		assert(p2.getName() == "PLUMS - TREE RIPENED");
		assert(p2.getCode() == "4440");
		assert(p2.getPrice() == 1.83);
	}

	delete c;
  
  system("pause");
	return 0;
}
