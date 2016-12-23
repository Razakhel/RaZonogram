
#include <vector>
#include <iostream>
#include "../include/Grid.hpp"

Grid::Grid(const unsigned int& height, const unsigned int& width) {
  colClues.resize(height);
  rowClues.resize(width);
  grid.resize(height);

  for (unsigned int i = 0; i < height; ++i) {
    grid[i].resize(width);
  }
}

Grid& Grid::solve() { return *this; }

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
  for (unsigned int i = 0; i < grid.getGrid().size(); ++i) { //TODO: make it clearer?
    os << "[ ";
    for (unsigned int j = 0; j < grid.getGrid()[i].size(); ++j) {
      char res = '-';
      switch (grid.getGrid()[i][j].getState()) {
        case FILLED:
          res = 'O';
          break;
        case DENIED:
          res = 'X';
          break;
        default:
          break;
      }
      os << res << ' ';
    }
    os << ']' << std::endl;
  }
  return os;
}
