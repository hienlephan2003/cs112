
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

public:
    Graph(int e);
    void myProcess(int n);
};
Graph::Graph(int e)
{
    string u, i;
    while (e--)
    {
        cin >> u >> i;
        // Lưu thông tin đỉnh và cạnh trong danh sách kề
        adj_list[u]; // thêm 1 ánh xạ đi từ (x) -> {rỗng}, xem như có 1 đỉnh mới là x được thêm vào ds kề.
        // adj_list[i].insert(u);
        // i là kề của u, bỏ i vào tập các đỉnh kề của u
        adj_list[u].insert(i); // truy cập vào đầu ra của ax đi từ x, tức là trả về {}, hàm insert để thêm phần từ vào tập hợp
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

int main()
{
    int e, n;
    cin >> e >> n;
    Graph G(e);
    G.myProcess(n);

    return 0;
}
