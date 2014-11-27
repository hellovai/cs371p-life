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

class ConwayCell : public AbstractCell {
 public:
  ConwayCell() : AbstractCell() {}
  ConwayCell(const ConwayCell* const c) { alive = c->alive; }
  virtual ConwayCell* clone() const { return new ConwayCell(this); }

  virtual char print() const { return alive ? CONWAY_ALIVE : CONWAY_DEAD; }

  virtual void evolve(int neighbors) {
    if (!alive && neighbors == 3)
      alive = true;
    else if (alive && (neighbors < 2 || neighbors > 3))
      alive = false;
  }

  virtual void setValue(char c) { alive = (c == CONWAY_ALIVE); }

  virtual bool isNeighbor(int h, int v) const { return true; }
};

class FredkinCell : public AbstractCell {
 private:
  char ageChar() const { return (age > 9) ? FREDKIN_MANY : (age + '0'); }

 public:
  int age = 0;
  FredkinCell() : AbstractCell(), age(0) {}
  FredkinCell(const FredkinCell* const c) : age(c->age) { alive = c->alive; }
  virtual FredkinCell* clone() const { return new FredkinCell(this); }

  virtual char print() const { return alive ? ageChar() : FREDKIN_DEAD; }

  virtual void evolve(int neighbors) {
    if (!alive && (neighbors == 1 || neighbors == 3))
      alive = true;
    else if (alive) {
      if (neighbors == 0 || neighbors == 2 || neighbors == 4)
        alive = false;
      else
        ++age;
    }
  }

  virtual void setValue(char c) {
    alive = !(c == FREDKIN_DEAD);
    age = 0;
    if (alive) {
      age = (c == FREDKIN_MANY) ? 10 : ((int)c - '0');
    }
  }

  virtual bool isNeighbor(int h, int v) const { return h == 0 || v == 0; }
};

class Cell {
  AbstractCell* _c;

 public:
  Cell() : _c(new FredkinCell()) {}
  Cell(const Cell& c) : _c(c._c->clone()) {}

  char print() const { return _c->print(); }

  void evolve(int neighbors) {
    _c->evolve(neighbors);
    FredkinCell* fc = dynamic_cast<FredkinCell*>(_c);
    if (fc != nullptr && fc->age == 2) setValue(CONWAY_ALIVE);
  }

  void setValue(char c) {
    FredkinCell* fc = dynamic_cast<FredkinCell*>(_c);
    if (fc != nullptr && (CONWAY_ALIVE == c || CONWAY_DEAD == c)) {
      delete _c;
      _c = new ConwayCell();
    }
    _c->setValue(c);
  }

  bool isAlive() const { return _c->isAlive(); }

  bool isNeighbor(int h, int v) const { return _c->isNeighbor(h, v); }

  ~Cell() { delete _c; }
};

#endif
