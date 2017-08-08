#include <stdexcept>
#include <vector>
#include "singly_linked_list.h"

using std::vector;
using std::invalid_argument;


template <typename E>
class Graph {
private:
  SLinkedList<int>* adjacency_list;
  E* verticies;
  bool* visited;
  int capacity;

public:
  Graph(const int CAPACITY = 100);
  ~Graph();
  void add_vertex(const E, int);
  void add_edge(int, int);
  vector<E> adjacent_verticies(const int);

};


template <typename E>
Graph<E>::Graph(const int CAPACITY) {
  adjacency_list = new SLinkedList<int>[CAPACITY];
  verticies = new E[CAPACITY];
  visited = new bool[CAPACITY];
  capacity = CAPACITY;

  for (int i = 0; i < capacity; i++)
    visited[i] = false;
}

template <typename E>
Graph<E>::~Graph() {
  delete[] adjacency_list;
  delete[] verticies;
  delete[] visited;
}

template <typename E>
void Graph<E>::add_vertex(const E vertex_val, int vertex_index) {
  // check index range for exception
  verticies[vertex_index] = vertex_val;
}

template <typename E>
void Graph<E>::add_edge(int vertex1_index, int vertex2_index) {
  // check index for exception
  adjacency_list[vertex1_index].insert_front(vertex2_index);
  adjacency_list[vertex2_index].insert_front(vertex1_index);
}

template <typename E>
vector<E> Graph<E>::adjacent_verticies(const int vertex_index) {

  vector<E> adj_verticies;
  adj_verticies.resize(adjacency_list[vertex_index].length());

  for (int i = 0; i < adjacency_list[vertex_index].length(); i ++) {
    adj_verticies[i] = verticies[adjacency_list[vertex_index][i]];
  }

  return adj_verticies;
}