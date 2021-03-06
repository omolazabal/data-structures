#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::length_error;


template <typename E>
class Queue;  // Let Node class know DLL exists

template <typename E>
class QNode {
private:
  E data;
  QNode<E>* next = nullptr;
  QNode<E>* prev = nullptr;
  friend class Queue<E>;
};


template <typename E>
class Queue {
private:
  QNode<E>* header;  // Pointer to the front of the list
  QNode<E>* trailer;  // Pointer to the end of the list
  int num_of_nodes;
  void insert_helper(QNode<E>*, const E &);
  void remove_helper(QNode<E>* &);

public:
  Queue();
  ~Queue();

  bool is_empty();
  int length();

  void dequeue();
  void enqueue(const E &);
  E& get_front();
  E& get_back();

  void print();
};

template <typename E>
Queue<E>::Queue() {
  // Initialize sentinel nodes.
  header = new QNode<E>;
  trailer = new QNode<E>;
  header->next = trailer;
  trailer->prev = header;
  num_of_nodes = 0;
}

template <typename E>
Queue<E>::~Queue() {
  // Delete all nodes, including sentinels.
  while (!is_empty())
    dequeue();
  delete header;
  delete trailer;
}

template <typename E>
bool Queue<E>::is_empty() {
  // Returns true if list is empty, else returns false.
  return num_of_nodes == 0;
}

template <typename E>
int Queue<E>::length() {
  // Return number of nodes in list.
  return num_of_nodes;
}

template <typename E>
void Queue<E>::insert_helper(QNode<E>* predecessor, const E &elem) {
  // Allocates a new node and links it between its predecessor node (the one
  // passed in) and its successor node.
  QNode<E>* new_node = new QNode<E>;
  new_node->data = elem;

  QNode<E>* successor = predecessor->next;
  predecessor->next = new_node;
  successor->prev = new_node;
  new_node->next = successor;
  new_node->prev = predecessor;
  num_of_nodes++;
}

template <typename E>
void Queue<E>::remove_helper(QNode<E>* &to_remove) {
  // Deletes the node that to_remove points to and links the nodes that are
  // its predecessor and successor nodes.
  QNode<E>* predecessor = to_remove->prev;
  QNode<E>* successor = to_remove->next;
  predecessor->next = successor;
  successor->prev = predecessor;
  delete to_remove;
  to_remove = nullptr;
  num_of_nodes--;
}

template <typename E>
void Queue<E>::dequeue() {
  // Call to remove_helper to remove element after header.
  if (is_empty())
    throw length_error("list is empty");
  QNode<E>* to_remove = header->next;
  remove_helper(to_remove);
}

template <typename E>
void Queue<E>::enqueue(const E &elem) {
  // Call to insert_helper to insert element before trailer.
  insert_helper(trailer->prev, elem);
}

template <typename E>
E& Queue<E>::get_front() {
  // Return front element.
  if (is_empty())
    throw length_error("list is empty");
  return header->next->data;
}

template <typename E>
E& Queue<E>::get_back() {
  // Return back element.
  if (is_empty())
    throw length_error("list is empty");
  return trailer->prev->data;
}

template <typename E>
void Queue<E>::print() {
  // Iterate and print all elements in the list.
  if (is_empty())
    throw length_error("list is empty");

  QNode<E>* current = header->next;
  while (current != trailer) {
    cout << current->data << " ";
    current = current->next;
  }
}

#endif
