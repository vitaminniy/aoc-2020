#include <algorithm>
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> doubles(const std::vector<int> &nums, int target);
std::vector<int> triples(const std::vector<int> &nums, int target);
void print(const std::vector<int> &nums);

int main() {
  std::vector<int> numbers;
  for (std::string s; std::getline(std::cin, s);) {
    try {
      numbers.push_back(std::stoi(s));
    } catch (std::exception &e) {
      std::cout << "could not parse number: " << e.what() << std::endl;
      return 1;
    }
  }

  std::sort(numbers.begin(), numbers.end());
  print(doubles(numbers, 2020));
  print(triples(numbers, 2020));

  return 0;
}

std::vector<int> doubles(const std::vector<int> &nums, int target) {
  if (nums.empty())
    return {};

  std::vector<int> result;
  result.reserve(2);

  int i = 0, k = nums.size() - 1;
  while (i != k) {
    if (nums[k] >= target) {
      k--;
      continue;
    }

    const auto diff = target - nums[k];
    if (diff > nums[i]) {
      i++;
    } else if (diff < nums[i]) {
      k--;
    } else {
      return {nums[i], nums[k]};
    }
  }

  return {};
}

std::vector<int> triples(const std::vector<int> &nums, int target) {
  if (nums.size() < 3)
    return {};

  for (size_t i = 0; i < nums.size(); i++) {
    auto diff = target - static_cast<int>(nums[i]);
    std::vector<int> d;
    d.reserve(nums.size() - 1);
    for (size_t j = 0; j < nums.size(); j++) {
      if (j == i)
        continue;
      d.push_back(nums[j]);
    }
    auto res = doubles(d, diff);
    if (!res.empty()) {
      return {nums[i], res[0], res[1]};
    }
  }

  return {};
}

void print(const std::vector<int> &nums) {
  int64_t sum = 0, mult = 1;
  for (size_t i = 0; i < nums.size(); i++) {
    sum += nums[i];
    mult *= nums[i];
    if (i > 0)
      std::cout << " ";
    std::cout << nums[i];
  }

  std::cout << "; sum: " << sum << "; mult: " << mult << std::endl;
}
