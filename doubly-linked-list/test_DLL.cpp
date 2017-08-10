
#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

void test_list() {
  DLinkedList<int> list;
  cout << "Inserting 2 4 5 into the front of list...\n";
  list.insert_front(2);
  list.insert_front(4);
  list.insert_front(5);

  cout << "list: ";
  for (int i = 0; i < list.length(); i++) {
    cout << list[i] << " ";
  }

  cout << endl;

  cout << "Length: " << list.length();

  cout << endl << endl;

  cout << "Inserting 1 at index 0...\n";
  list.insert(1, 0);
  cout << "list: ";
  list.print();

  cout << "\n\nInserting 3 at index 2...\n";
  list.insert(3, 2);
  cout << "list: ";
  list.print();

  cout << "\n\nInserting 6 at index 5...\n";
  list.insert(6, 5);
  cout << "list: ";
  list.print();

  cout <<  endl << endl;

  cout << "Inserting 9 8 7 into the back of list...\n";
  list.insert_back(9);
  list.insert_back(8);
  list.insert_back(7);
  list.print();

  cout <<  endl << endl;

  cout << "Reversing the list...\n";
  list.reverse();

  cout << "list: ";
  list.print();

  cout << endl;

  cout << "Length: " << list.length();

  cout << endl << endl;

  cout << "Removing element at index 0...\n";
  list.remove(0);
  cout << "list: ";
  list.print();

  cout << "\n\nRemoving element at index 4...\n";
  list.remove(4);
  cout << "list: ";
  list.print();

  cout << "\n\nRemoving element at index 2...\n";
  list.remove(2);
  cout << "list: ";
  list.print();

  cout << endl;

  cout << "Length: " << list.length();

  cout << endl << endl;

  cout << "Inserting 100 101 102 to the front of the list...\n";
  list.insert_front(100);
  list.insert_front(101);
  list.insert_front(102);
  cout << "list: ";
  list.print();

  cout << endl;

  cout << "Length: " << list.length();

  cout << endl << endl;

  cout << "Removing 2 elements from the front of the list...\n";
  list.remove_front();
  list.remove_front();

  cout << "list: ";
  list.print();

  cout << endl;

  cout << "Length: " << list.length();

  cout << endl << endl;

  cout << "Removing 2 elements from the back of the list...\n";
  list.remove_back();
  list.remove_back();

  cout << "list: ";
  list.print();

  cout << endl;

  cout << "Length: " << list.length();

  cout << endl << endl;

  cout << "Front element: " << list.get_front() << endl;

  cout << "Second element: " << list.retrieve(1) << endl;

  cout << endl;
}

int main() {
  test_list();
  return EXIT_SUCCESS;
}
