#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    map<string, map<string, int>> adj_list;

public:
    Graph(int e);
    void myProcess(int n);
};
Graph::Graph(int e)
{
    string u, i;
    int x;
    while (e--)
    {
        cin >> u >> i >> x;
        adj_list[u][i] = x;
    }
}

void Graph::myProcess(int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<string> route;
        string cur, next;
        cin >> cur;
        route.push_back(cur);
        bool flag = true;
        int d = 0;
        while (cin >> next && next != ".")
        {
            if (adj_list[cur].find(next) != adj_list[cur].end())
            {
                d += adj_list[cur][next];
            }
            else
            {
                flag = false;
            }
            cur = next;
            route.push_back(cur);
        }
        if (*route.begin() != *(route.end() - 1))
            flag = false;
        if (flag)
            cout << d << endl;
        else
            cout << "FALSE" << endl;
    }
}

int main()
{
    int e, n;
    cin >> e >> n;
    Graph G(e);
    G.myProcess(n);

    return 0;
}