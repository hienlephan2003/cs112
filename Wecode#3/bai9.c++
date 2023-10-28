#include <iostream>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

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
    void DFS(string, string);
    void myProcess(int n);
};
Graph::Graph()
{
    matrix = vector<vector<int>>(0, vector<int>(0, 0));
}
void Graph::input(int v)
{
    this->v = v;
    matrix = vector<vector<int>>(v, vector<int>(v, 0));
    int j = 0;
    for (int i = 0; i < v; i++)
    {
        string temp;
        cin >> temp;
        mapping[temp] = j;
        rMap[j] = temp;
        j++;
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
void Graph::myProcess(int n)
{
    while (n--)
    {
        string u, i;
        cin >> u >> i;
        DFS(u, i);
    }
}
// this function is used to implement DFS search algorithm
void Graph::DFS(string base, string goal)
{
    // Create a stack to store the nodes that are waiting to be explored
    stack<string> frontier;
    frontier.push(base);

    // Create a set to store the nodes that have been visited but not yet expanded
    set<string> explored;
    // Create a map to store the parent nodes and distance from the base node
    map<string, string> parent;
    map<string, int> distance;
    bool goalFound = false;
    distance[base] = 0;
    int pass = 0;

    while (!frontier.empty())
    {
        // Pop the first node from the stack
        string current = frontier.top();
        frontier.pop();
        // Check if the current node was the goal node
        // If the current node was expanded then we need to iterate the next node
        if (explored.find(current) == explored.end())
        {
            pass++;
            // Mark the current node as explore
            explored.insert(current);
            if (current == goal)
            {
                goalFound = true;
                break;
            }
            for (int i = 0; i < this->v; i++)
            {
                // calculate the distance between the current node and the next node
                int weight = matrix[mapping[current]][i];
                // if the distance is greater than 0
                if (weight != 0)
                {
                    string nextNode = rMap[i];
                    frontier.push(nextNode);
                    // if the next node is not expanded then we need to add it to frontier list
                    if (explored.find(nextNode) == explored.end())
                    {
                        // update the relationship between the current node and the next
                        parent[nextNode] = current;

                        // update the distance between the current node and the next
                        distance[nextNode] = distance[current] + weight;
                    }
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
    int v, n;
    Graph G;
    cin >> v >> n;
    G.input(v);
    G.myProcess(n);
    return 0;
}