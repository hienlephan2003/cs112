#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
map<string, set<string>> adj_list;
map<string, int> colors;
set<int> colors_;
vector<string> vertices;

void colorVertex(string v)
{
  int color0 = colors[v];
  int count = 0;
  set<int> filled;
  // check each the adjacent vertex has the same color or not
  for (auto next : adj_list[v])
  {
    int color1 = colors[next];
    if (color1 != -1)
    {
      filled.insert(color1);
      if (color0 == color1)
      {
        count++;
      }
    }
  }
  if (count == 0 && color0 != -1)
  {
    std::cout << "TRUE" << endl;
  }
  else
  {
    for (auto color : colors_)
    {
      if (filled.find(color) == filled.end())
      {
        std::cout << color << endl;
        return;
      }
    }

    int fill = 0;
    // while color fill is in filled colors list fill++
    while (filled.find(fill) != filled.end())
    {
      fill++;
    }
    std::cout << fill << endl;
  }
}
int main()
{

  int v, e, n;
  std::cin >> v >> e >> n;

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
  for (int i = 0; i < v; i++)
  {
    int color;
    cin >> color;
    colors[vertices[i]] = color;
    if (color != -1)
      colors_.insert(color);
  }
  for (int i = 0; i < n; i++)
  {
    cin >> vertex;
    colorVertex(vertex);
  }

  return 0;
}