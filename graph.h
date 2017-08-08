#include <stdexcept>
#include <vector>
#include "singly_linked_list.h"

using std::vector;
using std::invalid_argument;


template <typename E>
class Graph;  // Let Node class know graph exists

template <typename E>
class Vertex {
private:
  E value;
  int index;
  SLinkedList<Vertex*> adjacent_to;
  bool visited = false;
  friend class Graph<E>;
};


template <typename E>
class Graph {
private:
  Vertex<E>* adjacency_list;
  int capacity;

public:
  Graph(const int CAPACITY = 100);
  ~Graph();
  void add_vertex(const E, const int);
  void add_edge(const int, const int);
  vector<E> adjacent_verticies(const int);
};


template <typename E>
Graph<E>::Graph(const int CAPACITY) {
  adjacency_list = new Vertex<E>[CAPACITY];
  capacity = CAPACITY;
}

template <typename E>
Graph<E>::~Graph() {
  delete[] adjacency_list;
}

template <typename E>
void Graph<E>::add_vertex(const E vertex_val, const int vertex_index) {
  // check index range for exception
  Vertex<E> new_vertex;
  new_vertex.value = vertex_val;
  new_vertex.index = vertex_index;
  adjacency_list[vertex_index] = new_vertex;
}

template <typename E>
void Graph<E>::add_edge(const int vertex1_index, const int vertex2_index) {
  // check index for exception
  Vertex<E>* v1_ptr = &adjacency_list[vertex1_index];
  Vertex<E>* v2_ptr = &adjacency_list[vertex2_index];
  adjacency_list[vertex1_index].adjacent_to.insert_front(v2_ptr);
  adjacency_list[vertex2_index].adjacent_to.insert_front(v1_ptr);
}

template <typename E>
vector<E> Graph<E>::adjacent_verticies(const int vertex_index) {

  vector<E> adj_verticies;

  for (int i = 0; i < adjacency_list[vertex_index].adjacent_to.length(); i++) {
    adj_verticies.push_back(adjacency_list[vertex_index].adjacent_to[i]->value);
  }

  return adj_verticies;
}

