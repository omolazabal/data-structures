
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::length_error;


template <typename E>
class SLinkedList;  // Let Node class know SLL exists.

template <typename E>
class Node {
private:
  E data;
  Node<E>* next;
  friend class SLinkedList<E>;
};


template <typename E>
class SLinkedList {
private:
  Node<E>* head;  // Pointer to front of the list.
  int num_of_nodes;
  void set_to_index(Node<E>* &ptr, int index); // Move pointer to node on given index

public:
  SLinkedList();
  ~SLinkedList();

  bool is_empty();
  int length();

  void insert_front(const E &elem);
  void remove_front();
  E& get_front();

  void insert(const E &elem, int index);
  void remove(int index);
  E& retrieve(int index);

  void print();
  void reverse();  // Reverse the list.
  E& operator[](int index);
};


template <typename E>
SLinkedList<E>::SLinkedList() {
  head = nullptr;
  num_of_nodes = 0;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {
  while (!is_empty())
    remove_front();
}

template <typename E>
bool SLinkedList<E>::is_empty() {
  // Returns true if there are nodes in the list, else returns false.
  return num_of_nodes == 0;
}

template <typename E>
int SLinkedList<E>::length() {
  // Returns number of nodes in the list.
  return num_of_nodes;
}

template <typename E>
void SLinkedList<E>::insert_front(const E &elem) {
  // Adds a new element to the front of the list.
  Node<E>* new_node = new Node<E>;
  new_node->data = elem;
  new_node->next = head;
  head = new_node;
  num_of_nodes++;
}

template <typename E>
void SLinkedList<E>::remove_front() {
  // Removes the front element of the list.
  if (is_empty())
    throw  length_error("list is empty");

  Node<E>* front = head;
  head = head->next;
  delete front;
  front = nullptr;
  num_of_nodes--;
}

template <typename E>
E& SLinkedList<E>::get_front() {
  // Returns the front element of the list.
  if (is_empty())
    throw length_error("list is empty");

  return head->data;
}

template <typename E>
void SLinkedList<E>::set_to_index(Node<E>* &ptr, int index) {
  // Traverses the given pointer to the given index.
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  ptr = head;
  for (; index > 0; index--)
    ptr = ptr->next;
}

template <typename E>
void SLinkedList<E>::insert(const E &elem, int index) {
  // Inserts data in the given index.
  if (index < 0 || index > num_of_nodes)
    throw out_of_range("index out of range");

  if (index == 0) {
    insert_front(elem);
    return;
  }

  Node<E>* new_node = new Node<E>;
  Node<E>* predecessor;  // Predecessor to new_node
  set_to_index(predecessor, index - 1);
  // Predecessor to traverse to the index - 1. This is done so that new_node
  // can be inserted at the specified index value.

  new_node->data = elem;
  new_node->next = predecessor->next;
  predecessor->next = new_node;
  num_of_nodes++;
}

template <typename E>
void SLinkedList<E>::remove(int index) {
  // Remove element at the given index.
  if (is_empty())
    throw length_error("SLinkedList is empty");
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  if (index == 0) {
    remove_front();
    return;
  }

  Node<E>* predecessor;
  set_to_index(predecessor, index - 1);

  Node<E>* to_remove = predecessor->next;
  predecessor->next = to_remove->next;

  delete to_remove;
  to_remove = nullptr;
  num_of_nodes--;
}

template <typename E>
E& SLinkedList<E>::retrieve(int index) {
  // Returns the element at the given index position.
  if (is_empty())
    throw length_error("list is empty");
  if (index < 0 || index > num_of_nodes)
    throw out_of_range("index out of range");

  Node<E>* current;
  set_to_index(current, index);
  return current->data;
}

template <typename E>
void SLinkedList<E>::print() {
  // Prints all of the elements in the list.
  if (is_empty())
    throw length_error("list is empty");

  Node<E>* current = head;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
}

template <typename E>
void SLinkedList<E>::reverse() {
  // Call to helper to reverse list
  if (is_empty())
    throw length_error("list is empty");
  Node<E>* predecessor = nullptr;
  Node<E>* current = head;
  Node<E>* successor = current;

  // Iterate through list and reverse the pointers of each node.
  while (current != nullptr) {
    successor = current->next;
    current->next = predecessor;
    predecessor = current;
    current = successor;
  }

  head = predecessor;
}

template <typename E>
E& SLinkedList<E>::operator[](int index) {
  // Overloads [] for convention.
  return retrieve(index);
}

#endif
