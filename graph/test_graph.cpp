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

  try {
    {
      vector<string> adj = graph.adjacent_verticies(313);
      cout << "Stations adjacent to Whitechapel:\n";
      for (auto i : adj)
        if (i == *--adj.end())
          cout << i;
        else
          cout << i << ", ";

      cout << endl << endl;

      vector<string> path = graph.find_path(313, 55);
      cout << "Path from Whitechapel to Charing_Cross:\n";
      for (auto i : path)
        if (i == *--path.end())
          cout << i;
        else
          cout << i << " --> ";

      cout.flush();
    }
    cout << endl << endl;
    {
      vector<string> adj = graph.adjacent_verticies(15);
      cout << "Stations adjacent to Barbican:\n";
      for (auto i : adj)
        if (i == *--adj.end())
          cout << i;
        else
          cout << i << ", ";

      cout << endl << endl;

      vector<string> path = graph.find_path(15, 137);
      cout << "Path from Barbican to Holborn:\n";
      for (auto i : path)
        if (i == *--path.end())
          cout << i;
        else
          cout << i << " --> ";

      cout.flush();
    }
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }
}

int main() {
  test_graph();
  return EXIT_SUCCESS;
}