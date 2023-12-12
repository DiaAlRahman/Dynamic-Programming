// File Name: climbingStairs_2.cpp
// Author: Dia Al rahman
// Email Address: diaalrahman312@gmail.com
// Description:
// Last Changed: 12-12-2023

/*
Problem:
    Climbing Stairs

    In how many distinct ways can you climb to the top of the stairs given that
    there are n steps and you can either climb 1, 2 or k steps, at a time.

Framework of DP:
    1. Define the objective function
        f(i) is the number of distinct ways to reach the i-th stair.
    2. Identify base cases
        f(n <= 2) = 2
    3. Write down a recurrence relation for the optimized objective function.
        f(n) = f(n - 1) + f(n - 2) + ... + f(n - k)
    4. What's the order of execution?
        bottom-up, could be top-down
    5. Where to look for the answer?
        f(n)
*/

// Use the mod operator to rewrite memory by cycling through the array - learn more

#include <iostream>

long climbStairs(int n, int k) {
  if (n <= 1) {
    return n;
  }

  long dp[n + 1] = {1, 1};

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
      }
    }
  }
  return dp[n];
}

int main() {
  int nSteps, kSteps;
  while (1) {
    std::cout << "Enter the number of steps, n: ";
    std::cin >> nSteps;
    std::cout << "Enter the number of steps you can climb at a time, k: ";
    std::cin >> kSteps;
    std::cout << "There are " << climbStairs(nSteps, kSteps)
              << " distinct way(s) of reaching the top." << std::endl;
  }

  return 0;
}