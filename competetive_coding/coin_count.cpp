// File Name: coin_count.cpp
// Author: Dia Al rahman
// Email Address: diaalrahman312@gmail.com
// Description:
// Last Changed: 13-12-2023

/*
Framework of DP:
    1. Define the objective function
        f(i) is the total number of ways that a given set of coins can add up to
a target sum. sum.
    2. Identify base cases
        f(i == 0) = 1, f(i < 0) = 0
    3. Write down a recurrence relation for the optimized objective function.
        f(n) = sum of f(n - c), n - c >= 0 and c E {coins}
    4. What's the order of execution?
        bottom-up
    5. Where to look for the answer?
        f(n)
*/

#include <iostream>
#include <vector>

int coin_count(int n, std::vector<int> coins) {
  int count[n + 1] = {1};
  for (int i = 1; i <= n; i++) {
    for (auto c : coins) {
      if (i - c >= 0) {
        count[i] += count[i - c];
      }
    }
  }
  if (n > 0) {
    return count[n];
  } else {
    return 0;
  }
}

int main() {
  int n = 6;
  std::vector<int> coins = {1, 3, 4};

  std::cout << "There are " << coin_count(n, coins) << " to sum up to " << n
            << "." << std::endl;

  return 0;
}