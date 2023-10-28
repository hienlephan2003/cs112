#include <iostream>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;
int m, n;
pair<int, int> base;
pair<int, int> goal;
int hor[8] = {+0, +0, -1, -1, +1, -1, +1, +1};
int ver[8] = {+1, -1, +1, -1, +0, +0, -1, +1};
class Graph
{
private:
  vector<vector<int>> matrix;
  map<string, int> mapping;
  map<int, string> rMap;

  int v;

public:
  Graph();
  void input(int v);
  void inputMap();
  void BFS_map(pair<int, int> &, pair<int, int> &);
  void myProcess(int n);
  void AStar(pair<int, int> &, pair<int, int> &);
};

Graph::Graph() {}

int main()
{
  std::cin >> m >> n;
  std::cin >> base.first >> base.second;
  std::cin >> goal.first >> goal.second;
  base.first = m - base.first - 1;
  goal.first = m - goal.first - 1;
  Graph G;
  G.inputMap();
  // G.BFS_map(base, goal);
  G.AStar(base, goal);

  return 0;
}

int heuristic(int x, int y)
{
  // Manhattan distance heuristic
  // return abs(x - goal.first) + abs(y - goal.second);

  // Pythagoras
  return int(sqrt(pow(x - goal.first, 2) + pow(y - goal.second, 2))) / 5;
}
void Graph::inputMap()
{
  matrix = vector<vector<int>>(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
}

void Graph::BFS_map(pair<int, int> &base, pair<int, int> &goal)
{
  // Create a queue to store the nodes that are waiting to be explored
  queue<pair<int, int>> frontier;
  frontier.push(base);

  // Create a set to store the nodes that have been expanded
  set<pair<int, int>> explored;
  // Create a map to store the parent nodes and distance from the base node
  map<pair<int, int>, pair<int, int>> parent;
  map<pair<int, int>, int> distance;
  bool goalFound = false;
  distance[base] = 0;

  while (!frontier.empty())
  {
    // Pop the front node from the queue
    pair<int, int> current = frontier.front();
    frontier.pop();

    // If the current node was expanded then we need to iterate the next node
    if (explored.find(current) != explored.end())
      continue;
    // Mark the current node as explore
    explored.insert(current);

    // Check if the current node was the goal node
    if (current == goal)
    {
      goalFound = true;
      break;
    }
    for (int i = 0; i < 8; i++)
    {
      // calculate the distance between the current node and the next node
      int next_x = current.first + hor[i];
      int next_y = current.second + ver[i];
      if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || matrix[next_x][next_y] == 1)
        continue;

      pair<int, int> nextNode = make_pair(next_x, next_y);
      frontier.push(nextNode);
      // if the next node is not expanded then we need to add it to frontier list
      if (explored.find(nextNode) == explored.end() && parent[nextNode] == make_pair(0, 0))
      {
        parent[nextNode] = current;
        // update the distance between the current node and the next
        distance[nextNode] = distance[current] + 1;
      }
    }
  }
  if (goalFound)
  {
    std::cout << distance[goal] << endl;
  }
  else
  {
    std::cout << -1 << endl;
  }
}

void Graph::AStar(pair<int, int> &base, pair<int, int> &goal)
{
  auto cmp = [&](std::pair<std::pair<int, int>, int> a, std::pair<std::pair<int, int>, int> b) -> bool
  {
    return a.second > b.second;
  };

  // Create a queue to store the nodes that are waiting to be explore
  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(cmp)> frontier(cmp);

  frontier.push(make_pair(base, heuristic(base.first, base.second)));

  // Create a set to store the nodes that have been expanded
  set<pair<int, int>> explored;
  // Create a map to store the parent nodes and distance from the base node
  map<pair<int, int>, pair<int, int>> parent;
  map<pair<int, int>, int> distance;
  bool goalFound = false;
  distance[base] = 0;

  while (!frontier.empty())
  {
    pair<pair<int, int>, int> current = frontier.top();
    frontier.pop();

    pair<int, int> current_node = current.first;
    int current_dist = current.second;

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

    for (int i = 0; i < 8; i++)
    {
      int next_x = current_node.first + hor[i];
      int next_y = current_node.second + ver[i];
      if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || matrix[next_x][next_y] == 1)
        continue;

      pair<int, int> next_node = make_pair(next_x, next_y);

      // calculate the new distance to the next node
      int new_distance = distance[current_node] + 1;

      if (distance.count(next_node) == 0 || new_distance < distance[next_node])
      {
        if (explored.count(next_node) > 0)
          explored.erase(next_node);
        distance[next_node] = new_distance;

        // calculate the new f = g + h (priority) to the next node
        int priority = new_distance + heuristic(next_node.first, next_node.second);
        frontier.push(make_pair(next_node, priority));
        parent[next_node] = current_node;
      }
    }
  }
  if (goalFound)
    std::cout << distance[goal] << endl;
  else
    std::cout << -1 << endl;
}
