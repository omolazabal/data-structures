#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::invalid_argument;

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

  bool is_leaf_node(Node<E>*);
  bool only_one_child(Node<E>*);
  Node<E>* get_min_ptr(Node<E>*);

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
  size = 0;
}

template <typename E>
BinarySearchTree<E>::~BinarySearchTree() {
  remove_all();
}

template <typename E>
bool BinarySearchTree<E>::is_empty() {
  return root == nullptr;
}

template <typename E>
int BinarySearchTree<E>::size() {
  return num_of_nodes;
}

template <typename E>
void BinarySearchTree<E>::insert_helper(Node<E>* &ptr, const E &elem) {
  // Recursively traverse till reach a leaf node's child node (nullptr). Once
  // reached, allocate a new node and replace the nullptr to point to a new node.
  if (ptr == nullptr) {
    Node<E>* new_node = new Node<E>;
    new_node->data = elem;
    ptr = new_node;
    return;
  }

  if (elem < ptr->data)
    insert_helper(ptr->left_child, elem);
  else if (elem > ptr->data)
    insert_helper(ptr->right_child, elem);
  else if (elem == ptr->data)
    throw invalid_argument("value is already in tree");
}

template <typename E>
bool BinarySearchTree<E>::is_leaf_node(Node<E>* ptr) {
  // TODO empty exception
  if (ptr->left_child == nullptr && ptr->right_child == nullptr)
    return true;
  return false;
}

template <typename E>
bool BinarySearchTree<E>::only_one_child(Node<E>* ptr) {
  // TODO empty exception
  if (ptr->left_child == nullptr && ptr->right_child != nullptr)
    return true;
  if (ptr->right_child == nullptr && ptr->left_child != nullptr)
    return true;
  return false;
}

template <typename E>
Node<E>* BinarySearchTree<E>::get_min_ptr(Node<E>* ptr) {
  // TODO empty exception
  if (ptr->left_child == nullptr) {
    return ptr;
  }
  return get_min_ptr(ptr);
}

template <typename E>
void BinarySearchTree<E>::remove_node(Node<E>* &ptr) {
  if (is_leaf_node(ptr)) {
    delete ptr;
    ptr = nullptr;
  }

  else if (only_one_child(ptr)) {
    if (ptr->left_child == nullptr) {
      // Change ptr to point to its right child and delete the node that it
      // use to point to.
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
    Node<E>* temp = find_min(ptr->right_child);
    ptr->data = temp->data;
    remove_node(temp);
  }
}

template <typename E>
void BinarySearchTree<E>::remove_helper(Node<E>* &ptr, const E &elem) {
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
  insert_helper(elem);
}

template <typename E>
void BinarySearchTree<E>::remove(const E &elem) {
  remove_helper(root, elem);
};

template <typename E>
E& BinarySearchTree<E>::retrieve_helper(Node<E>* &ptr, const E &elem) {
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
  return retrieve_helper(root, elem);
}

template <typename E>
void BinarySearchTree<E>::print_helper(Node<E>* ptr, traversal_order order) {
  if (ptr != nullptr) {
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
  print_helper(root, order);
}

template <typename E>
void BinarySearchTree<E>::remove_all_helper(Node<E>* &ptr) {
  if (ptr != nullptr) {
    remove_all_helper(ptr->left_child);
    remove_all_helper(ptr->right_child);
    delete ptr;
    ptr = nullptr;
  }
}

template <typename E>
void BinarySearchTree<E>::remove_all() {
  remove_all_helper(root);
}

#endif