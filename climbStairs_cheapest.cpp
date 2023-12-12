// File Name: climbStairs_cheapest.cpp
// Author: Dia Al rahman
// Email Address: diaalrahman312@gmail.com
// Description:
// Last Changed: 12-12-2023

/*
Problem:
    Paid Staircase

    You are given an integer array cost where cost[i] is the cost of ith step on
a staircase. Once you pay the cost, you can either climb one or two steps. You
can either start from the step with index 0, or the step with index 1. Return
the minimum cost to reach the top of the floor.

    Framework of DP:
    1. Define the objective function
        f(i) is the cost of climbing to the top of the staircase.
    2. Identify base cases
        f(n <= 1) = cost[i]
    3. Write down a recurrence relation for the optimized objective function.
        f(n) = min(f(n - 1), f(n - 2)) + cost[i]
    4. What's the order of execution?
        bottom-up, could be top-down
    5. Where to look for the answer?
        minimum point of f(n)
*/

#include <iostream>

int minCost(int n, int p[]) {
    int dp[2] = {0, p[0]};
    int buffer;

    for (int i = 2; i <= n; i++) {
    buffer = dp[1];
    dp[1] = std::min(dp[0], dp[1]) + p[i - 1];
    dp[0] = buffer;
    }

    if (n != 0)
        return dp[1];
    else
        return 0;
}

int main() {
    int cost[10] = {10, 15, 20, 25, 30, 40, 50, 60, 70, 80};
    int nSteps;

    std::cout << "Enter the number of steps: ";
    std::cin >> nSteps;
    std::cout << "The cheapest cost to travel to the top is: "
                << minCost(nSteps, cost) << std::endl;

    return 0;
}