// Brian Goldman
// Example of how to use range based for loops
// Compiled using: g++ -std=c++11 auto.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Create a vector of 10 elements
  vector<int> some_data(10, 0);

  cout << "Old style indexing" << endl;
  // Generally not great
  for (size_t i=0; i < some_data.size(); i++) {
    some_data[i] ++;
    cout << some_data[i] << ", ";
  }
  cout << endl;

  cout << "Using iterators" << endl;
  // Better as iterators work well with unordered data structures like "list" and "map"
  for (vector<int>::iterator it = some_data.begin(); it != some_data.end(); it++) {
    (*it) ++;
    cout << *it << ", ";
  }
  cout << endl;

  cout << "Iterators, but with auto" << endl;
  // A lot less verbose about what "it" is
  for (auto it = some_data.begin(); it != some_data.end(); it++) {
    (*it) ++;
    cout << *it << ", ";
  }
  cout << endl;

  cout << "Using range based for loops" << endl;
  // Obvious that you are working with each element and don't care about the index
  for (int & value : some_data) {
    value ++;
    cout << value << ", ";
  }
  cout << endl;

  cout << "Using range based for loops and auto" << endl;
  // Auto saves you the headache of accidental type mismatch. Don't forget the & though!
  for (auto & value : some_data) {
    value ++;
    cout << value << ", ";
  }
  cout << endl;
  return 0;
}
