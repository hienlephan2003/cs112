#include <iostream>
#include <vector>

long long dfs(std::vector<std::vector<long long>> &graph, long long start, long long end, std::vector<bool> &visited)
{
    if (start == end)
    {
        return 0;
    }
    visited[start] = true;
    for (long long neighbor : graph[start])
    {
        std::cout << neighbor << std::endl;
        if (!visited[neighbor])
        {
            long long distance = dfs(graph, neighbor, end, visited);
            if (distance >= 0)
            {
                return distance + 1;
            }
        }
    }
    return -1;
}

int main()
{
    long long n, q;
    std::cin >> n >> q;
    std::vector<std::vector<long long>> graph(n + 1);
    std::vector<bool> visited(n + 1, false);

    for (long long i = 0; i < n - 1; i++)
    {
        long long a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (long long i = 0; i < q; i++)
    {
        long long a, b;
        std::cin >> a >> b;
        long long distance = dfs(graph, a, b, visited);
        std::cout << distance << std::endl;
    }

    return 0;
}
