
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::length_error;


template <typename E>
class SLinkedList;  // Let SNode class know SLL exists.

template <typename E>
class SNode {
private:
  E data;
  SNode<E>* next = nullptr;
  friend class SLinkedList<E>;
};


template <typename E>
class SLinkedList {
private:
  SNode<E>* head;  // Pointer to front of the list.
  int num_of_nodes;
  SNode<E>* get_ptr_at(int); // Move pointer to node on given index

public:
  SLinkedList();
  ~SLinkedList();

  bool is_empty();
  int length();

  void insert_front(const E &);
  void remove_front();
  E& get_front();

  void insert(const E &, int);
  void remove(int);
  E& retrieve(int);

  void print();
  void reverse();  // Reverse the list.
  E& operator[](int);
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
  SNode<E>* new_node = new SNode<E>;
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

  SNode<E>* front = head;
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
SNode<E>* SLinkedList<E>::get_ptr_at(int index) {
  // Traverses the given pointer to the given index.
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  SNode<E>* ptr = head;
  for (; index > 0; index--)
    ptr = ptr->next;
  return ptr;
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

  SNode<E>* new_node = new SNode<E>;
  SNode<E>* predecessor = get_ptr_at(index - 1);  // Predecessor to new_node.
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
    throw length_error("list is empty");
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  if (index == 0) {
    remove_front();
    return;
  }

  SNode<E>* predecessor = get_ptr_at(index - 1);
  // Traverse predecessor to node that comes before the one that needs to
  // be deleted.

  SNode<E>* to_remove = predecessor->next;
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

  SNode<E>* current = get_ptr_at(index);
  return current->data;
}

template <typename E>
void SLinkedList<E>::print() {
  // Prints all of the elements in the list.
  if (is_empty())
    throw length_error("list is empty");

  SNode<E>* current = head;
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
  SNode<E>* predecessor = nullptr;
  SNode<E>* current = head;
  SNode<E>* successor = current;

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
