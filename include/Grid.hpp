
#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <iostream>

#include "Tile.hpp"

class Grid {
public:
  Grid();

  std::vector<std::vector<Tile>> getGrid() const { return grid; }

  const bool loadFromFile(const std::string& fileName);
  Grid& solve();

private:
  std::vector<std::vector<int>> colClues;
  std::vector<std::vector<int>> rowClues;

  std::vector<std::vector<Tile>> grid;
};

std::ostream& operator<<(std::ostream& os, const Grid& grid);

#endif // GRID_HPP
