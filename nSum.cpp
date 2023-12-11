/*
    Problem Statement:
        Find the sum of the first 'n' numbers.

    Objective Function:
        f(i) is the sum of the first i elements.

    Recurrence relation:
        f(n) = f(n - 1) + n
*/

#include <iostream>

int nSum(int n) {
  int sums[n + 1] = {0};

  for (int i = 1; i <= n; i++) {
    sums[i] = sums[i - 1] + i;
  }

  return sums[n];
}

int naive_nSum(int n) {
  int total = 0;

  for (int i = 0; i <= n; i++) {
    total += i;
  }

  return total;
}

int main() {
  int number;
  while (1) {
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "The sum of the first " << number << " numbers is "
              << nSum(number) << std::endl;
    // std::cout << "The sum of the first " << number << " numbers is "
    //           << naive_nSum(number) << std::endl;
  }
}