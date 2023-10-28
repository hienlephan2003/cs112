/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// ###INSERT CODE HERE -
class Graph
{
private:
    vector<vector<int>> matrix;
    map<string, int> mapping;
    map<int, string> rMap;

public:
    Graph();
    void nhap(int v, int e);
    void myProcess(int n);
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
    }
}
void Graph::myProcess(int n)
{
    int test;
    string u, i;
    while (n--)
    {
        cin >> test;
        if (test == 1)
        {
            cin >> u >> i;
            if (matrix[mapping[u]][mapping[i]] != 0)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;
        }
        else if (test == 2)
        {
            bool flag = false;
            cin >> u;
            for (int j = 0; j < matrix.size(); j++)
            {
                if (matrix[mapping[u]][j] != 0)
                {
                    cout << rMap[j] << " ";
                    flag = true;
                }
            }
            cout << endl;
            if (!flag)
                cout << "NONE" << endl;
        }
    }
}
int main()
{
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}
