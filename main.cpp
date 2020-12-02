#include <iostream>
#include <iterator>
#include <fstream>

#include <vector>
#include <unordered_set>

/**
 * Answer for https://adventofcode.com/2020/day/1
 * Analysis:
 * - Space Complexity: O(n)
 * - Time Complexity: O(n)
 * @note If no two entries satisfy the requirement the function returns -1
 * @param vec Expense report from the Elves in accounting
 * @return the product of the two entries in vec that sum up to 2020
 */
int solutionDayOnePartOne(const std::vector<int> &vec) {
  std::unordered_set<int> complement_set;

  for (int num : vec) {
    complement_set.insert(2020 - num);
  }

  for (int num : vec) {
    if (complement_set.find(num)!=complement_set.end()) {
      return num*(2020 - num);
    }
  }
  return -1;
}

/**
 * Answer for https://adventofcode.com/2020/day/1#part2
 * Analysis:
 * - Space Complexity: O(1)
 * - Time Complexity: O(n^3)
 * @note Can be further improvised in terms of Time Complexity.
 * @note If no three entries satisfy the requirement the function returns -1
 * @param vec Expense report from the Elves in accounting
 * @return the product of the three entries in vec that sum up to 2020
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

/**
 * Answer for https://adventofcode.com/2020/day/2
 * Analysis:
 * - Space Complexity: O(1)
 * - Time Complexity: O(n)
 * @param input Vector of tuples, where each tuple is of the form:
 * <lower_bound, upperbound, character, password>
 * @return The number of passwords that are valid
 */
int solutionDayTwoPartOne(const std::vector<std::tuple<int,
                                                       int,
                                                       char,
                                                       std::string>> &input) {
  int count = 0;

  for (const auto &t: input) {
    int char_count = 0;
    for (const char &c: std::get<3>(t)) {
      if (c==std::get<2>(t)) {
        ++char_count;
      }
    }
    if (std::get<0>(t) <= char_count && char_count <= std::get<1>(t)) {
      ++count;
    }
  }

  return count;
}

/**
 * Answer for https://adventofcode.com/2020/day/2#part2
 * Analysis:
 * - Space Complexity: O(1)
 * - Time Complexity: O(n)
 * @param input Vector of tuples, where each tuple is of the form:
 * <lower_bound, upperbound, character, password>
 * @return The number of passwords that are valid
 */
int solutionDayTwoPartTwo(const std::vector<std::tuple<int,
                                                       int,
                                                       char,
                                                       std::string>> &input) {
  int count = 0;

  for (const auto &t: input) {
    char first_position = std::get<3>(t).at(std::get<0>(t) - 1);
    char second_position = std::get<3>(t).at(std::get<1>(t) - 1);
    char correct = std::get<2>(t);
    if (first_position!=second_position
        && (first_position==correct || second_position==correct)) {
      ++count;
    }
  }

  return count;
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


  // Read the input for day two
  std::ifstream infile("../inputs/dayTwo.txt");
  std::string count, character, password;
  std::vector<std::tuple<int, int, char, std::string>> inputDayTwo;

  while (infile >> count >> character >> password) {
    int lowerBound = std::stoi(count.substr(0, count.find_first_of('-')));
    int upperBound = std::stoi(count.substr(count.find_first_of('-') + 1));
    inputDayTwo.emplace_back(lowerBound, upperBound, character[0], password);
  }

  // Day two
  std::cout << "Solution day two, part one: "
            << solutionDayTwoPartOne(inputDayTwo)
            << std::endl;
  std::cout << "Solution day two, part two: "
            << solutionDayTwoPartTwo(inputDayTwo)
            << std::endl;
}
