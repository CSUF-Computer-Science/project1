
// receipt.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that represent a customer receipt.

#pragma once

#include <stdexcept>

#include "catalog.hpp"

// A ReceiptEntry is one line item on a receipt. Each entry is defined
// by a product, and the number of that product that were purchased.
class ReceiptEntry {
public:
  // Constructor.
  //
  // product is a const reference to a Product object.
  //
  // units is a number representing how many products were
  // purchased. It must be positive, or else this function throws
  // std::invalid_argument.
  ReceiptEntry(const Product& product, double units) {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  // Accessors.
  const Product& getProduct() const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }
  
  double getUnits() const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }
  
  // Compute the cost of this entry, which should be equal to the
  // product's price multiplied by the number of units.
  double cost() const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }
  
private:
  // TODO: add data members
};

// A receipt represents an entire transaction. It is a collection of
// ReceiptEntry objects.
class Receipt {
public:
  // Create a new Recipt.
  //
  // maxEntries is the maximum number of entries that can be
  // stored. It must be positive, or else this function throws
  // std::invalid_argument.
  Receipt(int maxEntries) {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  // Destructor.
  ~Receipt() {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  // Accessors.
  int getMaxEntries() const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  int getNumEntries() const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  // Return true when the catalog cannot fit any more products.
  bool isFull() const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  // Accessor for the entry at a given index.
  //
  // index must be >= 0 and < getNumEntries(), or else this function
  // throws std::out_of_range.
  const ReceiptEntry& getEntry(int index) const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  // Add an entry to the receipt.
  //
  // catalog is a const reference to a Catalog object.
  //
  // code is a product code, the same as in the catalog.
  //
  // units is the number of units perchased, the same as for a
  // ReceiptEntry.
  //
  // This function has the effect of increasing the number of entries
  // in the receipt. The new entry is added at the highest index so
  // far.
  //
  // If the code does not exist or units is not positive, throw
  // std::invalid_argument.
  //
  // If the receipt is already full, throws std::overflow_error.
  void addEntry(const Catalog& catalog,
                const std::string& code,
                double units) {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

  // Compute the grand total of the receipt. This is the sum of the
  // costs of each entry in the receipt.
  double grandTotal() const {
    // TODO: implement this function properly
    throw std::logic_error("not implemented yet");
  }

private:
  // TODO: add data members
};
