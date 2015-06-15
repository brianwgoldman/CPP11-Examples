// Brian Goldman
// Example of how "move" can make your code nicer
// Compiled using: g++ -std=c++11 auto.cpp
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using std::chrono::steady_clock;

// The old way of efficienty handling the return of a large data structure
// was to use "return by reference" so you don't have to copy everything.
void create_a_range(const int target_size, vector<int> & return_by_reference) {
  return_by_reference.resize(target_size);
  // note, you can convert this loop to:
  // iota(return_by_reference.begin(), return_by_reference.end(), 0);
  for (int i=0; i < target_size; i++) {
    return_by_reference[i] = i;
  }
}

// C++11 is smart enough to realize that "result" is created in
// this function and returned. Therefore it doens't need to
// make a copy when returning, it can just "move" the contents
// of the vector
vector<int> create_a_range(const int target_size) {
  vector<int> result(target_size);
  for (int i=0; i < target_size; i++) {
    result[i] = i;
  }
  return result;
}

int main() {
  // Variables to ensure enough elements are created and enough time is spent
  // to get timing results
  const int target_size = 100000;
  const int loops = 1000;
  // Simple checksum to ensure the compiler doesn't optimize away everything
  int reference_checksum = 0;
  int return_checksum = 0;

  // Time using return by reference
  steady_clock::time_point start_reference = steady_clock::now();
  for (int i=0; i < loops; i++) {
    vector<int> result;
    create_a_range(target_size, result);
    reference_checksum += result[target_size/2];
  }
  steady_clock::time_point stop_reference = steady_clock::now();
  auto reference_seconds = std::chrono::duration<double>(stop_reference - start_reference).count();

  // Time using return with "move"
  steady_clock::time_point start_return = steady_clock::now();
  for (int i=0; i < loops; i++) {
    vector<int> result = create_a_range(target_size);
    return_checksum += result[target_size/2];
  }
  steady_clock::time_point stop_return = steady_clock::now();
  auto return_seconds = std::chrono::duration<double>(stop_return - start_return).count();

  cout << "Return by reference took  : " << reference_seconds << endl;
  cout << "Return with move semantics: " << return_seconds << endl;
  cout << "Difference in checksum: " << reference_checksum - return_checksum << endl;
  return 0;
}
