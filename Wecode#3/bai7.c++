#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
map<string, set<string>> adj_list;
map<string, int> colors;
vector<string> vertices;

void colorGraph()
{
  // Process each vertex in the order they were input
  for (const auto &vertex : vertices)
  {
    set<int> availableColors;
    for (int i = 0; i < vertices.size(); i++)
    {
      availableColors.insert(i);
    }
    // Check the colors of adjacent vertices
    for (const auto &adjVertex : adj_list[vertex])
    {
      int adjColor = colors[adjVertex];
      if (adjColor != -1)
      {
        // Remove the color of the adjacent vertex from available colors
        availableColors.erase(adjColor);
      }
    }

    // Assign the smallest available color to the current vertex
    colors[vertex] = *availableColors.begin();
  }

  // Print the colors of all vertices
  for (int i = 0; i < colors.size(); ++i)
  {
    cout << colors[vertices[i]] << " ";
  }
}

int main()
{

  int v, e;
  std::cin >> v >> e;

  string vertex;

  // input
  for (int i = 0; i < v; i++)
  {
    cin >> vertex;
    colors[vertex] = -1;
    vertices.push_back(vertex);
    adj_list[vertex];
  }
  for (int i = 0; i < e; i++)
  {
    string v1, v2;
    cin >> v1 >> v2;
    adj_list[v1].insert(v2);
    adj_list[v2].insert(v1);
  }
  colorGraph();

  return 0;
}