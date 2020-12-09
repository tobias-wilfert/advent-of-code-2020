//============================================================================
// Name        : solutions.h
// Author      : Tobias Wilfert
//============================================================================

#ifndef ADVENT_OF_CODE_SRC_SOLUTIONS_H_
#define ADVENT_OF_CODE_SRC_SOLUTIONS_H_

#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <unordered_set>

// --------------------------------- DAY 1 ------------------------------------

/**
 * Reads the input for day one from the input file and
 * prints the solution for the first and second part.
 */
void solutionDayOne();

/**
 * Answer for https://adventofcode.com/2020/day/1
 * Analysis:
 * - Space Complexity: O(n)
 * - Time Complexity: O(n)
 * @note If no two entries satisfy the requirement the function returns -1
 * @param vec Expense report from the Elves in accounting
 * @return the product of the two entries in vec that sum up to 2020
 */
int solutionDayOnePartOne(const std::vector<int> &vec);

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
int solutionDayOnePartTwo(const std::vector<int> &vec);

// --------------------------------- DAY 2 ------------------------------------

/**
 * Reads the input for day two from the input file and
 * prints the solution for the first and second part.
 */
void solutionDayTwo();

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
                                                       std::string>> &input);

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
                                                       std::string>> &input);

// --------------------------------- DAY 3 ------------------------------------

/**
 * Reads the input for day three from the input file and
 * prints the solution for the first and second part.
 */
void solutionDayThree();

/**
 * Answer for https://adventofcode.com/2020/day/3#part1
 * Analysis:
 * - Space Complexity: O(1)
 * - Time Complexity: O(n)
 * @param input A vector of strings representing a map, with '#' representing a tree
 * @return The number of trees encountered following the slope 3 right, 1 down.
 * Starting in the top left corner
 */
int solutionDayThreePartOne(const std::vector<std::string> &input);

/**
 * Analysis:
 * - Space Complexity: O(1)
 * - Time Complexity: O(n)
 * @param delta_x The size of the step to the left on the map
 * @param delta_y The size of the step downwards on the map
 * @param input A vector of strings representing a map, with '#' representing a tree
 * @return The number of trees encountered following the slope delta_x right,
 * delta_y down.
 * Starting in the top left corner
 */
int helperSolutionDayThreePartTwo(int delta_x, int delta_y,
                                  const std::vector<std::string> &input);
/**
 * Answer for https://adventofcode.com/2020/day/3#part2
 * Analysis:
 * - Space Complexity: O(1)
 * - Time Complexity: O(n)
 * @param input A vector of strings representing a map, with '#' representing a tree
 * @return The product of the number of trees encountered following multiple slopes
 * Starting in the top left corner
 */
long solutionDayThreePartTwo(const std::vector<std::string> &input);

#endif //ADVENT_OF_CODE_SRC_SOLUTIONS_H_
