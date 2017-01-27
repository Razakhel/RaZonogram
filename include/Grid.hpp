
#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <iostream>

#include "Tile.hpp"

class Grid {
public:
  Grid();

  unsigned int getBoardHeight() const { return boardHeight; }
  unsigned int getBoardWidth() const { return boardWidth; }
  std::vector<std::vector<int>> getColClues() const { return colClues; }
  std::vector<std::vector<int>> getRowClues() const { return rowClues; }
  std::vector<std::vector<Tile>>& getBoard() { return board; }

  const bool loadFromFile(const std::string& fileName);
  Grid& solve();
  const bool isComplete();

private:
  unsigned int boardHeight, boardWidth;

  std::vector<std::vector<int>> colClues;
  std::vector<std::vector<int>> rowClues;

  std::vector<std::vector<Tile>> board;
};

std::ostream& operator<<(std::ostream& os, Grid& grid);

#endif // GRID_HPP
