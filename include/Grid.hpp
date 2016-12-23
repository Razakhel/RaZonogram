
#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <iostream>
#include "Tile.hpp"

class Grid {
public:
  Grid(const unsigned int& height, const unsigned int& width);

  std::vector<std::vector<Tile>> getGrid() const { return grid; }

  Grid& solve();

private:
  std::vector<std::vector<int>> colClues;
  std::vector<std::vector<int>> rowClues;

  std::vector<std::vector<Tile>> grid;
};

std::ostream& operator<<(std::ostream& os, const Grid& grid);

#endif // GRID_HPP
