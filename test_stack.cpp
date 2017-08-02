
#include <iostream>
#include "stack.h"

using namespace std;

void test_stack() {
  Stack<int> stack;
  cout << "Pushing 2 4 5 into stack...\n";
  stack.push(2);
  stack.push(4);
  stack.push(5);

  cout << "stack: ";
  for (int i = 0; i < stack.length(); i++) {
    cout << stack[i] << " ";
  }

  cout << endl;

  cout << "Length: " << stack.length();

  cout << endl << endl;

  cout << "Inserting 1 at index 0...\n";
  stack.insert(1, 0);
  cout << "stack: ";
  stack.print();

  cout << "\n\nInserting 3 at index 2...\n";
  stack.insert(3, 2);
  cout << "stack: ";
  stack.print();

  cout << "\n\nInserting 6 at index 5...\n";
  stack.insert(6, 5);
  cout << "stack: ";
  stack.print();

  cout <<  endl << endl;

  cout << "Reversing the stack...\n";
  stack.reverse();

  cout << "stack: ";
  stack.print();

  cout << endl;

  cout << "Length: " << stack.length();

  cout << endl << endl;

  cout << "Removing element at index 0...\n";
  stack.remove(0);
  cout << "stack: ";
  stack.print();

  cout << "\n\nRemoving element at index 4...\n";
  stack.remove(4);
  cout << "stack: ";
  stack.print();

  cout << "\n\nRemoving element at index 2...\n";
  stack.remove(2);
  cout << "stack: ";
  stack.print();

  cout << endl;

  cout << "Length: " << stack.length();

  cout << endl << endl;

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

  cout << "Second element: " << stack.retrieve(1) << endl;

  cout << endl;
}

int main() {
  test_stack();
  return EXIT_SUCCESS;
}
