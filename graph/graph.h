#ifndef GRAPH_H
#define GRAPH_H

#include <stdexcept>
#include <vector>
#include "singly_linked_list.h"
#include "queue.h"

using std::vector;
using std::invalid_argument;


template <typename E>
class Graph;  // Let Node class know graph exists.

template <typename E>
class Vertex {
  E value;
  int index;
  Vertex<E>* parent = nullptr;  // Points to parent when performing BFS.
  SLinkedList<Vertex*> neighbors;  // Adjacent verticies.
  bool visited = false;  // Has been visited during BFS.
  friend class Graph<E>;
};


template <typename E>
class Graph {
private:
  Vertex<E>* adjacency_list;
  bool* is_empty;  // Keeps track of which slots in adj list are empty.
  int capacity;  // How many verticies in adj list.
  void reset();  // Reset all verticies visited/parent status to defaults.

public:
  Graph(const int CAPACITY = 100);
  ~Graph();
  void add_vertex(const E, const int);
  void add_edge(const int, const int);
  vector<E> adjacent_verticies(const int);
  vector<E> find_path(const int, const int);
};


template <typename E>
Graph<E>::Graph(const int CAPACITY) {
  // Allocate new adj list with passed in capacity.
  adjacency_list = new Vertex<E>[CAPACITY];
  is_empty = new bool[CAPACITY];
  capacity = CAPACITY;

  for (int i = 0; i < capacity; i++)
    is_empty[i] = true;
}

template <typename E>
Graph<E>::~Graph() {
  // Free adj list from memory.
  delete[] adjacency_list;
  delete[] is_empty;
}

template <typename E>
void Graph<E>::add_vertex(const E vertex_val, const int vertex_index) {
  // Adds verticies to the adj list. Verticies store a value and an index.
  // The index corresponds with their position in the adj list.
  if (vertex_index < 0 || vertex_index >= capacity)
    throw invalid_argument("vertex index value exceeds capacity");

  Vertex<E> new_vertex;
  new_vertex.value = vertex_val;
  new_vertex.index = vertex_index;
  adjacency_list[vertex_index] = new_vertex;
  is_empty[vertex_index] = false;
}

template <typename E>
void Graph<E>::add_edge(const int vertex1_index, const int vertex2_index) {
  // Link the verticies that are located at the corresponding indices. Linking
  // is done by adding each vertex to eachother's neighbors linked list. This
  // is an undirected graph that is not weighted.
  if (vertex1_index < 0 || vertex1_index >= capacity ||
      vertex2_index < 0 || vertex2_index >= capacity)
    throw invalid_argument("vertex index value exceeds capacity");
  if (is_empty[vertex1_index] || is_empty[vertex2_index])
    throw invalid_argument("no vertex at specified index");

  Vertex<E>* v1_ptr = &adjacency_list[vertex1_index];
  Vertex<E>* v2_ptr = &adjacency_list[vertex2_index];
  adjacency_list[vertex1_index].neighbors.insert_front(v2_ptr);
  adjacency_list[vertex2_index].neighbors.insert_front(v1_ptr);
}

template <typename E>
vector<E> Graph<E>::adjacent_verticies(const int vertex_index) {
  // Return the adjacent verticies (neighbors) of the vertex that has the index
  // vertex_index. Adjacent verticies are stored in the neighbors linked list
  // of the vertex.
  if (vertex_index < 0 || vertex_index >= capacity)
    throw invalid_argument("vertex index value exceeds capacity");
  if (is_empty[vertex_index])
    throw invalid_argument("no vertex at specified index");
  if (adjacency_list[vertex_index].neighbors.length() == 0)
    throw invalid_argument("vertex has no neighbors");

  vector<E> neighbors;
  neighbors.reserve(adjacency_list[vertex_index].neighbors.length());

  for (int i = 0; i < adjacency_list[vertex_index].neighbors.length(); i++)
   neighbors.push_back(adjacency_list[vertex_index].neighbors[i]->value);

  return neighbors;
}

template <typename E>
vector<E> Graph<E>::find_path(const int start, const int end) {
  // Finds the shortest path to the destination using Breadth First Search.
  // Parent will be used to keep track of the shortest path. To obtain the
  // shortest path, we first need to reach the end using BFS. We will then
  // trace our way back to the start using the parent pointer.
  if (start < 0 || start >= capacity || end < 0 || end >= capacity)
    throw invalid_argument("vertex index value exceeds capacity");
  if (is_empty[start] || is_empty[end])
    throw invalid_argument("no vertex at specified index");
  if (adjacency_list[start].neighbors.length() == 0 ||
      adjacency_list[end].neighbors.length() == 0 )
    throw invalid_argument("vertex has no neighbors");

  Queue<int> queue;
  int current;
  int neighbor;

  adjacency_list[start].visited = true;
  queue.enqueue(start);

  while (!queue.is_empty()) {
    current = queue.get_front();
    queue.dequeue();

    for (int i = 0; i < adjacency_list[current].neighbors.length(); i++) {
      // For each neighbor of current...
      neighbor = adjacency_list[current].neighbors[i]->index;
      if (neighbor == end) {
        // Check if the neighbor is the end. In this case assign its parent and
        // exit BFS.
        adjacency_list[neighbor].parent = &adjacency_list[current];
        break;
      }
      if (!adjacency_list[neighbor].visited) {
        // else, check if the neighbor has been visited. If it hasnt, visit it,
        // set its parent, and enqueue it so that its neighbors can eventually
        // be checked.
        adjacency_list[neighbor].visited = true;
        adjacency_list[neighbor].parent = &adjacency_list[current];
        queue.enqueue(neighbor);
      }
    }
    if (neighbor == end) break; // Executes if we find the end as a neighbor.
  }

  if (queue.is_empty())
    throw invalid_argument("end cannot be reached");

  vector<E> path;
  Vertex<E>* temp = &adjacency_list[neighbor];

  while (temp != nullptr) {
    // Trace back to the start. Save the path as we navigate back. Should use
    // std::list instead of vector but whatevs.
    path.insert(path.begin(), temp->value);
    temp = temp->parent;
  }

  reset();
  return path;
}

template <typename E>
void Graph<E>::reset() {
  // Resets the parents and visited values of the vertcies to their default values.
  for (int i = 0; i < capacity; i++) {
    adjacency_list[i].parent = nullptr;
    adjacency_list[i].visited = false;
  }
}

#endif