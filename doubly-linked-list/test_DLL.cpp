
#include <iostream>
#include "doubly_linked_list.h"

using namespace std;


int main() {
  DLinkedList<int> list;
  int input;
  int value;
  int value2;

  while (true) {
    cout << "\n\nDOUBLY LINKED LIST\n";
    cout << "1. Insert front\n";
    cout << "2. Insert back\n";
    cout << "3. Insert\n";
    cout << "4. Remove front\n";
    cout << "5. Remove back\n";
    cout << "6. Remove\n";
    cout << "7. Get front\n";
    cout << "8. Get back\n";
    cout << "9. Retrieve\n";
    cout << "10. Print\n";
    cout << "11. Length\n";
    cout << "12. Reverse\n\n";

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
        try { list.insert_back(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 3:
        cout << "Enter a value: ";
        cin >> value;
        cout << "Enter index: ";
        cin >> value2;
        try { list.insert(value, value2); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 4:
        try { list.remove_front(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 5:
        try { list.remove_back(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 6:
        cout << "Enter an index: ";
        cin >> value;
        try { list.remove(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 7:
        try { cout << list.get_front(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 8:
        try { cout << list.get_back(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 9:
        cout << "Enter an index to retrieve at: ";
        cin >> value;
        try { cout << list[value]; }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 10:
        try { list.print(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 11:
        try { cout << list.length(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 12:
        try { list.reverse(); }
        catch (exception &e) { cerr << e.what(); }
        break;
    }
  }
  return EXIT_SUCCESS;
}
