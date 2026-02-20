/**
 * @file Utilities.h
 * @brief These are utility functions that in theory aren't unique to this
 * project.
 */

#pragma once

#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace Utilities {
/**
 * @param &str A string containing a single valid CSV record.
 * @return a vector of string values
 * @see https://www.ietf.org/rfc/rfc4180.txt
 */
std::vector<std::string> ParseCSV(const std::string &str);

/**
 * @param &vec A vector of string values.
 * @return a string containing a single valid CSV record
 * @see https://www.ietf.org/rfc/rfc4180.txt
 */
std::string MakeCSV(const std::vector<std::string> &vec);

/**
 * @param &str A string containing a single valid CSV record.
 * @return whether the record is empty (i.e., contains nothing except any
 * commas) */
bool EmptyCSV(const std::string &str);

/**
 * Reads data from a text file into a hashmap. The format of the file contents
 * is expected to be: \n Heading \\n \n Comma-separated list \\n \n (Empty line)
 * \\n \n The file isn't a valid CSV file, as the lines are expected to have
 * different numbers of elements. But each line is formatted as a valid CSV
 * record (i.e., comma-separated and using quotes for special characters, etc).
 *
 * @param &filename A string, the name of the text file
 * @return a hashmap {heading => data, ...}.
 * @throw std::runtime_error if filename can't be opened
 * @throw std::runtime_error if file contents aren't as expected
 */
std::unordered_map<std::string, std::vector<std::string>>
ReadLists(const std::string &filename);

/**
 * @brief Overload << for vectors using << operator for the elements,
 * separated by commas. Does nothing if vec is empty. */
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec);

/**
 * @brief Given an array and a condition, returns a vector of iterators,
 * pointing to the elements of the original array.
 */
template <typename T, size_t L>
std::vector<typename std::array<T, L>::iterator>
Select(std::array<T, L> &vec, const std::function<bool(const T &)> &condition);

/**
 * @brief Checks the size and data types of a list of data. The parameters
 * numerical_data and boolean_data are lists of indices. Throws an error if the
 * data is different from what it should be.
 */
template <size_t L1, size_t L2>
void ValidateList(const std::vector<std::string> &data, size_t data_size,
                  const std::array<size_t, L1> &numerical_data,
                  const std::array<size_t, L2> &boolean_data);

#include "Utilities.tpp"

} // namespace Utilities