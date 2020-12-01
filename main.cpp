#include <iostream>
#include <iterator>
#include <fstream>

#include <vector>
#include <unordered_map>

/**
 * Answer for https://adventofcode.com/2020/day/1 part one
 * Methodology:
 *  Make a map that has as a key 2020-x and as a value the index of x.
 *  Then loop over the list and check if the map has a complement for the
 *  current value, if yes return the product of the two.
 * Analysis:
 * - Space Complexity: O(n)
 * - Time Complexity: O(n)
 * @note If no two entries satisfy the requirement the function returns -1
 * @param vec Expense report from the Elves in accounting
 * @return the product of the two entries in vec that sum up to 2020
 * @author: Tobias Wilfert
 */
int solutionDayOnePartOne(const std::vector<int> &vec) {
  std::unordered_map<int, int> complement_map;

  for (int i = 0; i < vec.size(); ++i) {
    complement_map[2020 - vec[i]] = i;
  }

  for (int i = 0; i < vec.size(); ++i) {
    if (complement_map.find(vec[i])!=complement_map.end()) {
      return vec[i]*vec[complement_map[vec[i]]];
    }
  }
  return -1;
}

/**
 * Answer for https://adventofcode.com/2020/day/1 part two
 * Analysis:
 * - Space Complexity: O(1)
 * - Time Complexity: O(n^3)
 * @note Can be further improvised in terms of Time Complexity.
 * @note If no three entries satisfy the requirement the function returns -1
 * @param vec Expense report from the Elves in accounting
 * @return the product of the three entries in vec that sum up to 2020
 * @author: Tobias Wilfert
 */
int solutionDayOnePartTwo(const std::vector<int> &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = i + 1; j < vec.size(); ++j) {
      for (int k = j + 1; k < vec.size(); ++k) {
        if (vec[i] + vec[j] + vec[k]==2020) {
          return vec[i]*vec[j]*vec[k];
        }
      }
    }
  }
  return -1;
}

int main() {
  // Read the input into a vector
  std::ifstream is("../inputs/dayOne.txt");
  std::istream_iterator<int> start(is), end;
  std::vector<int> input(start, end);

  // Day one
  std::cout << "Solution day one, part one: " << solutionDayOnePartOne(input)
            << std::endl;
  std::cout << "Solution day one, part two: " << solutionDayOnePartTwo(input)
            << std::endl;
}
