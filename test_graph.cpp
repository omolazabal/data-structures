#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

void test_graph() {
  Graph<string> graph(400);

  ifstream name_file("station_names.txt");
  if (!name_file)
    cout << "unable to open file";
  else {
    string vertex_name;
    int vertex_index;

    while (name_file) {
      name_file >> vertex_name >> vertex_index;
      graph.add_vertex(vertex_name, vertex_index);
    }
    name_file.close();
  }

  ifstream route_file("station_route.txt");
  if (!route_file)
	  cout << "unable to open file";
  else {
	  int vertex1_index;
	  int vertex2_index;

	  while (route_file) {
		  route_file >> vertex1_index >> vertex2_index;
		  graph.add_edge(vertex1_index, vertex2_index);
	  }
	  route_file.close();
  }

  vector<string> test = graph.adjacent_verticies(0);
  for (vector<string>::iterator i = test.begin(); i != test.end(); i++)
    cout << *i << endl;

}

int main() {
  test_graph();
  return EXIT_SUCCESS;
}