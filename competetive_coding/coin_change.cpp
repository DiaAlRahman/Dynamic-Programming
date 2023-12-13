// File Name: coin_change.cpp
// Author: Dia Al rahman
// Email Address: diaalrahman312@gmail.com
// Description: Coin Change Problem - Chapter 6 Dynamic Programming - pg 65
// Last Changed: 13-12-2023

/*
Framework of DP:
    1. Define the objective function
        f(i) is the minimum number of coins whose values add up to the target
sum.
    2. Identify base cases
        f(i == 0) = 0, f(i < 0) = infinite
    3. Write down a recurrence relation for the optimized objective function.
        f(n) = min(f(n - c) + 1), n > 0 and c E {coins}
    4. What's the order of execution?
        bottom-up, could be top-down
    5. Where to look for the answer?
        f(n)
*/

#include <iostream>
#include <vector>

long INF = 1000000000000000;

int minCoins(int n, std::vector<int> coins) {
  long value[n + 1] = {0};
  for (int i = 1; i <= n; i++) {
    value[i] = INF;
    for (int c : coins) {
      if ((i - c >= 0) && (value[i - c] + 1 < value[i])) {
        value[i] = value[i - c] + 1;
      }
    }
  }

  return value[n];
}

int main() {
  int target_sum = 20;
  std::vector<int> coins = {1, 3, 4};

  std::cout << "The number of coins needed to add up to " << target_sum
            << " is " << minCoins(target_sum, coins) << std::endl;

  return 0;
}