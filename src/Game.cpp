
#include <iostream>

#include "Game.hpp"

Game::Game() {}

void Game::play() { //TODO: implement game loop
  int x, y, state;

  while (!grid.isComplete()) {
    do {
      std::cout << "Choose 2 numbers (column and row) followed by 0, 1 or 2 (empty, filled or denied respectively), in the form 'x y z': ";
      std::cin >> x >> y >> state;
      std::cout << std::endl;

      grid.getBoard()[y - 1][x - 1].state = static_cast<State>(state);
      std::cout << grid << std::endl << std::endl;
    } while (x >= 1 && x <= grid.getBoardHeight()
             && y >= 1 && y <= grid.getBoardWidth()
             && state >= 0 && state <= 2);
  }
}
