
#include <array>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "../include/Grid.hpp"
#include "../include/Utils.hpp"

Grid::Grid() {}


const bool Grid::loadFromFile(const std::string& fileName) {
  if (std::ifstream fs{fileName}) { // If the file could have been opened
    unsigned int height, width;

    // Fetching height & width of the grid from the first 2 characters
    fs >> height >> width;
    colClues.resize(height);
    rowClues.resize(width);

    // Resizing the grid accordingly
    grid.resize(height);
    for (unsigned int i = 0; i < height; ++i)
      grid[i].resize(width);

    // Fetching grid's clues
    int value, lineNumber = 1;
    std::string line;

    // Reads every clues for each row & column from the file
    // Clues are written as following:
    //
    // a;b;c d;e f;g    <- Columns' clues
    // h i;j;k;l;m n    <- Rows' clues
    //
    // When finding an ';' char, the algorithm moves to the next line
    // Within the same line, each clue is separated by a space
    while (std::getline(fs, line)) {
      if (lineNumber > 1) { // If the line isn't the first one (which is <height width>)
        std::vector<std::string> vals;

        if (lineNumber == 2) { // Second line is column's
          // Filling columns' clues
          Utils::split(line, ';', vals);

          for (unsigned int i = 0; i < vals.size(); ++i) {
            std::stringstream ss{vals[i]};
            while (ss >> value)
              colClues[i].push_back(value);
          }
        } else if (lineNumber == 3) { // Third line is row's
          // Filling rows' clues
          Utils::split(line, ';', vals);

          for (unsigned int i = 0; i < vals.size(); ++i) {
            std::stringstream ss{vals[i]};
            while (ss >> value)
              rowClues[i].push_back(value);
          }
        } // End of if (lineNumber == 3)
      } // End of if (lineNumber > 1)
      lineNumber++;
    } // End of while (std::getline(fs, line))
  } else { // If the file couldn't have been opened
    return false;
  }
  return true;
}

// Naive resolution algorithm
//   Heuristic: try to solve first the line with the higher amount of cumulated clues
//   Then fill the line with as many solutions the algorithm can deduce as possible
//   When the line's been processed, substract the number of tiles filled or denied to the line's total amount available
//   From there go to the next biggest line
//   Repeat until the grid is solved
const Grid Grid::solve() { //TODO: implement solver
  Grid solvedGrid = *this;
  std::vector<int> rowCluesTotal(rowClues.size());
  std::vector<int> colCluesTotal(colClues.size());
  std::vector<int>::iterator rowMax, colMax;

  // Calculates the cumulated amount of clues for each row
  for (unsigned int i = 0; i < rowClues.size(); ++i)
    for (unsigned int j = 0; j < rowClues[i].size(); ++j)
      rowCluesTotal[i] += rowClues[i][j];

  // Calculates the cumulated amount of clues for each column
  for (unsigned int i = 0; i < colClues.size(); ++i)
    for (unsigned int j = 0; j < colClues[i].size(); ++j)
      colCluesTotal[i] += colClues[i][j];

  rowMax = std::max_element(rowCluesTotal.begin(), rowCluesTotal.end());
  colMax = std::max_element(colCluesTotal.begin(), colCluesTotal.end());
  std::cout << std::distance(rowCluesTotal.begin(), rowMax) << std::endl;
  std::cout << std::distance(colCluesTotal.begin(), colMax) << std::endl;

  return solvedGrid;
}

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
  // For each entry in rows' clues, prints two spaces to make a margin (plus two for the starting '[ ')
  // Ideally, should get the entry with maximum number of clues and remove the last space
  // TODO: should also handle numbers, not only digits
  for (unsigned int i = 0; i <= grid.getRowClues()[0].size(); ++i)
    os << "  ";

  for (unsigned int colIndex = 0; colIndex < grid.getColClues().size(); ++colIndex) // Prints columns' clues
    os << grid.getColClues()[colIndex][0] << ' ';
  os << std::endl;

  for (unsigned int height = 0; height < grid.getGrid().size(); ++height) { // For each row
    for (unsigned int rowIndex = 0; rowIndex < grid.getRowClues()[height].size(); ++rowIndex) // Prints rows' clues
      os << grid.getRowClues()[height][rowIndex] << ' ';

    // Prints the whole grid in the form:
    // [ X O X ]
    // [ - O X ]
    // [ - O - ]
    // Where the tiles marked as 'O' are filled, those with an 'X' are denied, and '-' means it's empty
    os << "[ ";
    for (unsigned int width = 0; width < grid.getGrid()[height].size(); ++width) { // For each tile
      char res = '-';
      switch (grid.getGrid()[height][width].getState()) { // Prints ouput depending of the tile's state
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
    os << "] ";

    for (unsigned int rowIndex = 0; rowIndex < grid.getRowClues()[height].size(); ++rowIndex) // Prints rows' clues
      os << grid.getRowClues()[height][rowIndex] << ' ';
    os << std::endl;
  }

  // Prints margin again at the bottom of the grid
  for (unsigned int i = 0; i <= grid.getRowClues()[0].size(); ++i)
    os << "  ";
  for (unsigned int colIndex = 0; colIndex < grid.getColClues().size(); ++colIndex) // Prints columns' clues
    os << grid.getColClues()[colIndex][0] << ' ';

  return os << std::endl;
}
