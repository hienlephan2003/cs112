#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

void findPath(vector<vector<int>> G, vector<int> estimate, vector<string> vertice, map<string, int> mapping, string s, string u, int v)
{
  map<string, string> parent;
  vector<vector<int>> f_g(2, vector<int>(v, 0)); // 1st row is f value, 2nd is g value
  vector<int> close(v, 0), open(v, 0);
  int check = 0, count_open = 0, count_close = 0;
  open[mapping[s]] = 1;
  count_open++;
  f_g[0][mapping[s]] = estimate[mapping[s]];
  while (count_open != 0)
  {
    int min = -1;
    for (int i = 0; i < v; i++)
    {
      if (open[i] == 1 && (min == -1 || f_g[0][min] > f_g[0][i]))
        min = i;
    }
    open[min] = 0;
    count_open--;
    close[min] = 1;
    count_close++;
    if (vertice[min] == u)
    {
      check = 1;
      break;
    }
    for (int i = 0; i < v; i++)
    {
      if (G[min][i] > 0)
      {
        if (open[i] == 0 && close[i] == 0)
        {
          f_g[1][i] = f_g[1][min] + G[min][i];
          f_g[0][i] = f_g[1][i] + estimate[i];
          parent[vertice[i]] = vertice[min];
          open[i] = 1;
          count_open++;
        }
        else
        {
          if (f_g[1][i] > f_g[1][min] + G[min][i])
          {
            f_g[1][i] = f_g[1][min] + G[min][i];
            f_g[0][i] = f_g[1][i] + estimate[i];
            parent[vertice[i]] = vertice[min];
            if (close[i] == 1)
            {
              close[i] = 0;
              count_close--;
              open[i] = 1;
              count_open++;
            }
          }
        }
      }
    }
  }
  vector<string> path;
  if (check == 0)
    cout << "-unreachable-\n";
  else
  {
    string p = u;
    path.push_back(p);
    while (parent[p] != "")
    {
      path.push_back(parent[p]);
      p = path.back();
    }
    for (int t = path.size() - 1; t >= 0; t--)
    {
      cout << path[t] << " ";
    }
    cout << "\n";
  }
  cout << count_close << " " << f_g[1][mapping[u]];
}

int main()
{
  int v, e, w;
  string s, u, x, y;
  cin >> v >> e;
  vector<vector<int>> G(v, vector<int>(v, 0));
  vector<int> estimate(v);
  vector<string> vertice(v);
  map<string, int> mapping;
  cin >> s >> u;
  for (int i = 0; i < v; i++)
  {
    cin >> vertice[i];
    mapping[vertice[i]] = i;
  }
  for (int i = 0; i < v; i++)
  {
    cin >> estimate[i];
  }
  for (int i = 0; i < e; i++)
  {
    cin >> x >> y >> w;
    G[mapping[x]][mapping[y]] = w;
  }
  findPath(G, estimate, vertice, mapping, s, u, v);
  return 0;
}