
#include <iostream>
#include "binary_search_tree.h"
#include <string>

using namespace std;

int main() {
  BinarySearchTree<int> tree;
  string order;
  int input;
  int value;

  while (true) {
    cout << "\n\nBINARY SEARCH TREE\n";
    cout << "1. Insert\n";
    cout << "2. Remove\n";
    cout << "3. Retrieve\n";
    cout << "4. Print\n";
    cout << "5. Height\n";
    cout << "6. Size\n";
    cout << "7. Remove all\n\n";

    cout << "Selection: ";
    cin >> input;
    cout << endl;

    switch(input) {
      case 1:
        cout << "Enter a value: ";
        cin >> value;
        try { tree.insert(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 2:
        cout << "Enter a value: ";
        cin >> value;
        try { tree.remove(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 3:
        cout << "Enter a value to retrieve: ";
        cin >> value;
        try { cout << tree.retrieve(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 4:
        cout << "Enter an order (preorder, inorder, postorder): ";
        cin >> order;
        try {
          cout << endl;
          tree.print(order);
        }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 5:
        try { cout << tree.height(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 6:
        try { cout << tree.size(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 7:
        try { tree.remove_all(); }
        catch (exception &e) { cerr << e.what(); }
        break;
    }
  }
  return EXIT_SUCCESS;
}
