#include "Life.h"

void ConwayCell::evolve(int neighbors) {
  assert(neighbors >= 0 && neighbors < 9);
  if (!alive && neighbors == 3)
    alive = true;
  else if (alive && (neighbors < 2 || neighbors > 3))
    alive = false;
}

void FredkinCell::evolve(int neighbors) {
  assert(neighbors >= 0 && neighbors < 5);
  if (!alive && (neighbors == 1 || neighbors == 3))
    alive = true;
  else if (alive) {
    if (neighbors == 0 || neighbors == 2 || neighbors == 4)
      alive = false;
    else
      ++age;
  }
}

void FredkinCell::setValue(char c) {
  assert(c == FREDKIN_DEAD || c == FREDKIN_MANY || (c >= '0' && c <= '9'));
  alive = !(c == FREDKIN_DEAD);
  age = 0;
  if (alive) {
    age = (c == FREDKIN_MANY) ? 10 : ((int)c - '0');
  }
}

void Cell::evolve(int neighbors) {
  _c->evolve(neighbors);
  FredkinCell* fc = dynamic_cast<FredkinCell*>(_c);
  if (fc != nullptr && fc->age == 2) setValue(CONWAY_ALIVE);
}

void Cell::setValue(char c) {
  FredkinCell* fc = dynamic_cast<FredkinCell*>(_c);
  if (fc != nullptr && (CONWAY_ALIVE == c || CONWAY_DEAD == c)) {
    delete _c;
    _c = new ConwayCell();
  }
  _c->setValue(c);
}
