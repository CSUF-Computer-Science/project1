

// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.


#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>
#include <vector>
using namespace std;

// A product represents one particular kind of product, such as apples
// or cereal.
class Product {
private:
	std::string code;
	std::string name;
	double price;
	friend class Catalog;
public:
	// Create a product with a given code, name, and price.
	//
	// code is intended to be a UPC code (bar code) or PLU code in a
	// string.
	//
	// name may be any string.
	//
	// price is in units of dollars. It must be positive, or else this
	// function throws std::invalid_argument.
	Product(){}

	Product(const std::string& code1, const std::string& name1, double price1) {
		if (price1 <= 0)
		{
			
			throw std::invalid_argument("Cost must be positive!");
		}
		else
		{
			code = code1;
			name = name1;
			price = price1;
		}
	}
	
	~Product() { }
	void set(const std::string& code1, const std::string& name1, double price1)
	{
		code = code1;
		name = name1;
		price = price1;
	}

	// Accessors.
	const std::string& getCode() const { return code; }
	const std::string& getName() const { return name; }
	double getPrice() const { return price; }


};

// A catalog represents a collection of all of the products available
// at a store.
class Catalog {
private:
	int maxProducts;
	vector<Product>list;
public:
	// Create a new catalog.
	//
	// maxProducts is the maximum number of products that can be
	// stored. It must be positive, or else this function throws
	// std::invalid_argument.
	Catalog() {}

	Catalog(int maxProducts1) {
		if (maxProducts1 <= 0)
		{
			throw std::invalid_argument("Max cannot be less than 0!");
		}
		else
		{
			maxProducts = maxProducts1;
		}

		
		
	}
	/*Catalog(const Catalog &cpy)
	{
		maxProducts = cpy.getMaxProducts();
		for (int i = 0; i < list.size(); i++)
		{
			list[i].set(cpy.list[i].getCode(), cpy.list[i].getName(), cpy.list[i].getPrice());
		}
	}
*/
	~Catalog() 
	{
	//	vector<Product>clear;
		//vector<Product>().swap(clear);
	}

	// Accessors.
	int getMaxProducts() const {
		return maxProducts;
		
	}

	int getNumProducts() const {
		return list.size();
		
	}

	// Return true when the catalog cannot fit any more products.
	bool isFull() const {
		if (getNumProducts() == getMaxProducts())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Add a new product to the catalog with a given code and name.
	//
	// code, name, and price have the same meaning as in a Product. If
	// price is invalid, throw std::invalid_argument.
	//
	// If this catalog is already full, throw overflow_error.
	//
	// Code must be different from all the product codes already in the
	// database. If it's not, throw std::invalid_argument.
	void addProduct(const std::string& code1, const std::string& name1, double price1) 
	{
		if (isFull() == true)
			{
				throw std::overflow_error("Catalog is already full");
			}
		for(int i = 0; i != list.size(); i++)
		{
			if (list[i].getCode() == code1)
			{
				throw std::invalid_argument("Item already is on catalog!");
			}
		}
		Product temp(code1, name1, price1);
		list.push_back(temp);
		
		
	}

	// Find a product by its code.
	//
	// code is a product code.
	//
	// Returns a const reference to the product with the matching code.
	//
	// Throw std::invalid_argument if no product with that code exists
	// in the catalog.
	
	const Product& findCode(const std::string& code1) const
	{
		bool keepGoing = true;
		
		for (int i = 0; i != list.size(); i++)
		{
			if (list[i].getCode() == code1)
			{
				
				keepGoing = false;
				return list[i];
			}
			
		}
		if(keepGoing == true)
		{
			throw std::invalid_argument("Code doesnt exist!");
		}
		
	}


};
