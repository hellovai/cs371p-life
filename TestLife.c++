// ------------------------------------
// projects/allocator/TestAllocator.c++
// Copyright (C) 2014
// Glenn P. Downing
// ------------------------------------

// --------
// includes
// --------

#include <algorithm>  // count
#include <memory>     // allocator

#include "gtest/gtest.h"

#include "Life.h"

// -------------
// TestAllocator
// -------------

TEST(Cell, ConwayCell1) {
  ConwayCell c;
  ASSERT_EQ(c.print(), CONWAY_DEAD);
}

TEST(Cell, ConwayCell2) {
  ConwayCell c;
  c.setValue(CONWAY_ALIVE);
  ASSERT_EQ(c.print(), CONWAY_ALIVE);
}

TEST(Cell, ConwayCell3) {
  ConwayCell c;
  c.evolve(3);
  ASSERT_EQ(c.print(), CONWAY_ALIVE);
}

TEST(Cell, ConwayCell4) {
  ConwayCell c;
  c.evolve(0);
  ASSERT_EQ(c.print(), CONWAY_DEAD);
}

TEST(Cell, ConwayCell5) {
  ConwayCell c;
  c.setValue(CONWAY_ALIVE);
  c.evolve(2);
  ASSERT_EQ(c.print(), CONWAY_ALIVE);
}

TEST(Cell, ConwayCell6) {
  ConwayCell c;
  c.setValue(CONWAY_ALIVE);
  c.evolve(0);
  ASSERT_EQ(c.print(), CONWAY_DEAD);
}

TEST(Cell, FredkinCell1) {
  FredkinCell c;
  ASSERT_EQ(c.print(), FREDKIN_DEAD);
}

TEST(Cell, FredkinCell2) {
  FredkinCell c;
  c.setValue('0');
  ASSERT_EQ(c.print(), '0');
}

TEST(Cell, FredkinCell3) {
  FredkinCell c;
  c.evolve(3);
  ASSERT_EQ(c.print(), '0');
}

TEST(Cell, FredkinCell4) {
  FredkinCell c;
  c.evolve(4);
  ASSERT_EQ(c.print(), FREDKIN_DEAD);
}

TEST(Cell, FredkinCell5) {
  FredkinCell c;
  c.setValue('0');
  c.evolve(1);
  ASSERT_EQ(c.print(), '1');
}

TEST(Cell, FredkinCell6) {
  FredkinCell c;
  c.setValue('0');
  c.evolve(0);
  ASSERT_EQ(c.print(), FREDKIN_DEAD);
}


TEST(Cell, Cell1) {
  Cell c;
  ASSERT_EQ(c.print(), FREDKIN_DEAD);
}

TEST(Cell, Cell2) {
  Cell c;
  c.setValue('0');
  ASSERT_EQ(c.print(), '0');
}

TEST(Cell, Cell3) {
  Cell c;
  c.evolve(3);
  ASSERT_EQ(c.print(), '0');
}

TEST(Cell, Cell4) {
  Cell c;
  c.evolve(4);
  ASSERT_EQ(c.print(), FREDKIN_DEAD);
}

TEST(Cell, Cell5) {
  Cell c;
  c.setValue('0');
  c.evolve(1);
  ASSERT_EQ(c.print(), '1');
}

TEST(Cell, Cell6) {
  Cell c;
  c.setValue('0');
  c.evolve(0);
  ASSERT_EQ(c.print(), FREDKIN_DEAD);
}

TEST(Cell, Cell7) {
  Cell c;
  c.setValue('*');
  c.evolve(0);
  ASSERT_EQ(c.print(), CONWAY_DEAD);
}

TEST(Cell, Cell8) {
  Cell c;
  c.setValue('1');
  c.evolve(1);
  ASSERT_EQ(c.print(), CONWAY_ALIVE);
}

TEST(Life, life0) {
  std::istringstream r("ConwayCell\n2\n2\n..\n..\n");
  std::ostringstream o;
  Life<ConwayCell> test(2,2);
  test.parse(r);
  test.print(o);
  ASSERT_EQ("Generation = 0, Population = 0.\n..\n..\n", o.str());
}

TEST(Life, life1) {
  std::istringstream r("ConwayCell\n2\n2\n..\n.*\n");
  std::ostringstream o;
  Life<ConwayCell> test(2,2);
  test.parse(r);
  test.print(o);
  ASSERT_EQ("Generation = 0, Population = 1.\n..\n.*\n", o.str());
}

TEST(Life, life2) {
  std::istringstream r("FredkinCell\n2\n2\n--\n--\n");
  std::ostringstream o;
  Life<FredkinCell> test(2,2);
  test.parse(r);
  test.print(o);
  ASSERT_EQ("Generation = 0, Population = 0.\n--\n--\n", o.str());
}

TEST(Life, life3) {
  std::istringstream r("FredkinCell\n2\n2\n--\n-1\n");
  std::ostringstream o;
  Life<FredkinCell> test(2,2);
  test.parse(r);
  test.print(o);
  ASSERT_EQ("Generation = 0, Population = 1.\n--\n-1\n", o.str());
}
