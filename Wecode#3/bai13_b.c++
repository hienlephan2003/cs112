#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

const int MAX_SIZE = 5000;
const int INF = INT_MAX;

struct Node
{
  int x, y; // Coordinates
  int g;    // Cost from start node
  int h;    // Heuristic (estimated cost to goal)
  int f;    // f = g + h

  Node(int x, int y, int g, int h) : x(x), y(y), g(g), h(h), f(g + h) {}
};

// Custom comparator for priority queue
struct NodeComparator
{
  bool operator()(const Node &a, const Node &b)
  {
    return a.f > b.f; // Smaller f-value has higher priority
  }
};

int m, n;                // Size of the map
pair<int, int> start;    // Starting position
pair<int, int> goal;     // Goal position
vector<vector<int>> map; // Map representation

int heuristic(int x, int y)
{
  // Manhattan distance heuristic
  return abs(x - goal.first) + abs(y - goal.second);
}

bool isValid(int x, int y)
{
  // Check if the given coordinates are within the valid range and the cell is traversable
  return (x >= 0 && x < m && y >= 0 && y < n && map[x][y] == 0);
}

int AStar()
{
  // Create a priority queue to store the nodes to be explored
  priority_queue<Node, vector<Node>, NodeComparator> frontier;

  // Create a 2D array to store the cost from start node
  vector<vector<int>> cost(m, vector<int>(n, INF));

  // Add the start node to the frontier
  frontier.push(Node(start.first, start.second, 0, heuristic(start.first, start.second)));
  cost[start.first][start.second] = 0;

  // Possible directions: right, left, down, up, diagonal
  int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
  int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

  while (!frontier.empty())
  {
    // Get the node with the minimum f-value from the priority queue
    Node current = frontier.top();
    frontier.pop();

    // Check if the current node is the goal
    if (current.x == goal.first && current.y == goal.second)
    {
      return current.g;
    }

    // Explore the neighbors of the current node
    for (int i = 0; i < 8; i++)
    {
      int nx = current.x + dx[i];
      int ny = current.y + dy[i];

      // Check if the neighbor is valid
      if (isValid(nx, ny))
      {
        int ng = current.g + 1; // Cost from start to neighbor (always 1 in this case)

        // Update the cost if the new path is shorter
        if (ng < cost[nx][ny])
        {
          cost[nx][ny] = ng;
          int nh = heuristic(nx, ny);
          int nf = ng + nh;
          frontier.push(Node(nx, ny, ng, nh));
        }
      }
    }
  }

  // The goal is unreachable
  return -1;
}

int main()
{
  // Read input
  cin >> m >> n;
  cin >> start.first >> start.second;
  cin >> goal.first >> goal.second;

  // Adjust coordinates
  start.first = m - start.first - 1;
  goal.first = m - goal.first - 1;

  // Read map
  map.resize(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }

  // Run A* algorithm
  int result = AStar();

  // Output the result
  cout << result << endl;

  return 0;
}
