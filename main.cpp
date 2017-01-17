
#include <string>
#include <vector>

#include "include/Grid.hpp"

int main(int argc, char* argv[]) {
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

  int choice = 0;

  do {
    std::cout << std::endl;
    std::cout << "1 - Play" << std::endl;
    std::cout << "2 - Solve" << std::endl;
    std::cout << "3 - Quit" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
      std::cout << "Implementation in progress.";
    } else if (choice == 2) {
      Grid solvedGrid{grid.solve()};
      std::cout << "Solved grid:" << std::endl;
      std::cout << solvedGrid << std::endl;
    } else if (choice == 3) {
      std::cout << "Bye then!" << std::endl;
    } else {
      std::cout << "Wrong choice, try again." << std::endl;
    }
  } while (choice != 1 && choice != 2 && choice != 3);

  return 0;
}
