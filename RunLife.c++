// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl

// ----
// main
// ----

#include "Life.h"

int main() {
  using namespace std;

  // -----------------
  // Conway Cell 21x13
  // -----------------
  cout << "*** Life<ConwayCell> 21x13 ***" << endl << endl;
  {
    Life<ConwayCell> test(21, 13);
    test.parse(std::cin);
    for (int i = 0; i < 12; ++i) {
      test.print(std::cout) << std::endl;
      test.run();
    }
    test.print(std::cout) << std::endl;
  }
  exit(-1);
  /*
  Simulate 12 evolutions.
  Print every grid (i.e. 0, 1, 2, 3, ... 12)
  */

  std::cout << "*** Life<ConwayCell> 20x29 ***" << endl << endl;
  {
    Life<ConwayCell> test(20, 29);
    test.parse(std::cin);
    for (int i = 0; i < 7; ++i) {
      test.print(std::cout) << std::endl;
      test.run(4);
    }
    test.print(std::cout) << std::endl;
  }
  /*
  Simulate 28 evolutions.
  Print every 4th grid (i.e. 0, 4, 8, ... 28)
  */

  // ------------------
  // Conway Cell 109x69
  // ------------------

  cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
  {
    Life<ConwayCell> test(109, 69);
    test.parse(std::cin);
    for (int i = 0; i < 10; ++i) {
      test.print(std::cout) << std::endl;
      test.run();
    }
    test.run(273);
    test.print(std::cout) << std::endl;
    test.run(40);
    test.print(std::cout) << std::endl;
    test.run(2500 - 323);
    test.print(std::cout) << std::endl;
  }
  /*
  Simulate 283 evolutions.
  Print the first 10 grids (i.e. 0, 1, 2, ... 9).
  Print the 283rd grid.
  Simulate 40 evolutions.
  Print the 323rd grid.
  Simulate 2177 evolutions.
  Print the 2500th grid.
  */

  // ------------------
  // Fredkin Cell 20x20
  // ------------------

  cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
  {
    Life<FredkinCell> test(20, 20);
    test.parse(std::cin);
    for (int i = 0; i < 5; ++i) {
      test.print(std::cout) << std::endl;
      test.run();
    }
    test.print(std::cout) << std::endl;
  }
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */

  // ----------
  // Cell 20x20
  // ----------

  cout << "*** Life<Cell> 20x20 ***" << endl << endl;
  {
    Life<Cell> test(20, 20);
    test.parse(std::cin);
    for (int i = 0; i < 5; ++i) {
      test.print(std::cout) << std::endl;
      test.run();
    }
    test.print(std::cout);
  }
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */

  return 0;
}
