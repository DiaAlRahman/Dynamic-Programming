// File Name: lng_inc_subseq.cpp
// Author: Dia Al rahman
// Email Address: diaalrahman312@gmail.com
// Description:
// Last Changed: 14-12-2023

/*
Framework of DP:
    1. Define the objective function
        f(i) is the maximum length of subsequence at i.
    2. Identify base cases
        f(i == 0) = 1
    3. Write down a recurrence relation for the optimized objective function.
        f(n) =  max(f(n), f(i) + 1), where i -> n
    4. What's the order of execution?
        bottom-up
    5. Where to look for the answer?
        the maximum value of f(n)
*/

#include <iostream>
#include <vector>

int highest(int n, int arr[]) {
  int highest = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > highest) {
      highest = arr[i];
    }
  }
  return highest;
}

int longest(int n, std::vector<int> sequence) {
  int count[n + 1] = {1};
  for (int i = 1; i <= n; i++) {
    count[i] = 1;
    for (int j = 0; j < i; j++) {
      if (sequence[j] < sequence[i]) {
        count[i] = std::max(count[j] + 1, count[i]);
      }
    }
  }
  return highest(n + 1, count);
}

int main() {
  std::vector<int> sequence = {6, 9, 8, 2, 3, 5, 1, 4, 7};
  int n = 8;

  std::cout << longest(n, sequence) << std::endl;

  return 0;
}