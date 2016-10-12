// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.

#pragma once

#include <stdexcept>
#include <string>

// A product represents one particular kind of product, such as apples
// or cereal.
class Product {
public:
	// Create a product with a given code, name, and price.
	//
	// code is intended to be a UPC code (bar code) or PLU code in a
	// string.
	//

	Product() {
		code = "NULL";
		name = "NULL";
		price = 0;
	}

	// name may be any string.
	//
	// price is in units of dollars. It must be positive, or else this
	// function throws std::invalid_argument.
	Product(const std::string& _code,
		const std::string& _name,
		double _price) {
		// TODO: implement this function properly
		if (_price < 0 || _code.length() > 14) {
			throw std::invalid_argument("not implemented yet");
		}
		else {
			name = _name;
			code = _code;
			price = _price;
		}
	}


	// Accessors.
	const std::string& getCode() const { return code; }
	const std::string& getName() const { return name; }
	double getPrice() const { return price; }

private:
	std::string code, name;
	double price;
};

// A catalog represents a collection of all of the products available
// at a store.
class Catalog {
public:
	// Create a new catalog.
	//
	// maxProducts is the maximum number of products that can be
	// stored. It must be positive, or else this function throws
	// std::invalid_argument.
	Catalog(int _maxProducts) {
		// TODO: implement this function properly
		if (maxProducts > 130000)
		{
			maxProducts = 130000;
		}
		if (_maxProducts <= 0)
		{
			throw std::invalid_argument("not implemented yet");
		}
		else 
		{
			maxProducts = _maxProducts;
			ptr = new Product[maxProducts];
		}

	}

	~Catalog() {
		// TODO: implement this function properly
		delete[] ptr;
		ptr = NULL;
			
	}

	// Accessors.
	int getMaxProducts() const {
		// TODO: implement this function properly
		/*if (maxProducts < 0)
			throw std::invalid_argument("not implemented yet");
		else*/
			return maxProducts;
	}

	int getNumProducts() const {
		// TODO: implement this function properly
		return numProducts;
	}

	// Return true when the catalog cannot fit any more products.
	bool isFull() const {
		// TODO: implement this function properly
		if (numProducts == maxProducts) {
			return true;

		}
		else {
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
	void addProduct(const std::string& _code,
		const std::string& _name,
		double _price) {
		// TODO: implement this function properly
		
		if (isFull())
		{
			throw std::overflow_error("No entry can be made, Catalog is full");
		}
		if(!isFull())
		{ 
			if (_price <= 0.0)
				throw std::invalid_argument("Error: Price must be greater than 0.");
			else
			{ 
				for (int i = 0; i < numProducts; i++)
				{
					if (ptr[i].getCode() == _code)
						throw std::invalid_argument("not implemented yet");
				}
			}
		}
	Product temp(_code, _name, _price);
	ptr[numProducts] = temp;
	numProducts++;
	}

	// Find a product by its code.
	//
	// code is a product code.
	//
	// Returns a const reference to the product with the matching code.
	//
	// Throw std::invalid_argument if no product with that code exists
	// in the catalog.
	const Product& findCode(const std::string& _code) const 
	{
		// TODO: implement this function properly
		for (int i = 0; i < numProducts; i++)
		{
			if (ptr[i].getCode() == _code)
			{
				return ptr[i];
			}
			
		}
	throw std::invalid_argument("not implemented yet");
	}


private:
	// TODO: add data members
	Product *ptr;
	int maxProducts;
	int numProducts;
};
