
#include <iostream>

#include "Game.hpp"

Game::Game() {}

void Game::play() { //TODO: implement game loop
  int x, y, state;

  // Asks for a move until the grid is completed
  while (!grid.isComplete()) {
    // Keeps asking while the user hasn't picked correct numbers yet
    do {
      std::cout << "Choose 2 numbers (column and row) followed by 0, 1 or 2 (empty, filled or denied respectively), in the form 'x y z': ";
      std::cin >> x >> y >> state;
      std::cout << std::endl;
    } while (x < 1 && x > grid.getBoardHeight()
             && y < 1 && y > grid.getBoardWidth()
             && state < 0 && state > 2);

    // Defines the chosen tile's state to the one chosen
    grid.getBoard()[y - 1][x - 1].state = static_cast<State>(state);
    std::cout << grid << std::endl << std::endl;
  }

  std::cout << "Well done!" << std::endl;
  grid.clear();
}
