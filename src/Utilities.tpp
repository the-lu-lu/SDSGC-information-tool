template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  if (vec.empty()) {
    return os;
  }

  for (size_t i{0}; i < vec.size() - 1; i++) {
    os << vec[i] << ", ";
  }
  os << vec[vec.size() - 1];
  return os;
}

template <typename T, size_t L>
std::vector<typename std::array<T, L>::iterator>
Select(std::array<T, L> &vec, const std::function<bool(const T &)> &condition) {
  std::vector<typename std::array<T, L>::iterator> out{};
  for (auto it{vec.begin()}; it != vec.end(); it++) {
    if (condition(*it)) {
      out.push_back(it);
    }
  }
  return out;
}

template <size_t L1, size_t L2>
void ValidateList(const std::vector<std::string> &data, size_t data_size,
                  const std::array<size_t, L1> &numerical_data,
                  const std::array<size_t, L2> &boolean_data) {
  const std::string &hero = data[0];
  if (data.size() != data_size) {
    std::string error_message = "Invalid format in data file. Hero " + hero +
                                " has " + std::to_string(data.size()) +
                                " items instead of " +
                                std::to_string(data_size) + ".";
    throw std::runtime_error(error_message);
  }

  for (size_t i = 0; i < data_size; i++) {
    // check if it's a number
    try {
      std::stoi(data[i]); // is a number
      if (std::find(numerical_data.begin(), numerical_data.end(), i) ==
          numerical_data.end()) { // not numerical data
        std::string error_message = "Invalid data in data/owned.csv. Item \"" +
                                    data[i] + "\" of hero " + hero +
                                    " should not be a number.";
        throw std::runtime_error(error_message);
      } else {
        // fine
      }
    } catch (const std::invalid_argument &) { // not a number
      if (std::find(numerical_data.begin(), numerical_data.end(), i) !=
          numerical_data.end()) { // is numerical data
        std::string error_message = "Invalid data in data/owned.csv. Item \"" +
                                    data[i] + "\" of hero " + hero +
                                    " should be a number.";
        throw std::runtime_error(error_message);
      } else {
        // fine
      }
    }
    // check if it's a boolean
    if (data[i] == "true" || data[i] == "false") { // is a boolean
      if (std::find(boolean_data.begin(), boolean_data.end(), i) ==
          boolean_data.end()) { // not boolean data
        std::string error_message = "Invalid data in data/owned.csv. Item \"" +
                                    data[i] + "\" of hero " + hero +
                                    " should not be a boolean.";
        throw std::runtime_error(error_message);
      } else {
        // fine
      }
    } else { // not a boolean
      if (std::find(boolean_data.begin(), boolean_data.end(), i) !=
          boolean_data.end()) { // is boolean data
        std::string error_message = "Invalid data in data/owned.csv. Item \"" +
                                    data[i] + "\" of hero " + hero +
                                    " should be a boolean.";
        throw std::runtime_error(error_message);
      } else {
        // fine
      }
    }
  }
}