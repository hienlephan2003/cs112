
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


int v, e;
class Graph
{
private:
    vector<vector<int>> matrix;
    map<string, int> mapping;
    map<int, string> rMap;

public:
    Graph();
    void nhap(int v, int e);
    void myProcess();
};
Graph::Graph()
{
    matrix = vector<vector<int>>(0, vector<int>(0, 0));
}
void Graph::nhap(int v, int e)
{
    matrix = vector<vector<int>>(v, vector<int>(v, 0));
    int j = 0;
    while (v--)
    {
        string temp;
        cin >> temp;
        mapping[temp] = j;
        rMap[j] = temp;
        j++;
    }
    string u, i;
    while (e--)
    {
        cin >> u >> i;
        matrix[mapping[u]][mapping[i]] = 1;
        matrix[mapping[i]][mapping[u]] = 1;
    }
}
void Graph::myProcess()
{
    for (int j = 0; j < v; j++)
    {
        int degree = 0;
        for (int k = 0; k < matrix.size(); k++)
        {
            if (matrix[j][k] != 0)
            {
                degree++;
            }
        }
        cout << degree << " ";
    }
}
int main()
{
    Graph G;

    cin >> v >> e;
    G.nhap(v, e);
    G.myProcess();
    return 0;
}