
#include <iostream>
#include "queue.h"

using namespace std;

void test_list() {
  Queue<int> queue;
  cout << "Enqueuing 2 4 5 6...\n";
  queue.enqueue(2);
  queue.enqueue(4);
  queue.enqueue(5);
  queue.enqueue(6);

  cout << "queue: ";
  queue.print();

  cout << endl;

  cout << "Length: " << queue.length();

  cout << endl << endl;

  cout << "Dequeuing 2 elements...\n";
  queue.dequeue();
  queue.dequeue();

  cout << "queue: ";
  queue.print();

  cout << endl;

  cout << "Length: " << queue.length();

  cout << endl << endl;

  cout << "Front element: " << queue.get_front() << endl;

  cout << "Back element: " << queue.get_back() << endl;

  cout << endl;
}

int main() {
  test_list();
  return EXIT_SUCCESS;
}
