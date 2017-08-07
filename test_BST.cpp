
#include <iostream>
#include "binary_search_tree.h"

using namespace std;

void test_BST() {
  BinarySearchTree<int> tree;
  int numbers[] = {7, 6, 2, 5, 1, 3, 4, 11, 8, 9, 10, 13, 12, 14};

  cout << "Inserting 7 6 2 5 1 3 4 11 8 9 10 13 12 14 into tree...\n";
  for (int i = 0; i < 14; i++)
    tree.insert(numbers[i]);

  cout << "Size: " << tree.size();
  cout << "\nPreorder: ";
  tree.print(preorder);
  cout << "\nInorder: ";
  tree.print(inorder);
  cout << "\nPostorder: ";
  tree.print(postorder);

  cout << endl << endl;

  cout << "Inserting repeated value 5...\n";
  try {
      tree.insert(5);
  }
  catch(exception &e) {
    cerr << e.what();
  }
  cout << "\nInorder: ";
  tree.print(inorder);

  cout << endl << endl;

  cout << "Removing 4...\n";
  tree.remove(4);
  cout << "Size: " << tree.size();
  cout << "\nPreorder: ";
  tree.print(preorder);
  cout << "\nInorder: ";
  tree.print(inorder);
  cout << "\nPostorder: ";
  tree.print(postorder);

  cout << endl << endl;

  cout << "Removing 8...\n";
  tree.remove(8);
  cout << "Size: " << tree.size();
  cout << "\nPreorder: ";
  tree.print(preorder);
  cout << "\nInorder: ";
  tree.print(inorder);
  cout << "\nPostorder: ";
  tree.print(postorder);

  cout << endl << endl;

  cout << "Removing 11...\n";
  tree.remove(11);
  cout << "Size: " << tree.size();
  cout << "\nPreorder: ";
  tree.print(preorder);
  cout << "\nInorder: ";
  tree.print(inorder);
  cout << "\nPostorder: ";
  tree.print(postorder);

  cout << endl << endl;

  cout << "Removing 7...\n";
  tree.remove(7);
  cout << "Size: " << tree.size();
  cout << "\nPreorder: ";
  tree.print(preorder);
  cout << "\nInorder: ";
  tree.print(inorder);
  cout << "\nPostorder: ";
  tree.print(postorder);

  cout << endl << endl;

  cout << "Retrieving 5: " << tree.retrieve(5) << endl;
  cout << "Retreiving 9: " << tree.retrieve(9) << endl;

  cout << endl;

  cout << "Emptying tree...";
  tree.remove_all();
  cout << "\nInorder: ";

  try {
      tree.print(inorder);
  }
  catch (exception &e) {
      cerr << e.what();
  }

  cout << endl << endl;

}

int main() {
  test_BST();
  return EXIT_SUCCESS;
}
