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
    map<string, set<string>> adj_list;
    set<string> vertices;

public:
    Graph(int e);
    bool myProcess();
};
Graph::Graph(int e)
{
    string u, i;
    while (e--)
    {
        cin >> u >> i;
        adj_list[u];
        adj_list[u].insert(i);
        vertices.insert(u);
        vertices.insert(i);
    }
}
bool Graph::myProcess()
{
    int numberOfVertices = vertices.size() - 1;
    for (string v : vertices)
    {
        if (adj_list[v].size() != numberOfVertices)
            return false;
    }
    return true;
}

int main()
{
    int e;
    cin >> e;
    Graph G(e);
    cout << ((G.myProcess()) ? "TRUE" : "FALSE") << endl;
    return 0;
}