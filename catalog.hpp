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
	// name may be any string.
	//
	// price is in units of dollars. It must be positive, or else this
	// function throws std::invalid_argument.
	Product(){} //default constructor
	Product(const std::string& code, const std::string& name, double price) {
		// TODO: implement this function properly
		if (price < 0) throw std::invalid_argument("The price must be more than one dollar.");
		this->price = price;
		this->code = code;
		this->name = name;
	}

	~Product() { }

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
	Catalog(int maxProducts) {
		if (maxProducts <= 0) throw std::invalid_argument("The product must be at least one.");
		else if (maxProducts >= 65535) throw std::invalid_argument("maxProducts too high");
		else{
			this->maxProducts = maxProducts;
			catalogArray = new Product[maxProducts];
		}
	}

	~Catalog() { delete[] catalogArray;}

	// Accessors.
	int getMaxProducts() const { return maxProducts;}

	int getNumProducts() const {
		if (numProducts < 0 && numProducts > maxProducts){
			throw std::logic_error("not implemented yet");
		}
		else{
			return numProducts;
		}
	}

	// Return true when the catalog cannot fit any more products.
	bool isFull() const {
		if (getNumProducts() == maxProducts) return true;
		else return false;
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
	void addProduct(const std::string& code, const std::string& name, double price) {
		if (isFull()) throw std::overflow_error("Catalog is full");
		if (price < 0) throw std::invalid_argument("invalid price");
		else
		{
			for (int i = 0; i < getNumProducts(); i++)
			{
				if (catalogArray[i].getCode() == code)
					throw std::invalid_argument("Code already exits");
			}
			Product temp(code, name, price);
			catalogArray[numProducts] = temp;
			numProducts++;
		}
	}

	// Find a product by its code.
	//
	// code is a product code.
	//
	// Returns a const reference to the product with the matching code.
	//
	// Throw std::invalid_argument if no product with that code exists
	// in the catalog.
	const Product& findCode(const std::string& code) const {
		for (int i = 0; i < getNumProducts(); i++)
		{
			if (catalogArray[i].getCode() == code)
				return catalogArray[i];
		}
		throw std::invalid_argument("No Product exists");
	}

private:
	int maxProducts; //size of array
	int numProducts = 0; //index to each product
	Product* catalogArray;

};
