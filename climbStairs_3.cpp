// File Name: climbingStairs_2.cpp
// Author: Dia Al rahman
// Email Address: diaalrahman312@gmail.com
// Description:
// Last Changed: 12-12-2023

/*
Problem:
    Climbing Stairs

    In how many distinct ways can you climb to the top of the stairs given that
    there are n steps and you can either climb 1, 2 or 3 steps, at a time.

Framework of DP:
    1. Define the objective function
        f(i) is the number of distinct ways to reach the i-th stair.
    2. Identify base cases
        f(n <= 2) = 2
    3. Write down a recurrence relation for the optimized objective function.
        f(n) = f(n - 1) + f(n - 2) + f(n - 3)
    4. What's the order of execution?
        bottom-up, could be top-down
    5. Where to look for the answer?
        f(n)
*/

#include <iostream>

long climbStairs(int n) {
  if (n <= 2) {
    return n;
  }

  long dp[3] = {1, 2, 4};

  for (int i = 3; i < n; i++) {
    long buffer[2] = {dp[1], dp[2]};
    dp[2] = dp[2] + dp[1] + dp[0];
    dp[0] = buffer[0];
    dp[1] = buffer[1];
  }

  return dp[2];
}

int main() {
  int nSteps;
  while (1) {
    std::cout << "Enter the number of steps, n: ";
    std::cin >> nSteps;
    std::cout << "There are " << climbStairs(nSteps)
              << " distinct way(s) of reaching the top." << std::endl;
  }

  return 0;
}