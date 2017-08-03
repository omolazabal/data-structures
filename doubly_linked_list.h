#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::length_error;


template <typename E>
class DLinkedList;  // Let Node class know DLL exists

template <typename E>
class Node {
private:
  E data;
  Node<E>* next;
  Node<E>* prev;
  friend class DLinkedList<E>;
};


template <typename E>
class DLinkedList {
private:
  Node<E>* header;  // Pointer to the front of the list
  Node<E>* trailer;  // Pointer to the end of the list
  int num_of_nodes;
  void set_to_index(Node<E>* &ptr, int index);  // Traverse pointer to given index
  void insert_helper(Node<E>* ptr, const E &elem);
  void remove_helper(Node<E>* ptr);
  void reverse_helper(Node<E>* ptr);

public:
  DLinkedList();
  ~DLinkedList();

  bool is_empty();
  int length();

  void insert_front(const E &elem);
  void remove_front();
  void insert_back(const E &elem);
  void remove_back();
  E& get_front();
  E& get_back();

  void insert(const E &elem, int index);
  void remove(int index);
  E& retrieve(int index);

  void print();
  void reverse();  // Reverse the list
  E& operator[](int index);
};

template <typename E>
DLinkedList<E>::DLinkedList() {
  // Initialize sentinel nodes.
  header = new Node<E>;
  trailer = new Node<E>;
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
  header = nullptr;
  delete trailer;
  trailer = nullptr;
}

template <typename E>
bool DLinkedList<E>::is_empty() {
  // Returns true if list is empty, else returns false.
  return num_of_nodes == 0;
}

template <typename E>
int DLinkedList<E>::length() {
  // Return num of nodes in list.
  return num_of_nodes;
}

template <typename E>
void DLinkedList<E>::insert_helper(Node<E>* ptr, const E &elem) {
  // Allocates a new node and links it between ptr's node and the node after ptr.
  Node<E>* new_node = new Node<E>;
  new_node->data = elem;

  Node<E>* after_ptr = ptr->next;
  ptr->next = new_node;
  after_ptr->prev = new_node;
  new_node->next = after_ptr;
  new_node->prev = ptr;
  num_of_nodes++;
}

template <typename E>
void DLinkedList<E>::remove_helper(Node<E>* ptr) {
  // Deletes the node that ptr points to and links the nodes that are before
  // ptr and after ptr.
  Node<E>* before_ptr = ptr->prev;
  Node<E>* after_ptr = ptr->next;
  before_ptr->next = after_ptr;
  after_ptr->prev = before_ptr;
  delete ptr;
  num_of_nodes--;
}

template <typename E>
void DLinkedList<E>::insert_front(const E &elem) {
  insert_helper(header, elem);
}

template <typename E>
void DLinkedList<E>::remove_front() {
  remove_helper(header->next);
}

template <typename E>
void DLinkedList<E>::insert_back(const E &elem) {
  insert_helper(trailer->prev, elem);
}

template <typename E>
void DLinkedList<E>::remove_back() {
  remove_helper(trailer->prev);
}

template <typename E>
E& DLinkedList<E>::get_front() {
  return header->next->data;
}

template <typename E>
E& DLinkedList<E>::get_back() {
  return trailer->prev->data;
}

template <typename E>
void DLinkedList<E>::set_to_index(Node<E>* &ptr, int index) {
  // Traverses the given pointer to the given index.a
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

  Node<E>* ptr;
  set_to_index(ptr, index - 1);  // index - 1 because insert_helper() inserts a
  insert_helper(ptr, elem);            // node after the passed in pointer.
}

template <typename E>
void DLinkedList<E>::remove(int index) {
  // Remove a node at the given index.
  if (index == 0) {
    remove_front();
    return;
  }
  if (index == num_of_nodes - 1) {
    remove_back();
    return;
  }

  Node<E>* ptr;
  set_to_index(ptr, index);
  remove_helper(ptr);
}

template <typename E>
E& DLinkedList<E>::retrieve(int index) {
  // Returns the element at the given index position.
  Node<E>* ptr;
  set_to_index(ptr, index);
  return ptr->data;
}

template <typename E>
void DLinkedList<E>::print() {
  Node<E>* current = header->next;
  while (current != trailer) {
    cout << current->data << " ";
    current = current->next;
  }
}

template <typename E>
void DLinkedList<E>::reverse() {
  reverse_helper(header);
}

template <typename E>
void DLinkedList<E>::reverse_helper(Node<E>* ptr) {
  // Reverse the list
  if (ptr == trailer) {
    Node<E>* temp = header;
    header = trailer;
    trailer = temp;
    header->prev = header->next;
    return;
  }

  reverse_helper(ptr->next);
  ptr->next->next = ptr;
  ptr->prev = ptr->next;
  ptr->next = nullptr;
}

template <typename E>
E& DLinkedList<E>::operator[](int index) {
  // Overloads [] for convention.
  return retrieve(index);
}

#endif
