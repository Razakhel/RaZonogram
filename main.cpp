
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

  Grid solvedGrid{grid.solve()};
  std::cout << "Solved grid:" << std::endl;
  std::cout << solvedGrid << std::endl;

  return 0;
}
