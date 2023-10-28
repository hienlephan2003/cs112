#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define UNCOLORED -1
using namespace std;
map<string, set<string>> adj_list;
map<string, int> colors;
vector<string> vertices;

int minColors = (2 << 23);
vector<int> best_colors;
vector<int> usedColors;

void attempt(int i)
{
  if (set<int>(usedColors.begin(), usedColors.end()).size() >= minColors)
  {
    return; // Prune early
  }
  if (i == vertices.size())
  {
    // check if the number of colors is smallest
    int num_of_used_colors = set<int>(usedColors.begin(), usedColors.end()).size();
    if (num_of_used_colors < minColors)
    {
      best_colors.clear();
      for (const auto &vertex : vertices)
        best_colors.push_back(colors[vertex]);
      minColors = num_of_used_colors;
    }
    return;
  }
  set<int> removed_colors;
  for (const auto &adjVertex : adj_list[vertices[i]])
  {
    int adjColor = colors[adjVertex];

    if (adjColor != UNCOLORED)
    {
      removed_colors.insert(adjColor);
    }
  }

  for (int _color = 0; _color < vertices.size(); _color++)
  {
    colors[vertices[i]] = _color;
    if (removed_colors.find(_color) == removed_colors.end())
    {
      usedColors.push_back(_color);
      attempt(i + 1);
      usedColors.pop_back();
    }
    colors[vertices[i]] = UNCOLORED;
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
    colors[vertex] = UNCOLORED;
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
  attempt(0);
  for (auto color : best_colors)
    cout << color << " ";

  return 0;
}