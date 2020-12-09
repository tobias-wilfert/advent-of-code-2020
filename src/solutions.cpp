//============================================================================
// Name        : solutions.cpp
// Author      : Tobias Wilfert
//============================================================================

#include "solutions.h"

// --------------------------------- DAY 1 ------------------------------------

void solutionDayOne() {
  // Read the input into a vector
  std::ifstream is("../inputs/dayOne.txt");
  std::istream_iterator<int> start(is), end;
  std::vector<int> input(start, end);

  std::cout << "Solution day one, part one: " << solutionDayOnePartOne(input)
            << std::endl;
  std::cout << "Solution day one, part two: " << solutionDayOnePartTwo(input)
            << std::endl;
}

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

// --------------------------------- DAY 2 ------------------------------------

void solutionDayTwo() {
  // Read the input for day two
  std::ifstream infile("../inputs/dayTwo.txt");
  std::string count, character, password;
  std::vector<std::tuple<int, int, char, std::string>> inputDayTwo;

  while (infile >> count >> character >> password) {
    int lowerBound = std::stoi(count.substr(0, count.find_first_of('-')));
    int upperBound = std::stoi(count.substr(count.find_first_of('-') + 1));
    inputDayTwo.emplace_back(lowerBound, upperBound, character[0], password);
  }

  std::cout << "Solution day two, part one: "
            << solutionDayTwoPartOne(inputDayTwo)
            << std::endl;
  std::cout << "Solution day two, part two: "
            << solutionDayTwoPartTwo(inputDayTwo)
            << std::endl;
}

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

// --------------------------------- DAY 3 ------------------------------------

void solutionDayThree() {
  // Read the input for day three
  std::ifstream infile("../inputs/dayThree.txt");
  std::vector<std::string> input;
  std::string row;
  while (getline(infile, row)) {
    input.push_back(row);
  }

  std::cout << "Solution day three, part one: "
            << solutionDayThreePartOne(input)
            << std::endl;
  std::cout << "Solution day three, part two: "
            << solutionDayThreePartTwo(input)
            << std::endl;
}

int solutionDayThreePartOne(const std::vector<std::string> &input) {
  int x = 0;
  int tree_count = 0;

  for (int y = 0; y < input.size(); ++y) {
    if (input[y][x]=='#') {
      ++tree_count;
    }
    x += 3;
    x %= input[0].size();
  }

  return tree_count;
}

int helperSolutionDayThreePartTwo(int delta_x, int delta_y,
                                  const std::vector<std::string> &input) {
  int x = 0;
  int tree_count = 0;

  for (int y = 0; y < input.size(); y += delta_y) {
    if (input[y][x]=='#') {
      ++tree_count;
    }
    x += delta_x;
    x %= input[0].size();
  }

  return tree_count;
}

long solutionDayThreePartTwo(const std::vector<std::string> &input) {
  std::vector<std::pair<int, int>> slopes{
      {1, 1},
      {3, 1},
      {5, 1},
      {7, 1},
      {1, 2}
  };
  long solution = 1;
  for (const std::pair<int, int> &p: slopes) {
    solution *= helperSolutionDayThreePartTwo(p.first, p.second, input);
  }
  return solution;
}
