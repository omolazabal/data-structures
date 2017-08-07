#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::invalid_argument;
using std::length_error;

enum traversal_order {preorder, inorder, postorder};

template <typename E>
class BinarySearchTree;  // Let node class know BST exists.

template <typename E>
class Node {
  E data;
  Node<E>* left_child;
  Node<E>* right_child;
  friend class BinarySearchTree<E>;
};


template <typename E>
class BinarySearchTree {
private:
  Node<E>* root;
  int num_of_nodes;

  // Helper functions to perform recursion.
  void insert_helper(Node<E>* &, const E &);
  void remove_node(Node<E>* &);
  void remove_helper(Node<E>* &, const E &);
  E& retrieve_helper(Node<E>* &, const E &);
  void print_helper(Node<E>*, traversal_order);
  void remove_all_helper(Node<E>* &);

  bool is_leaf_node(Node<E>*);  // Check if node it a leaf node
  bool only_one_child(Node<E>*);  // Check if node has only one child node
  Node<E>* get_min_ptr(Node<E>*);  // Find the pointer that points to the
                                   // minimum value.

public:
  BinarySearchTree();
  ~BinarySearchTree();

  bool is_empty();
  int size();

  void insert(const E &);
  void remove(const E &);
  E& retrieve(const E &);

  void print(traversal_order);
  void remove_all();
};

template <typename E>
BinarySearchTree<E>::BinarySearchTree() {
  root = nullptr;
  num_of_nodes = 0;
}

template <typename E>
BinarySearchTree<E>::~BinarySearchTree() {
  remove_all_helper(root);
}

template <typename E>
bool BinarySearchTree<E>::is_empty() {
  // Returns true if tree is empty, else false.
  return root == nullptr;
}

template <typename E>
int BinarySearchTree<E>::size() {
  // Returns the number of nodes in the tree.
  return num_of_nodes;
}

template <typename E>
void BinarySearchTree<E>::insert_helper(Node<E>* &ptr, const E &elem) {
  // Recursively traverse utill you reach a leaf node's child node (nullptr). Once
  // reached, allocate a new node and replace the nullptr to point to that new node.

  if (ptr == nullptr) {
    // Add new node to tree.
    Node<E>* new_node = new Node<E>;
    new_node->data = elem;
    ptr = new_node;
    return;
  }

  // Traverse
  if (elem < ptr->data)
    insert_helper(ptr->left_child, elem);
  else if (elem > ptr->data)
    insert_helper(ptr->right_child, elem);
  else if (elem == ptr->data)
    throw invalid_argument("value is already in tree");
}

template <typename E>
bool BinarySearchTree<E>::is_leaf_node(Node<E>* ptr) {
  // Check it passed in pointer points to a leaf node.
  if (ptr->left_child == nullptr && ptr->right_child == nullptr)
    return true;
  return false;
}

template <typename E>
bool BinarySearchTree<E>::only_one_child(Node<E>* ptr) {
  // Check if passed in pointer points to a node with only one child.
  if (ptr->left_child == nullptr && ptr->right_child != nullptr)
    return true;
  if (ptr->right_child == nullptr && ptr->left_child != nullptr)
    return true;
  return false;
}

template <typename E>
Node<E>* BinarySearchTree<E>::get_min_ptr(Node<E>* ptr) {
  // Traverse the passed in pointer to the minimum value of the tree/subtree.
  if (ptr == nullptr)
    throw invalid_argument("ptr has null value, cannot find minimum value");

  if (ptr->left_child == nullptr)
    return ptr;

  return get_min_ptr(ptr->left_child);
}

template <typename E>
void BinarySearchTree<E>::remove_node(Node<E>* &ptr) {
  // Remove node that the passed in pointer points to. There are three cases
  // that have to be taken cared of: The node that needs to be removed (1) is
  // a leaf node, (2) has only one child, or (3) has two child nodes.

  if (is_leaf_node(ptr)) {
    // If leaf node, just delete.
    delete ptr;
    ptr = nullptr;
  }

  else if (only_one_child(ptr)) {
    // If node only has one child node then (depending on whether it is a right
    // child or left child) set the pointer to point to the child node and
    // delete the node that the pointer previously pointed to.

    if (ptr->left_child == nullptr) {
      // Change ptr to point to its right child and delete the node that it
      // previously pointed to.
      Node<E>* to_remove = ptr;
      ptr = ptr->right_child;
      delete to_remove;
      to_remove = nullptr;
    }
    else if (ptr->right_child == nullptr) {
      // Preform the same as above but with opposite child.
      Node<E>* to_remove = ptr;
      ptr = ptr->left_child;
      delete to_remove;
      to_remove = nullptr;
    }
  }

  // Case in which there are two children.
  else {
    // Find the minimum value of the subtree with ptr->right_child as root, then
    // replace ptr's data with the minimum value. Finally, delete the node that
    // originally had the minimum value.
    Node<E>* min = get_min_ptr(ptr->right_child);
    ptr->data = min->data;
    remove_helper(ptr->right_child, min->data);
  }
}

template <typename E>
void BinarySearchTree<E>::remove_helper(Node<E>* &ptr, const E &elem) {
  // Traverses ptr to the node that needs to be deleted.
  if (ptr == nullptr)
    throw invalid_argument("value not in tree");

  if (ptr->data == elem)
    remove_node(ptr);
  else if (elem < ptr->data)
    remove_helper(ptr->left_child, elem);
  else if (elem > ptr->data)
    remove_helper(ptr->right_child, elem);
}

template <typename E>
void BinarySearchTree<E>::insert(const E &elem) {
  // To remove an element. Call to insert helper.
  insert_helper(root, elem);
  num_of_nodes++;
}

template <typename E>
void BinarySearchTree<E>::remove(const E &elem) {
  // To remove an element. Call to remove helper.
  if (is_empty())
    throw length_error("tree is empty, nothing to remove");

  remove_helper(root, elem);
  num_of_nodes--;
};

template <typename E>
E& BinarySearchTree<E>::retrieve_helper(Node<E>* &ptr, const E &elem) {
  // Traverses to the node the matches elem. Returns that value.
  if (ptr == nullptr)
    throw invalid_argument("value not in tree");

  if (ptr->data == elem)
    return ptr->data;
  else if (elem < ptr->data)
    return retrieve_helper(ptr->left_child, elem);
  else if (elem > ptr->data)
    return retrieve_helper(ptr->right_child, elem);
}

template <typename E>
E& BinarySearchTree<E>::retrieve(const E &elem) {
  // Retrieve the node's data that matches elem. Call to retrieve_helper.
  if (is_empty())
    throw length_error("tree is empty, nothing to retrieve");
  return retrieve_helper(root, elem);
}

template <typename E>
void BinarySearchTree<E>::print_helper(Node<E>* ptr, traversal_order order) {
  // Performs preorder, inorder, and postorder traversal.
  if (ptr != nullptr) {
    // Pop off the recursive stack if reached nullptr.

    if (order == preorder) {
      cout << ptr->data << " ";
      print_helper(ptr->left_child, preorder);
      print_helper(ptr->right_child, preorder);
    }
    else if (order == inorder) {
      print_helper(ptr->left_child, inorder);
      cout << ptr->data << " ";
      print_helper(ptr->right_child, inorder);
    }
    else if (order == postorder) {
      print_helper(ptr->left_child, postorder);
      print_helper(ptr->right_child, postorder);
      cout << ptr->data << " ";
    }
  }
}

template <typename E>
void BinarySearchTree<E>::print(traversal_order order) {
  // Print values in the tree in the given order (preorder, inorder, or postorder).
  if (is_empty())
    throw length_error("tree is empty, nothing to print");

  print_helper(root, order);
  cout.flush();  // Flush output buffer to avoid data from not appearing on console.
}

template <typename E>
void BinarySearchTree<E>::remove_all_helper(Node<E>* &ptr) {
  // Traverses the tree in postorder order and removes the nodes one at a time.
  if (ptr != nullptr) {
    // Pop of the recursive stack if reached nullptr.
    remove_all_helper(ptr->left_child);
    remove_all_helper(ptr->right_child);
    delete ptr;
    ptr = nullptr;
  }
}

template <typename E>
void BinarySearchTree<E>::remove_all() {
  // Remove all nodes from tree. Call to remove_helper.
  if (is_empty())
    throw length_error("tree is empty, nothing to remove");

  remove_all_helper(root);
  num_of_nodes = 0;
}

#endif