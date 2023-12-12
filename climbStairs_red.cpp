// File Name: climbStairs_red.cpp
// Author: Dia Al rahman
// Email Address: diaalrahman312@gmail.com
// Description:
// Last Changed: 12-12-2023

#include <iostream>

int climbStairs(int n, int k, bool red[]) {
    int dp[n + 1] = {1};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
            {
                continue;
            }
            else if (!red[i])
            {
                dp[i] += dp[i - j];
            }
            else
            {
                dp[i] = 0;
            }
        }
    }
    return dp[n];
}

int main() {

    bool red[7] = {false, true, false, true, true, false, false};
    std::cout << climbStairs(7, 3, red) << std::endl;

    return 0;
}