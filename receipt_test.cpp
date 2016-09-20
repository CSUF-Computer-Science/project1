
#include "receipt.hpp"

#include <cassert>
#include <iostream>

using namespace std;

int main() {
  cout << "==== receipt.hpp ====" << endl;

  Product cheese("123", "cheese", 8.0);
  
  cout << "ReceiptEntry constructor, accessors" << endl;
  {
    ReceiptEntry x(cheese, 4.0);
    assert( (&cheese) == (&x.getProduct()) );
    assert( x.getUnits() == 4.0 );
  }

  Receipt r(3);

  cout << "Receipt constructor and accessors" << endl;
  {
    assert(r.getMaxEntries() == 3);
    assert(r.getNumEntries() == 0);
    assert(!r.isFull());
  }

  Catalog c(4);
  c.addProduct("100", "milk", 8.0);
  c.addProduct("101", "water", 1.0);
  c.addProduct("102", "cereal", 4.0);
  
  cout << "add entries" << endl;
  {
    r.addEntry(c, "101", 1.0);
    assert(r.getNumEntries() == 1);
    assert(!r.isFull());
    
    r.addEntry(c, "100", 2.0);
    assert(r.getNumEntries() == 2);
    assert(!r.isFull());
  }

  cout << "add entry can't find code" << endl;
  {
    bool thrown = false;
    try {
      r.addEntry(c, "99", 1.0);
    } catch (invalid_argument e) {
      thrown = true;
    }
    assert(thrown);
  }


  cout << "receipt becomes full" << endl;
  {
    r.addEntry(c, "102", 3.0);
    assert(r.getNumEntries() == 3);
    assert(r.isFull());
  }

  cout << "receipt already full" << endl;
  {
    bool thrown = false;
    try {
      r.addEntry(c, "102", 3.0);
    } catch (overflow_error e) {
      thrown = true;
    }
    assert(thrown);
  }

  cout << "get entries" << endl;
  {
    assert(r.getEntry(0).getProduct().getCode() == "101");
    assert(r.getEntry(0).getUnits() == 1.0);

    assert(r.getEntry(1).getProduct().getCode() == "100");
    assert(r.getEntry(1).getUnits() == 2.0);

    assert(r.getEntry(2).getProduct().getCode() == "102");
    assert(r.getEntry(2).getUnits() == 3.0);

    bool thrown = false;
    try {
      r.getEntry(-1);
    } catch (out_of_range e) {
      thrown = true;
    }
    assert(thrown);

    thrown = false;
    try {
      r.getEntry(4);
    } catch (out_of_range e) {
      thrown = true;
    }
    assert(thrown);
  }

  cout << "grand total" << endl;
  {
    Receipt empty(10);
    assert(empty.grandTotal() == 0.0);

    assert(r.grandTotal() == (1.0*1.0 + 2.0*8.0 + 3.0*4.0));
  }

  return 0;
}
