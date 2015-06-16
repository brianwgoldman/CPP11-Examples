// Brian Goldman
// Example of how to use random number generation
// Compiled using: g++ -std=c++11 random_number_generator.cpp
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// Creates an alias for the Mersenne Twister named "Random"
// because I don't think mt19937 is very descriptive
using Random=std::mt19937;

int main() {
  // Create some storage for random numbers
  vector<int> int_values;
  vector<double> double_values;
  const int number_to_generate = 10;

  // Create a new source of random numbers
  Random engine;

  // Create a distrubtion which makes random numbers from 5 to 25, inclusive
  uniform_int_distribution<int> distribution(5, 25);
  for (int i=0; i < number_to_generate; i++) {
    // Use the "distribution" to convert randomness from the "engine"
    // into your desired type of number
    int number = distribution(engine);
    int_values.push_back(number);
  }

  // Create a set of normally distributed numbers with mean of 0 and std of 1
  normal_distribution<> normal_numbers(0, 1);
  for (int i=0; i < number_to_generate; i++) {
    // Use the "normal_numbers" distribution to covert randomness from "engine"
    // into normally distributed numbers
    double number = normal_numbers(engine);
    double_values.push_back(number);
  }

  for (int i=0; i < number_to_generate; i++) {
    cout << int_values[i] + double_values[i] << ", ";
  }
  cout << endl;

  // Shuffle a data structure
  shuffle(int_values.begin(), int_values.end(), engine);
  return 0;
}
