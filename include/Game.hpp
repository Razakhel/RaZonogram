
#ifndef GAME_HPP
#define GAME_HPP

#include "Grid.hpp"

class Game {
public:
  Game();

  Grid& getGrid() { return grid; }
  void setGrid(Grid& grid) { this->grid = grid; }

  void play();

private:
  Grid grid;
};

#endif // GAME_HPP
