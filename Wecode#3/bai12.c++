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
int v, e;
string base, goal;
class Graph
{

public:
  map<string, map<string, int>> adj_list;
  map<string, int> heuristics;
  vector<string> vertices;
  map<string, int> rMap;
  Graph();
  void input();
  void AStar(string &, string &);
  void myProcess();
};
Graph::Graph()
{
}
void Graph::input()
{
  cin >> v >> e;
  cin >> base >> goal;
  for (int i = 0; i < v; i++)
  {
    string vertex;
    cin >> vertex;
    heuristics[vertex] = 0;
    vertices.push_back(vertex);
    rMap[vertex] = i;
  }
  for (int i = 0; i < v; i++)
  {
    int dist;
    cin >> dist;
    heuristics[vertices[i]] = dist;
  }
  for (int i = 0; i < e; i++)
  {
    string v1, v2;
    int x;
    cin >> v1 >> v2 >> x;
    adj_list[v1][v2] = x;
  }
  AStar(base, goal);
}

// this function is used to implement AStar search algorithm
void Graph::AStar(string &base, string &goal)
{

  auto cmp = [&](pair<string, int> a, pair<string, int> b)
  {
    if (a.second < b.second)
    {
      return false;
    }
    if (a.second == b.second)
    {
      return rMap[a.first] > rMap[b.first];
    }
    return true;
  };

  // Create a queue to store the nodes that are waiting to be explore
  priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> frontier(cmp);

  frontier.push(make_pair(base, heuristics[base]));

  // Create a set to store the nodes that have been expanded
  set<string> explored;
  // Create a map to store the parent nodes and distance from the base node
  unordered_map<string, string> parent;
  unordered_map<string, int> distance;
  bool goalFound = false;
  distance[base] = 0;

  while (!frontier.empty())
  {
    // Get the node with the smallest distance from the priority queue
    string current_node = frontier.top().first;
    int current_dist = frontier.top().second;
    frontier.pop();

    // Skip this node if it has already been explored
    if (explored.count(current_node) > 0)
    {
      if (current_dist >= distance[current_node])
        continue;
      explored.erase(current_node);
    }

    // Add the current node to the set of explored nodes.
    explored.insert(current_node);

    // Check if the current node is the goal node
    if (current_node == goal)
    {
      goalFound = true;
      break;
    }

    for (auto neighbor : adj_list[current_node])
    {
      string next_node = neighbor.first;
      int edge_cost = neighbor.second;

      // calculate the new distance to the next node
      int new_distance = distance[current_node] + edge_cost;

      if (distance.count(next_node) == 0 || new_distance < distance[next_node])
      {
        if (explored.count(next_node) > 0)
          explored.erase(next_node);
        distance[next_node] = new_distance;
        // calculate the new f = g + h (priority) to the next node
        int priority = new_distance + heuristics[next_node];

        frontier.push(make_pair(next_node, priority));
        parent[next_node] = current_node;
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
    cout << explored.size() << " " << distance[goal] << endl;
  }
  else
  {
    cout << "-unreachable-" << endl;
    cout << explored.size() << " " << distance[goal] << endl;
  }
}

int main()
{
  Graph G;
  G.input();
  return 0;
}