
#ifndef TILE_HPP
#define TILE_HPP

enum State { EMPTY = 0, FILLED, DENIED };

class Tile {
public:
  Tile() : state{EMPTY} {}

  State state;
};

#endif // TILE_HPP
