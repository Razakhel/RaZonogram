
#include <string>
#include <vector>
#include <sstream>

namespace Utils {

  static void split(const std::string& str, char delim, std::vector<std::string>& elems) {
    std::stringstream ss;
    ss.str(str);

    std::string item;
    while (std::getline(ss, item, delim)) {
      if (!item.empty()) elems.push_back(item);
    }
  }
  
}
