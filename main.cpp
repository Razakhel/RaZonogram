
#include <string>
#include <vector>

#include "include/Game.hpp"
#include "include/Grid.hpp"

int main(int argc, char* argv[]) {
  Game game;
  Grid grid;

  if (argc == 2) {
    if (!grid.loadFromFile(argv[1]))
      std::cerr << "Error while opening the file." << std::endl;
  } else {
    std::cerr << "No input file provided, exiting." << std::endl;
    return 1;
  }

  std::cout << "Original grid:" << std::endl;
  std::cout << grid << std::endl;
  game.setGrid(grid);

  int choice = 0;

  do {
    std::cout << std::endl;
    std::cout << "1 - Play" << std::endl;
    std::cout << "2 - How to play" << std::endl;
    std::cout << "3 - Solve" << std::endl;
    std::cout << "4 - Quit" << std::endl;
    std::cin >> choice;

    if (choice == 1) { // Playing the game
      std::cout << "Implementation in progress." << std::endl;
      game.play();
    } else if (choice == 2) { // Printing the game explanations
      std::cout << "Implementation in progress." << std::endl;
    } else if (choice == 3) { // Solving the grid
      std::cout << "Solved grid:" << std::endl << grid.solve() << std::endl;
    } else if (choice == 4) { // Exiting the game
      std::cout << "Bye then!" << std::endl;
    } else { // Number entered nonexistant
      std::cout << "Wrong choice, try again." << std::endl;
    }
  } while (choice != 4);

  return 0;
}
