// Brian Goldman
// Example of how to use shared_ptr
// Compiled using: g++ -std=c++11 shared_pointer.cpp
#include <iostream>
#include <memory>
using namespace std;

class SomeCommonThing {
  // New C++11 initialization method. I don't know if I like it.
  int count=0;
 public:
  string message;
  void does_some_thing() {
    count ++;
    cout << message << " stated " << count << " times" << endl;
  }
};

// Often you want a function that returns dynamically allocated memory,
// but you also want to make certain it gets cleaned up. shared_ptr does that.
shared_ptr<SomeCommonThing> makes_thing() {
  // Wrap the call to "new" in a shared pointer
  shared_ptr<SomeCommonThing> thing(new SomeCommonThing());
  // Use it just like a regular pointer
  thing->message = "The message";
  return thing;
}

void process_using_thing(shared_ptr<SomeCommonThing> thing) {
  thing->does_some_thing();
}

int main() {
  auto the_thing = makes_thing();
  // Sends the shared thing to may other functions
  for (int i=0; i < 17; i++) {
    process_using_thing(the_thing);
  }
  cout << "Done" << endl;
  // Shared pointers clean themselves up when they go out of scope
  // for the last time, so you don't have to worry about memory leaks
  return 0;
}
