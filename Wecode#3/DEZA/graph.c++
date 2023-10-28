#include <iostream>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>

using namespace std;

// // Khai báo struct Node đại diện cho các phần tử trong hàng đợi ưu tiên
// struct Node
// {
//     string value;
//     int priority;
//     Node(string v, int p) : value(v), priority(p) {}
// };

// // Định nghĩa toán tử so sánh (<) để set biết cách sắp xếp các phần tử
// bool operator<(const Node &a, const Node &b)
// {
//     return a.priority < b.priority; // So sánh theo ưu tiên tăng dần
// }

class Graph
{
private:
    map<string, set<string>> adj_list;

public:
    Graph(int e);
    void myProcess(int n);
    void BFS(string);
    void DFS(string);
    void Dijkstra(string);
};
Graph::Graph(int e)
{
    string u, i;
    while (e--)
    {
        cin >> u >> i;
        // Lưu thông tin đỉnh và cạnh trong danh sách kề
        // adj_list[u]; // thêm 1 ánh xạ đi từ (x) -> {rỗng}, xem như có 1 đỉnh mới là x được thêm vào ds kề.
        adj_list[i].insert(u);

        // i là kề của u, bỏ i vào tập các đỉnh kề của u
        // truy cập vào đầu ra của ax đi từ x, tức là trả về {}, hàm insert để thêm phần từ vào tập hợp
        adj_list[u].insert(i);
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
            set<string>::iterator it;
            it = adj_list[u].find(i);
            if (it != adj_list[u].end())
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;
        }
        else if (test == 2)
        {
            cin >> u;
            int counter = adj_list[u].size();
            cout << counter << endl;
        }
    }
}
void Graph::BFS(string base)
{
    queue<string> open;
    open.push(base);
    set<string> closed;
    closed.insert(base);
    while (!open.empty())
    {
        string v = open.front(); // lấy đỉnh ở đầu hàng đợi
        open.pop();
        cout << v << " --> ";
        for (auto it : adj_list[v])
        {
            if (closed.find(it) == closed.end())
            {
                closed.insert(it);
                open.push(it);
            }
        }
    }
}void Graph::DFS(string base)
{
    stack<string> open;
    open.push(base);
    set<string> visited;
    visited.insert(base);
    while (!open.empty())
    {
        string v = open.top();
        open.pop();
        cout << v << " --> ";
        for (string it : adj_list[v])
        {
            if (visited.find(it) == visited.end())
            {
                visited.insert(it);
                open.push(it);
            }
        }
    }
}
void Graph::Dijkstra(string base)
{
    priority_queue<string , vector<string> , greater<int>> open;
    open.push(base);
    set<string> visited;
    visited.insert(base);
    while (!open.empty())
    {
        string v = open.top();
        open.pop();
        cout << v << " --> ";
        for (string it : adj_list[v])
        {
            if (visited.find(it) == visited.end())
            {
                visited.insert(it);
                open.push(it);
            }
        }
    }
}

int main()
{
    /*
        int e, n;
        cin >> e >> n;
        Graph G(e);
        G.myProcess(n);
     */
    int e;
    cin >> e;
    Graph G(e);
    string v;
    cin >> v;
    G.BFS(v);
    cout << endl;
    G.DFS(v);
    return 0;
}