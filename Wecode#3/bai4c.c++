
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

map<string, map<string, int>> adj_list;
set<string> vertices;
vector<string> path;
vector<string> best_path;
set<string> explored;
map<string, int> dist;
int min_path = 10000000;
string s;

void attempt(int i)
{
  if (i == vertices.size())
  {
    if (adj_list[path[i]].find(s) == adj_list[path[i]].end())
      return;
    int last_distance = dist[path[i]] + adj_list[path[i]][s];
    if (last_distance < min_path)
    {
      path.push_back(s);
      best_path = path;
      min_path = last_distance;
      path.pop_back();
    }
  }
  for (auto adjNode : adj_list[path[i]])
  {
    if (explored.find(adjNode.first) == explored.end())
    {
      path.push_back(adjNode.first);
      dist[adjNode.first] = dist[path[i]] + adjNode.second;
      explored.insert(adjNode.first);
      attempt(i + 1);
      explored.erase(adjNode.first);
      path.pop_back();
    }
  }
}
int main()
{
  int e;

  cin >> e;
  cin >> s;

  // input

  for (int i = 0; i < e; i++)
  {
    string u, v;
    cin >> u >> v;
    int x;
    cin >> x;
    adj_list[u][v] = x;
    vertices.insert(u);
    vertices.insert(v);
  }

  path.push_back(s);
  explored.insert(s);
  vertices.erase(s);
  dist[s] = 0;
  attempt(0);
  for (auto vertex : best_path)
  {
    std::cout << vertex << " ";
  }
  return 0;
}