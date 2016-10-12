
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
 
	Product() {
		code = "";
		name = "";
		price = 0;
	}

	Product(const std::string& ucode, const std::string& uname, double uprice) {
  // TODO: implement this function properly
	if(uprice < 0) {
		throw std::invalid_argument("Must be positive.");
	}
	else {
		code = ucode;
		name = uname;
		price = uprice;
	}
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
    // TODO: implement this function properly
	  if (maxProducts <= 0) {
		throw std::invalid_argument("Must be positive.");
	}
	else {
		max = maxProducts;
		ptr = new Product[max];
	}
  }
  
  ~Catalog() {
    // TODO: implement this function properly
	  delete[] ptr;
  }

  // Accessors.
  int getMaxProducts() const {
    // TODO: implement this function properly
		  return max;
  }

  int getNumProducts() const {
    // TODO: implement this function properly
	  return n;
  }

  // Return true when the catalog cannot fit any more products.
  bool isFull() const {
    // TODO: implement this function properly
	  return n == max;
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
  void addProduct(const std::string& ucode,
                  const std::string& uname,
                  double uprice) {
    // TODO: implement this function properly
	  for (int i = 0; i < n; i++) {
		  if (ptr[i].getCode() == ucode) {
			  throw std::invalid_argument("Already in database.");
		  }
	  }
		  if (uprice < 0) {
			  throw std::invalid_argument("Price is invalid.");
		  }
		  else if (isFull()) {
			  throw std::overflow_error("Catalog is full.");
		  }
		  else {
			  ptr[n] = Product(ucode, uname, uprice);
			  n++;
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
  const Product& findCode(const std::string& ucode) const {
    // TODO: implement this function properly
	  for (int i = 0; i < n; i++) {
		  if (ptr[i].getCode() == ucode) {
			  return ptr[i];
		  }
	  }
	  throw std::invalid_argument("Code not found.");
  }

private:
  // TODO: add data members
	int n, max; //index of products, max number of products
	Product *ptr;
};
