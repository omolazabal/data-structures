#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::length_error;


template <typename E>
class DLinkedList;  // Let DNode class know DLL exists

template <typename E>
class DNode {
private:
  E data;
  DNode<E>* next = nullptr;
  DNode<E>* prev = nullptr;
  friend class DLinkedList<E>;
};


template <typename E>
class DLinkedList {
private:
  DNode<E>* header;  // Pointer to the front of the list
  DNode<E>* trailer;  // Pointer to the end of the list
  int num_of_nodes;
  DNode<E>* get_ptr_at(int);  // Traverse pointer to given index
  void insert_helper(DNode<E>*, const E &);
  void remove_helper(DNode<E>* &);

public:
  DLinkedList();
  ~DLinkedList();

  bool is_empty();
  int length();

  void insert_front(const E &);
  void remove_front();
  void insert_back(const E &);
  void remove_back();
  E& get_front();
  E& get_back();

  void insert(const E &, int);
  void remove(int);
  E& retrieve(int);

  void print();
  void reverse();  // Reverse the list
  E& operator[](int);
};

template <typename E>
DLinkedList<E>::DLinkedList() {
  // Initialize sentinel nodes.
  header = new DNode<E>;
  trailer = new DNode<E>;
  header->next = trailer;
  trailer->prev = header;
  num_of_nodes = 0;
}

template <typename E>
DLinkedList<E>::~DLinkedList() {
  // Delete all nodes, including sentinels.
  while (!is_empty())
    remove_front();
  delete header;
  delete trailer;
}

template <typename E>
bool DLinkedList<E>::is_empty() {
  // Returns true if list is empty, else returns false.
  return num_of_nodes == 0;
}

template <typename E>
int DLinkedList<E>::length() {
  // Return number of nodes in list.
  return num_of_nodes;
}

template <typename E>
void DLinkedList<E>::insert_helper(DNode<E>* predecessor, const E &elem) {
  // Allocates a new node and links it between its predecessor node (the one
  // passed in) and its successor node.
  DNode<E>* new_node = new DNode<E>;
  new_node->data = elem;

  DNode<E>* successor = predecessor->next;
  predecessor->next = new_node;
  successor->prev = new_node;
  new_node->next = successor;
  new_node->prev = predecessor;
  num_of_nodes++;
}

template <typename E>
void DLinkedList<E>::remove_helper(DNode<E>* &to_remove) {
  // Deletes the node that to_remove points to and links the nodes that are
  // its predecessor and successor nodes.
  DNode<E>* predecessor = to_remove->prev;
  DNode<E>* successor = to_remove->next;
  predecessor->next = successor;
  successor->prev = predecessor;
  delete to_remove;
  to_remove = nullptr;
  num_of_nodes--;
}

template <typename E>
void DLinkedList<E>::insert_front(const E &elem) {
  // Call to insert_helper to insert element after header.
  insert_helper(header, elem);
}

template <typename E>
void DLinkedList<E>::remove_front() {
  // Call to remove_helper to remove element after header.
  if (is_empty())
    throw length_error("list is empty");
  DNode<E>* to_remove = header->next;
  remove_helper(to_remove);
}

template <typename E>
void DLinkedList<E>::insert_back(const E &elem) {
  // Call to insert_helper to insert element before trailer.
  insert_helper(trailer->prev, elem);
}

template <typename E>
void DLinkedList<E>::remove_back() {
  // Call to remove_helper to remove element before trailer.
  if (is_empty())
    throw length_error("list is empty");
  DNode<E>* to_remove = trailer->prev;
  remove_helper(to_remove);
}

template <typename E>
E& DLinkedList<E>::get_front() {
  // Return front element.
  if (is_empty())
    throw length_error("list is empty");
  return header->next->data;
}

template <typename E>
E& DLinkedList<E>::get_back() {
  // Return back element.
  if (is_empty())
    throw length_error("list is empty");
  return trailer->prev->data;
}

template <typename E>
DNode<E>* DLinkedList<E>::get_ptr_at(int index) {
  // Traverses the given pointer to the given index. Checks to see if whether
  // traversing from the header vs trailer is faster.
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  DNode<E>* ptr;
  if (index <= (num_of_nodes - 1)/2) {
    ptr = header->next;
    for (; index > 0; index--)
      ptr = ptr->next;
  }
  else {
    ptr = trailer->prev;
    for (; index < num_of_nodes - 1; index++)
      ptr = ptr->prev;
  }
  return ptr;
}

template <typename E>
void DLinkedList<E>::insert(const E &elem, int index) {
  // Insert a new node at the given index.
  if (index == 0) {
    insert_front(elem);
    return;
  }
  if (index == num_of_nodes) {
    insert_back(elem);
    return;
  }

  DNode<E>* predecessor = get_ptr_at(index - 1);
  // Index - 1  because insert_helper inserts a node at the location that comes
  // after the passed in pointer.
  insert_helper(predecessor, elem);
}

template <typename E>
void DLinkedList<E>::remove(int index) {
  // Remove a node at the given index.
  if (is_empty())
    throw length_error("list is empty");
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  if (index == 0) {
    remove_front();
    return;
  }
  if (index == num_of_nodes - 1) {
    remove_back();
    return;
  }

  DNode<E>* to_remove = get_ptr_at(index);
  remove_helper(to_remove);
}

template <typename E>
E& DLinkedList<E>::retrieve(int index) {
  // Returns the element at the given index position.
  if (is_empty())
    throw length_error("list is empty");
  if (index < 0 || index > num_of_nodes)
    throw out_of_range("index is out of range");

  DNode<E>* ptr = get_ptr_at(index);
  return ptr->data;
}

template <typename E>
void DLinkedList<E>::print() {
  // Iterate and print all elements in the list.
  if (is_empty())
    throw length_error("list is empty");

  DNode<E>* current = header->next;
  while (current != trailer) {
    cout << current->data << " ";
    current = current->next;
  }
}

template <typename E>
void DLinkedList<E>::reverse() {
  // Reverse the list
  if (is_empty())
    throw length_error("list is empty");
  DNode<E>* current = header;
  DNode<E>* successor = current;

  while (current != nullptr) {
    successor = current->next;
    current->next = current->prev;
    current->prev = successor;
    current = successor;
  }

  // Swap header and trailer
  DNode<E>* temp = header;
  header = trailer;
  trailer = temp;
}

template <typename E>
E& DLinkedList<E>::operator[](int index) {
  // Overloads [] for convention.
  return retrieve(index);
}

#endif
