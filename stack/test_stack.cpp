
#include <iostream>
#include "stack.h"

using namespace std;


int main() {
  Stack<int> stack;
  int input;
  int value;

  while (true) {
    cout << "\n\nSTACK\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Print\n";
    cout << "5. Length\n\n";

    cout << "Selection: ";
    cin >> input;
    cout << endl;

    switch(input) {
      case 1:
        cout << "Enter a value: ";
        cin >> value;
        try { stack.push(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 2:
        try { stack.pop(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 3:
        try { cout << stack.top(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 4:
        try { stack.print(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 5:
        try { cout << stack.length(); }
        catch (exception &e) { cerr << e.what(); }
        break;
    }
  }
  return EXIT_SUCCESS;
}

