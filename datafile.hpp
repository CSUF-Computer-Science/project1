
// datafile.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Function to load a product catalog from a text file into a Catalog
// object.

#pragma once

#include <fstream>
#include <string>
#include <stdexcept>

#include "catalog.hpp"

// Helper to throw std::runtime_error due to a parse error in the data
// file.
void throw_decode_exception() {
  throw std::runtime_error("product database decode error");
}

// Load products from a .dat file with the given filename.
//
// Returns a pointer to a Catalog object containing all the products
// in the data file. The returned object is allocated on the heap with
// new, so the caller is responsible for eventually deleting it.
//
// Throws std::runtime_error if the file cannot be opened, or is not a
// properly formatted .dat file.
Catalog* load_products(const std::string& filename) {
  std::ifstream f(filename.c_str());
  if (!f)
    throw std::runtime_error("cannot open product file");

  // used for individual tokens that we skip over
  std::string s;
  
  getline(f, s);
  if (!f || (s != "PRODUCTS DATABASE"))
    throw_decode_exception();

  int count;
  f >> s >> count;
  if (!f || (s != "COUNT") || (count < 1))
    throw_decode_exception();
  getline(f, s); // newline
  getline(f, s); // blank line

  Catalog* c = new Catalog(count);
  
  for (int i = 0; i < count; ++i) {
    std::string code, name;
    int price_cents;
    f >> s // UPC or PLU
      >> s // CODE
      >> code; // code string
    getline(f, s); // newline
    getline(f, name); // name on its own line
    f >> s // PRICE
      >> s // BY
      >> s // COUNT or POUND
      >> price_cents; // price in cents
    getline(f, s); // newline
    getline(f, s); // blank line

    double price_dollars = static_cast<double>(price_cents) / 100.0;
    
    c->addProduct(code, name, price_dollars);
  }

  if (!f) {
    delete c;
    throw_decode_exception();
  }

  f.close();

  return c;
}
