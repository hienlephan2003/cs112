INF = float('inf')
def floyd_warshall(n, graph):
    distances = [[INF] * (n + 1) for _ in range(n + 1)]

    # Khởi tạo khoảng cách ban đầu
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i == j:
                distances[i][j] = 0
            elif j in graph[i]:
                distances[i][j] = 1

    # Cập nhật khoảng cách
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j])

    return distances

# Đọc input
n, q = map(int, input().split())
graph = [[] for _ in range(n + 1)]

# Xây dựng đồ thị từ thông tin đường đi
for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# Tính toán khoảng cách ngắn nhất
distances = floyd_warshall(n, graph)

# Giải các truy vấn
for _ in range(q):
    a, b = map(int, input().split())
    distance = distances[a][b]
    print(distance)

# Reference: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/