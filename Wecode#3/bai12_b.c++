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
};

Graph::Graph() {}

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

  priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> frontier(cmp);
  frontier.push(make_pair(base, heuristics[base]));

  set<string> explored;
  unordered_map<string, string> parent;
  unordered_map<string, int> distance;
  bool goalFound = false;
  distance[base] = 0;
  int pass = 0;

  while (!frontier.empty())
  {
    string current_node = frontier.top().first;
    int current_dist = frontier.top().second;
    frontier.pop();
    if (explored.count(current_node) > 0)
      continue;

    explored.insert(current_node);
    pass++;

    if (current_node == goal)
    {
      goalFound = true;
      break;
    }

    for (const auto &neighbor : adj_list[current_node])
    {
      string next_node = neighbor.first;
      int edge_weight = neighbor.second;

      int tentative_dist = distance[current_node] + edge_weight;
      if (distance.count(next_node) == 0 || tentative_dist < distance[next_node])
      {
        if (next_node == goal)
        {
          distance[next_node] = tentative_dist;
          int f_score = tentative_dist + heuristics[next_node];
          frontier.push(make_pair(next_node, f_score));
          parent[next_node] = current_node;
        }
        else
        {
          distance[next_node] = tentative_dist;
          parent[next_node] = current_node;
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
  Graph G;
  G.input();
  return 0;
}
