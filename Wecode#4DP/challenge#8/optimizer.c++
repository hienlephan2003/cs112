#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const unsigned short INF = 60000;

std::vector<std::vector<unsigned short>> floyd_warshall(unsigned short n, std::vector<std::vector<unsigned short>> &graph)
{
    std::vector<std::vector<unsigned short>> distances(n + 1, std::vector<unsigned short>(n + 1, INF));

    for (unsigned short i = 1; i <= n; i++)
    {
        distances[i][i] = 0;
        for (unsigned short j : graph[i])
        {
            distances[i][j] = 1;
        }
    }

    for (unsigned short k = 1; k <= n; k++)
    {
        for (unsigned short i = 1; i <= n; i++)
        {
            for (unsigned short j = 1; j <= n; j++)
            {
                distances[i][j] = std::min(distances[i][j], unsigned short(distances[i][k] + distances[k][j]));
            }
        }
    }

    return distances;
}

int main()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<unsigned short>> graph(n + 1);

    for (unsigned short i = 0; i < n - 1; i++)
    {
        unsigned short a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<std::vector<unsigned short>> distances = floyd_warshall(n, graph);

    for (unsigned short i = 0; i < q; i++)
    {
        unsigned short a, b;
        std::cin >> a >> b;
        unsigned short distance = distances[a][b];
        std::cout << distance << std::endl;
    }

    return 0;
}
