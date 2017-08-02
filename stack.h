
#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::length_error;


template <typename E>
class Stack;  // Let Node class know Stack exists.

template <typename E>
class Node {
private:
  E data;
  Node<E>* next;
  friend class Stack<E>;
};


template <typename E>
class Stack {
private:
  Node<E>* head;  // Pointer to front of the stack.
  int num_of_nodes;

  void set_to_index(Node<E>* &ptr, int index); // Move pointer to node on given index
  void reverse_helper(Node<E>* ptr);

public:
  Stack();
  ~Stack();

  bool is_empty();
  int length();

  void push(const E &elem);
  void pop();
  E& top();

  void insert(const E &elem, int index);
  void remove(int index);
  E& retrieve(int index);

  void print();
  void reverse();
  E& operator[](int index);
};


template <typename E>
Stack<E>::Stack() {
  head = nullptr;
  num_of_nodes = 0;
}

template <typename E>
Stack<E>::~Stack() {
  while (!is_empty())
    pop();
}

template <typename E>
bool Stack<E>::is_empty() {
  // Returns true if there are nodes in the stack, else
  // returns false.
  return num_of_nodes == 0;
}

template <typename E>
int Stack<E>::length() {
  // Returns number of nodes in stack.
  return num_of_nodes;
}

template <typename E>
void Stack<E>::push(const E& elem) {
  // Adds a new element to the top of the stack.
  Node<E>* new_node = new Node<E>;
  new_node->data = elem;
  new_node->next = head;
  head = new_node;
  num_of_nodes++;
}

template <typename E>
void Stack<E>::pop() {
  // Removes the top element of the stack.
  if (is_empty())
    throw  length_error("stack is empty");

  Node<E>* temp = head;
  head = head->next;
  delete temp;
  num_of_nodes--;
}

template <typename E>
E& Stack<E>::top() {
  // Returns the top element of the stack.
  if (is_empty())
    throw length_error("stack is empty");

  return head->data;
}

template <typename E>
void Stack<E>::set_to_index(Node<E>* &ptr, int index) {
  // Traverses the given pointer to the given index.
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  ptr = head;
  for (; index > 0; index--)
    ptr = ptr->next;
}

template <typename E>
void Stack<E>::insert(const E& elem, int index) {
  // Inserts data in the given index.
  if (index < 0 || index > num_of_nodes)
    throw out_of_range("index out of range");

  if (index == 0) {
    push(elem);
    return;
  }

  Node<E>* new_node = new Node<E>;
  Node<E>* current;
  set_to_index(current, index - 1);
  // current to traverse to the index - 1. This is done so that a new
  // node can be inserted at the specified index value safely.

  new_node->data = elem;
  new_node->next = current->next;
  current->next = new_node;
  num_of_nodes++;
}

template <typename E>
void Stack<E>::remove(int index) {
  // Remove element at the given index.
  if (is_empty())
    throw length_error("stack is empty");
  if (index < 0 || index > num_of_nodes - 1)
    throw out_of_range("index out of range");

  if (index == 0) {
    pop();
    return;
  }

  Node<E>* current;
  set_to_index(current, index - 1);

  Node<E>* temp = current->next;
  current->next = temp->next;

  delete temp;
  num_of_nodes--;
}

template <typename E>
E& Stack<E>::retrieve(int index) {
  // Returns the element at the given index position.
  if (is_empty())
    throw length_error("stack is empty");
  if (index < 0 || index > num_of_nodes)
    throw out_of_range("index out of range");

  Node<E>* current;
  set_to_index(current, index);

  return current->data;
}

template <typename E>
void Stack<E>::print() {
  // Prints all of the elements in the stack.
  if (is_empty())
    throw length_error("stack is empty");

  Node<E>* current = head;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
}

template <typename E>
void Stack<E>::reverse() {
  // Call to helper to reverse stack
  if (is_empty())
    throw length_error("stack is empty");
  reverse_helper(head);
}

template <typename E>
void Stack<E>::reverse_helper(Node<E>* ptr) {
  // Reverse the stack
  if (ptr->next == nullptr){
    head = ptr;
    return;
  }

  reverse_helper(ptr->next);
  ptr->next->next = ptr;
  ptr->next = nullptr;
}

template <typename E>
E& Stack<E>::operator[](int index){
  // Overloads [] for convention.
  return retrieve(index);
}

#endif
