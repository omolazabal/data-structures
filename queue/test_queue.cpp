
#include <iostream>
#include "queue.h"

using namespace std;


int main() {
  Queue<int> queue;
  int input;
  int value;

  while (true) {
    cout << "\n\nQueue\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Get front\n";
    cout << "4. Get back\n";
    cout << "5. Print\n";
    cout << "6. Length\n\n";

    cout << "Selection: ";
    cin >> input;
    cout << endl;

    switch(input) {
      case 1:
        cout << "Enter a value: ";
        cin >> value;
        try { queue.enqueue(value); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 2:
        try { queue.dequeue(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 3:
        try { cout << queue.get_front(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 4:
        try { cout << queue.get_back(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 5:
        try { queue.print(); }
        catch (exception &e) { cerr << e.what(); }
        break;
      case 6:
        try { cout << queue.length(); }
        catch (exception &e) { cerr << e.what(); }
        break;
    }
  }
  return EXIT_SUCCESS;
}
