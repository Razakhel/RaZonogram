
#include <vector>
#include <fstream>
#include <iostream>

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
    {
      int value, lineNumber = 1;
      std::string line;

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
      } // End of while (std::getline(fs, line)))
    }
  } else { // If the file couldn't have been opened
    return false;
  }
  return true;
}

Grid& Grid::solve() { return *this; } //TODO: implement solver

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
