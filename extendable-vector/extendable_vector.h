
#ifndef EXTENDABLE_VECTOR_H
#define EXTENDABLE_VECTOR_H

#include <stdexcept>
#include <iostream>

using std::cout;
using std::out_of_range;
using std::invalid_argument;
using std::length_error;


template <typename E>
class Vector{
private:
  int end;  // Keeps track of the index where the end of the list is.
  int capacity;  // Keeps track of how many allocated spaces there are
                 // in the array.
  E *arr;
  void expand();

public:
  Vector(int capacity = 100);
  ~Vector();

  bool is_empty();
  int length();
  int size();

  void insert(E value, int index);
  void insert(E value);
  void remove(int index);
  void remove();
  void print();
  E& retrieve(int index);
  E& operator[](int index);
};


template <typename E>
Vector<E>::Vector(int capacity){
  if (capacity < 1)
    throw invalid_argument("length < 1");
  this->capacity = capacity;
  end = -1;
  arr = new E[capacity];
}

template <typename E>
Vector<E>::~Vector() { delete[] arr; }

template <typename E>
bool Vector<E>::is_empty() {
  // Returns true if the list is empty. Returns false if the list is
  // not empty.
  return end == -1;
}

template <typename E>
int Vector<E>::length() {
  // Returns the length of the list.
  return end + 1;
}

template <typename E>
int Vector<E>::size() {
  // Returns how many spaces have been allocated for the list.
  return capacity;
}

template <typename E>
void Vector<E>::expand() {
  // Create new array of double the size of the previous array to avoid
  // the cost of the operation.
  E *newArr = new E[capacity*2];
  for (int i = 0; i <= end; i++) {
    newArr[i] = arr[i];
  }

  // Delete old array and set it equal to the address of the new one.
  if (arr != nullptr)
    delete[] arr;
  arr = newArr;
  capacity = capacity*2;
}

template <typename E>
void Vector<E>::insert(E value, int index) {
  // Insert data into the list. If no index is specified
  // then the data will be inserted at the end of the list.
  if (index > end + 1 || index < 0)
    throw out_of_range("index out of range");
  if (end+1 == capacity)
    // Expand the array if it is full.
    expand();
  for (int i = end; i >= index; i--) {
    arr[i+1] = arr[i];
  }
  arr[index] = value;
  end++;
}

template <typename E>
void Vector<E>::insert(E value) {
  // Insert a value at the end of the list, unless an index
  // is specified; in that case data will be inserted at
  // that index.
  insert(value, end+1);
}

template <typename E>
void Vector<E>::remove(int index) {
  // Remove data from the list. If no index is specified
  // then the data will be removed from the end of the list.
  if (index > end || index < 0)
    throw out_of_range("index out of range");
  for (int i = index; i < end; i++) {
    arr[i] = arr[i+1];
  }
  end--;
}

template <typename E>
void Vector<E>::remove() {
  // Remove data from the end of the list, unless an index
  // is specified; in that case data will be removed at
  // that index.
  remove(end);
}

template <typename E>
E& Vector<E>::retrieve(int index) {
  // Retrieves data located at the specified index.
  if (index > end || index < 0)
    throw out_of_range("index out of range");
  return arr[index];
}

template <typename E>
void Vector<E>::print() {
  // Print contents of the vector.
  if (is_empty())
    throw length_error("vector is empty");
  for (int i = 0; i < length(); i++)
    cout << arr[i] << " ";
}

template <typename E>
E& Vector<E>::operator[](int index){
  // Overloads [] for convention.
  return retrieve(index);
}

#endif
