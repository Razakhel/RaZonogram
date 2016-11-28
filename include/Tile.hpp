
#ifndef TILE_HPP
#define TILE_HPP

class Tile {
public:
  Tile() : state{EMPTY} {}

  enum STATES { EMPTY = 0, FILLED, DENIED };

private:
  bool state;
};

#endif // TILE_HPP
