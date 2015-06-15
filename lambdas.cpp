// Brian Goldman
// Example of how to use Lambda functions
// Compiled using: g++ -std=c++11 lambdas.cpp
#include <iostream>
#include <algorithm>
using namespace std;

// Example of the old way to get reverse sorting
bool reverse_order(const int& first, const int& second) {
  return first > second;
}

// Utility to print out the vectors
void print(const vector<int> & numbers) {
  for (const auto & number : numbers) {
    cout << number << ", ";
  }
  cout << endl;
}

int main() {
  // creates a vector of numbers using C++11's initializer lists
  vector<int> numbers = {8, 6, 7, 5, 3, 0, 9};

  // does an implace sort
  sort(numbers.begin(), numbers.end());
  cout << "Smallest to largest" << endl;
  print(numbers);

  // Uses a regular function to sort in reverse order
  sort(numbers.begin(), numbers.end(), reverse_order);

  // Uses a Lambda function to sort in reverse order
  sort(numbers.begin(), numbers.end(),
       // This is a lambda being passed as the third argument of sort
       // Lambda's have 3 parts
       // * The [] is the "capture" which holds on to extra variables
       // * The () is the argument list, like any other function
       // * The {} is the function body, like any other function
       [](const int& first, const int& second) { return first > second; }
  );
  cout << "Largest to smallest" << endl;
  print(numbers);

  int target = 7;
  // Create a lambda named "from_target" which captures a reference to "target"
  auto from_target = [&target](const int& first, const int& second) { return abs(target-first) < abs(target-second); };
  target = 3;
  sort(numbers.begin(), numbers.end(), from_target);

  cout << "Ordered by absolute distance from " << target << endl;
  print(numbers);
  return 0;
}
