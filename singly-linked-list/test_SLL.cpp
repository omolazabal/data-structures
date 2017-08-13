
#include <iostream>
#include "singly_linked_list.h"

using namespace std;

int main() {
  SLinkedList<int> list;
  int input;
  int value;
  int value2;

  while (true) {
    cout << "\n\nSINGLY LINKED LIST\n";
    cout << "1. Insert front\n";
    cout << "2. Insert\n";
    cout << "3. Remove front\n";
    cout << "4. Remove\n";
    cout << "5. Get front\n";
    cout << "6. Retrieve\n";
    cout << "7. Print\n";
    cout << "8. Length\n";
    cout << "9. Reverse\n\n";

    cout << "Selection: ";
    cin >> input;
    cout << endl;

    switch(input) {
      case 1:
        cout << "Enter a value: ";
        cin >> value;
        try { list.insert_front(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 2:
        cout << "Enter a value: ";
        cin >> value;
        cout << "Enter index: ";
        cin >> value2;
        try { list.insert(value, value2); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 3:
        try { list.remove_front(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 4:
        cout << "Enter an index: ";
        cin >> value;
        try { list.remove(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 5:
        try { cout << list.get_front(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 6:
        cout << "Enter an index to retrieve at: ";
        cin >> value;
        try { cout << list[value]; }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 7:
        try { list.print(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 8:
        try { cout << list.length(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 9:
        try { list.reverse(); }
        catch (exception &e) { cerr << e.what(); }
        break;
    }
  }
  return EXIT_SUCCESS;
}
