
#include <iostream>
#include "extendable_vector.h"

using namespace std;

int main() {
  Vector<int> vect(4);
  int input;
  int value;
  int value2;

  while (true) {
    cout << "\n\nEXTENDABLE VECTOR\n";
    cout << "1. Insert\n";
    cout << "2. Remove\n";
    cout << "3. Retrieve\n";
    cout << "4. Print\n";
    cout << "5. Length\n";
    cout << "6. Size\n\n";

    cout << "Selection: ";
    cin >> input;
    cout << endl;

    switch(input) {
      case 1:
        cout << "Enter a value: ";
        cin >> value;
        cout << "Enter index (enter -1 if no index): ";
        cin >> value2;
        try {
          if (value2 == -1)
            vect.insert(value);
          else
            vect.insert(value, value2);
        }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 2:
        cout << "Enter an index: ";
        cin >> value;
        try { vect.remove(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 3:
        cout << "Enter an index to retrieve at: ";
        cin >> value;
        try { cout << vect[value]; }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 4:
        try { vect.print(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 5:
        try { cout << vect.length(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 6:
        try { cout << vect.size(); }
        catch (exception &e) { cerr << e.what(); }
        break;
    }
  }
  return EXIT_SUCCESS;
}
