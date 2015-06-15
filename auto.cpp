// Brian Goldman
// Example of how to use the "auto" keyword
// Compiled using: g++ -std=c++11 auto.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // Compiler figures out another_x is an "int"
  int x;
  auto another_x = x;
  
  // Compiler figures out the result of adding two strings
  string words = "These are words";
  auto more_word = words + " and some more";
  
  // The type of "result" matches the return time of "sqrt"
  auto result = sqrt(17);
  
  // Auto doesn't keep type modifiers like "const" and "reference"
  const double PI = 3.1415;
  auto my_PI = PI;
  // no compiler error since it isn't a const.
  my_PI = 3;

  return 0;
}