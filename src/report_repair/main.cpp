#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<int> numbers;
  for (std::string s; std::getline(std::cin, s);) {
    try {
      const auto n = std::stoi(s);
      if (n >= 2020)
        continue;

      numbers.push_back(n);
    } catch (std::exception &e) {
      std::cout << "could not parse number: " << e.what() << std::endl;
      return 1;
    }
  }

  std::sort(numbers.begin(), numbers.end());
  int i = 0, k = numbers.size() - 1;

  while (i != k) {
    auto diff = 2020 - numbers[k];
    if (diff > numbers[i]) {
      i++;
    } else if (diff < numbers[i]) {
      k--;
    } else {
      break;
    }
  }

  std::cout << numbers[i] << " + " << numbers[k] << " = "
            << numbers[i] + numbers[k] << std::endl;
  std::cout << numbers[i] << " * " << numbers[k] << " = "
            << numbers[i] * numbers[k] << std::endl;

  return 0;
}
