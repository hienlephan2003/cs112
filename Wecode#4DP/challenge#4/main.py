MOD = int(1e9 + 7)

def count_safe_paths(n, grid):
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    
    # Khởi tạo giá trị ban đầu
    dp[1][1] = 1 if grid[0][0] == '.' else 0
    
    # Tính giá trị dp[i][1]
    for i in range(2, n + 1):
        if grid[i-1][0] == '*':
            break
        dp[i][1] = 1
    
    # Tính giá trị dp[1][j]
    for j in range(2, n + 1):
        if grid[0][j-1] == '*':
            break
        dp[1][j] = 1
    
    # Tính giá trị dp[i][j] sử dụng công thức đệ quy
    for i in range(2, n + 1):
        for j in range(2, n + 1):
            if grid[i-1][j-1] == '.':
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD
    
    return dp[n][n]

# Đọc input
n = int(input())
grid = []
for _ in range(n):
    row = input()
    grid.append(row)

# Gọi hàm và in kết quả
result = count_safe_paths(n, grid)
print(result)
