
#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::length_error;


template <typename E>
class Stack;  // Let StNode class know SLL exists.

template <typename E>
class StNode {
private:
  E data;
  StNode<E>* next = nullptr;
  friend class Stack<E>;
};


template <typename E>
class Stack {
private:
  StNode<E>* head;  // Pointer to front of the list.
  int num_of_nodes;
  StNode<E>* get_ptr_at(int); // Move pointer to node on given index

public:
  Stack();
  ~Stack();

  bool is_empty();
  int length();

  void push(const E &);
  void pop();
  E& top();
  void print();
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
  // Returns true if there are nodes in the list, else returns false.
  return num_of_nodes == 0;
}

template <typename E>
int Stack<E>::length() {
  // Returns number of nodes in the list.
  return num_of_nodes;
}

template <typename E>
void Stack<E>::push(const E &elem) {
  // Adds a new element to the front of the list.
  StNode<E>* new_node = new StNode<E>;
  new_node->data = elem;
  new_node->next = head;
  head = new_node;
  num_of_nodes++;
}

template <typename E>
void Stack<E>::pop() {
  // Removes the front element of the list.
  if (is_empty())
    throw  length_error("list is empty");

  StNode<E>* front = head;
  head = head->next;
  delete front;
  front = nullptr;
  num_of_nodes--;
}

template <typename E>
E& Stack<E>::top() {
  // Returns the front element of the list.
  if (is_empty())
    throw length_error("list is empty");

  return head->data;
}

template <typename E>
void Stack<E>::print() {
  // Prints all of the elements in the list.
  if (is_empty())
    throw length_error("list is empty");

  StNode<E>* current = head;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
}

#endif
