// Brian Goldman
// A collection of other useful things in C++11
// Compiled using: g++ -std=c++11 other.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  // You no longer need the space between >> when using nested templates
  vector<vector<double> > with_space; // Old way
  vector<vector<double>> no_more_space; // New way

  // You can use the words "and" "or" "not" to replace "&&" "||" "!"
  bool to_be = true;
  int silly_level = 9001;
  if ((to_be or not to_be) and silly_level > 0) {
    cout << "Loop is true" << endl;
  }

  // You no longer need c_str() to open a file
  string some_file_name = "temp.txt";
  ifstream old_way(some_file_name.c_str());
  ifstream new_way(some_file_name);

  // "stol" = "string to long"
  cout << stol("19") + 1 << endl;

  // Unitialized pointers should be set to "nullptr" so you don't read bad data
  int * nowhere = nullptr;
  if (nowhere != nullptr) {
    cout << *nowhere << endl;
  }

  // New data structure similar to python "dict" which provides
  // a hashing O(1) lookup table from unique keys to values
  unordered_map<int, double> fraction_lookup;
  for (int i=1; i < 10; i++) {
    fraction_lookup[i] = 1 / static_cast<double>(i);
  }
  cout << "1/4 is " << fraction_lookup[4] << endl;
  return 0;
}
