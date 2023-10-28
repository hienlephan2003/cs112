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
// bool isComplete(vector<string> &path)
// {
//     string cur = path[0];
//     for (int i = 1; i < path.size(); i++)
//     {
//         if (adj_list[cur].find(path[i]) == adj_list[cur].end())
//         {
//             return false;
//         }
//         cur = path[i];
//     }
//     if (cur != path[0])
//     {
//         return false;
//     }
//     return true;
// }
int main()
{
    int e;
    string s;
    cin >> e;
    cin >> s;

    // input
    set<string> vertices;
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

    // process
    vector<string> path;
    set<string> explored;
    path.push_back(s);
    string cur = s;
    for (int i = 0; i < vertices.size() - 1; i++)
    {
        int min_route = 100000;
        for (auto next : adj_list[cur])
        {
            if (explored.find(next.first) != explored.end() || next.first == s)
                continue;
            if (next.second < min_route)
            {
                min_route = next.second;
                cur = next.first;
            }
        }
        explored.insert(cur);
        path.push_back(cur);
    }
    path.push_back(s);

    // output
    for (auto vertex : path)
    {
        std::cout << vertex << " ";
    }

    return 0;
}