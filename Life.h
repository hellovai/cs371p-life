#ifndef __LIFE_H__
#define __LIFE_H__

#include <iostream>

#define CONWAY_DEAD '.'
#define CONWAY_ALIVE '*'
#define FREDKIN_DEAD '-'
#define FREDKIN_MANY '+'

class AbstractCell {
 protected:
  bool alive;

 public:
  virtual bool isAlive() const { return alive; }
  virtual AbstractCell* clone() const = 0;
  virtual char print() const = 0;
  virtual void evolve(int neighbors) = 0;
  virtual void setValue(char c) = 0;
  virtual bool isNeighbor(int change_r, int change_c) const = 0;

  AbstractCell() : alive(false) {}
  virtual ~AbstractCell() {}
};

#endif
