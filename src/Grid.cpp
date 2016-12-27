
#include <vector>
#include <fstream>
#include <iostream>

#include "../include/Grid.hpp"
#include "../include/Utils.hpp"

Grid::Grid() {}

const bool Grid::loadFromFile(const std::string& fileName) {
  unsigned int height, width;

  if (std::ifstream fs{fileName}) {
    fs >> height >> width;
    colClues.resize(height);
    rowClues.resize(width);
    grid.resize(height);

    for (unsigned int i = 0; i < height; ++i)
      grid[i].resize(width);

    {
      int value, lineNumber = 1;
      std::string line;

      while (std::getline(fs, line)) {
        if (lineNumber > 1) { // If the line isn't the first one (which is <height width>)
          std::vector<std::string> vals;

          if (lineNumber == 2) { // Second line is column's
            /* Filling columns' clues */
            Utils::split(line, ';', vals);

            for (unsigned int i = 0; i < vals.size(); ++i) {
              std::stringstream ss{vals[i]};
              while (ss >> value)
                colClues[i].push_back(value);
            }
          } else if (lineNumber == 3) { // Third line is row's
            /* Filling rows' clues */
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
