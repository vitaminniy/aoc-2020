#include <iostream>
#include <sstream>
#include <string>

bool is_valid(const std::string &s);
bool new_policy(const std::string &s);

int main() {
  int nvalid = 0, new_valid = 0;
  for (std::string line; std::getline(std::cin, line);) {
    if (is_valid(line))
      nvalid++;

    if (new_policy(line))
      new_valid++;
  }

  std::cout << nvalid << " " << new_valid << std::endl;
  return 0;
}

// Checks that password succeeds policy.
// Ex.:
// 1-3 a: abcde - true
// 1-3 b: cdefg - false
// 2-9 c: ccccccc - true
bool is_valid(const std::string &s) {
  int min, max;
  char target;

  std::stringstream ss(s);
  ss >> min;
  ss.ignore(1);
  ss >> max;
  ss.ignore(1);
  ss >> target;
  ss.ignore(1);

  int n = 0;
  while (ss) {
    char c = ss.get();
    if (c == target)
      n++;
  }

  if (n >= min && n <= max) {
    return true;
  }

  return false;
}

bool new_policy(const std::string &s) {
  int i, j;
  char c;

  std::stringstream ss(s);
  ss >> i;
  ss.ignore(1);

  ss >> j;
  ss.ignore(1);

  ss >> c;
  ss.ignore(2);

  int n = 0;
  bool first = false, second = false;
  while (ss) {
    n++;
    auto cc = ss.get();
    if (cc == c) {
      if (n == i) {
        first = true;
      }
      if (n == j) {
        second = true;
      }
    }
  }

  if (first && second)
    return false;

  return first || second;
}
