#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

const int INF = 1e6;

std::vector<std::vector<int>> floyd_warshall(int n, std::vector<std::vector<int>> &graph)
{
    std::vector<std::vector<int>> distances(n + 1, std::vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                distances[i][j] = 0;
            }
            else if (std::find(graph[i].begin(), graph[i].end(), j) != graph[i].end())
            {
                distances[i][j] = 1;
            }
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                distances[i][j] = std::min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    return distances;
}

int main()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<std::vector<int>> distances = floyd_warshall(n, graph);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        std::cin >> a >> b;
        int distance = distances[a][b];
        std::cout << distance << std::endl;
    }

    return 0;
}
// Reference: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/