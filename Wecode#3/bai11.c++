#include <iostream>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int v;
class Graph
{

public:
  vector<vector<int>> matrix;
  unordered_map<string, int> mapping;
  unordered_map<int, string> rMap;
  Graph();
  void input(int &v);
  void Dijkstra(string &, string &);
  void myProcess(int &n);
};
Graph::Graph()
{
  matrix = vector<vector<int>>(0, vector<int>(0, 0));
}
void Graph::input(int &v)
{
  matrix = vector<vector<int>>(v, vector<int>(v, 0));
  for (int i = 0; i < v; i++)
  {
    string temp;
    cin >> temp;
    mapping[temp] = i;
    rMap[i] = temp;
  }
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      cin >> matrix[i][j];
    }
  }
}
void Graph::myProcess(int &n)
{
  while (n--)
  {
    string u, i;
    cin >> u >> i;
    Dijkstra(u, i);
  }
}
// this function is used to implement Dijkstra search algorithm
void Graph::Dijkstra(string &base, string &goal)
{
  // Create a queue to store the nodes that are waiting to be explored
  auto cmp = [&](pair<string, int> a, pair<string, int> b)
  {
    if (a.second < b.second)
    {
      return false;
    }
    if (a.second == b.second)
    {
      return mapping[a.first] < mapping[b.first];
    }
    return true;
  };
  priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> frontier(cmp);

  frontier.push(make_pair(base, 0));

  // Create a set to store the nodes that have been expanded
  set<string> explored;
  // Create a map to store the parent nodes and distance from the base node
  unordered_map<string, string> parent;
  unordered_map<string, int> distance;
  bool goalFound = false;
  distance[base] = 0;
  int pass = 0;

  while (!frontier.empty())
  {
    // Get the node with the smallest distance from the priority queue
    string current_node = frontier.top().first;
    int current_distance = frontier.top().second;
    frontier.pop();

    // Skip this node if it has already been explored
    if (explored.find(current_node) != explored.end())
      continue;
    pass++;
    // Add the current node to the set of explored nodes
    explored.insert(current_node);

    // Check if the current node is the goal node
    if (current_node == goal)
    {
      goalFound = true;
      break;
    }

    // Explore the neighbors of the current node
    int current_index = mapping[current_node];
    for (int i = v - 1; i >= 0; i--)
    {
      int weight = matrix[current_index][i];
      if (weight > 0)
      {
        string neighbor = rMap[i];

        // Calculate the new distance to the neighbor
        int new_distance = current_distance + weight;

        // Update the distance and parent if the new distance is smaller
        if (distance.find(neighbor) == distance.end() || new_distance < distance[neighbor])
        {
          distance[neighbor] = new_distance;
          parent[neighbor] = current_node;
          frontier.push(make_pair(neighbor, new_distance));
        }
      }
    }
  }

  if (goalFound)
  {
    vector<string> path;
    path.push_back(goal);
    string current_node = path.back();
    while (current_node != base)
    {
      current_node = parent[current_node];
      path.push_back(current_node);
    }
    for (int i = path.size() - 1; i >= 0; i--)
    {
      cout << path[i] << " ";
    }
    cout << endl;
    cout << pass << " " << distance[goal] << endl;
  }
  else
  {
    cout << "-unreachable-" << endl;
    cout << pass << " " << distance[goal] << endl;
  }
}

int main()
{
  int n;
  Graph G;
  cin >> v >> n;
  G.input(v);
  G.myProcess(n);
  return 0;
}