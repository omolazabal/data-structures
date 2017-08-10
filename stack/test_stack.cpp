
#include <iostream>
#include "stack.h"

using namespace std;

void test_stack() {
  Stack<int> stack;
  cout << "Pushing 2 4 5...\n";
  stack.push(2);
  stack.push(4);
  stack.push(5);

  cout << "stack: ";
  stack.print();
  cout << endl;

  cout << "Length: " << stack.length() << endl << endl;

  cout << "Pushing 100 101 102...\n";
  stack.push(100);
  stack.push(101);
  stack.push(102);
  cout << "stack: ";
  stack.print();

  cout << endl;

  cout << "Length: " << stack.length();

  cout << endl << endl;

  cout << "Popping 2 elements...\n";
  stack.pop();
  stack.pop();

  cout << "stack: ";
  stack.print();

  cout << endl;

  cout << "Length: " << stack.length();

  cout << endl << endl;

  cout << "Top element: " << stack.top() << endl;

}

int main() {
  test_stack();
  return EXIT_SUCCESS;
}

