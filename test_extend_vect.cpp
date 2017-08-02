
#include <iostream>
#include "extendable_vector.h"

using namespace std;

void test_vect() {
  Vector<int> vect(4);
  cout << "Inserting 2 4 5 into vector...\n";
  vect.insert(2);
  vect.insert(4);
  vect.insert(5);

  cout << "Vect: ";
  for (int i = 0; i < vect.length(); i++) {
    cout << vect[i] << " ";
  }

  cout << endl;

  cout << "Length: " << vect.length() << endl;
  cout << "Size: " << vect.size();

  cout << endl << endl;

  cout << "Inserting 1 at index 0...\n";
  vect.insert(1, 0);
  cout << "vect: ";
  vect.print();

  cout << "\n\nInserting 3 at index 2...\n";
  vect.insert(3, 2);
  cout << "vect: ";
  vect.print();

  cout << "\n\nInserting 6 at index 5...\n";
  vect.insert(6, 5);
  cout << "vect: ";
  vect.print();

  cout << endl;

  cout << "Length: " << vect.length() << endl;
  cout << "Size: " << vect.size();

  cout << endl << endl;

  cout << "Removing element at index 0...\n";
  vect.remove(0);
  cout << "vect: ";
  vect.print();

  cout << "\n\nRemoving element at index 4...\n";
  vect.remove(4);
  cout << "vect: ";
  vect.print();

  cout << "\n\nRemoving element at index 2...\n";
  vect.remove(2);
  cout << "vect: ";
  vect.print();

  cout << endl;

  cout << "Length: " << vect.length();

  cout << endl << endl;

  cout << "Second element: " << vect.retrieve(1) << endl;

  cout << endl;
}

int main() {
  test_vect();
  return EXIT_SUCCESS;
}
