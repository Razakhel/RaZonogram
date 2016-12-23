
#include <string>
#include <vector>
#include <fstream>
#include "include/Grid.hpp"
#include "include/Utils.hpp"

int main(int argc, char* argv[]) {
  unsigned int height, width;
  std::vector<std::vector<unsigned int>> colClues;
  std::vector<std::vector<unsigned int>> rowClues;

  if (argc == 2) { //TODO: externalize this
    if (std::ifstream fs{argv[1]}) {
      fs >> height >> width;
      colClues.resize(height);
      rowClues.resize(width);

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
                while (ss >> value) {
                  colClues[i].push_back(value);
                }
              }
            } else if (lineNumber == 3) { // Third line is row's
              /* Filling rows' clues */
              Utils::split(line, ';', vals);

              for (unsigned int i = 0; i < vals.size(); ++i) {
                std::stringstream ss{vals[i]};
                while (ss >> value) {
                  rowClues[i].push_back(value);
                }
              }
            }
          }
          lineNumber++;
        }
      }
    } else { // If the file couldn't have been opened
      std::cerr << "Error while opening the file." << std::endl;
    }
  }

  Grid grid{height, width};
  std::cout << "Original grid:" << std::endl;
  std::cout << grid << std::endl;

  Grid solvedGrid{grid.solve()};
  std::cout << "Solved grid:" << std::endl;
  std::cout << solvedGrid << std::endl;

  return 0;
}
