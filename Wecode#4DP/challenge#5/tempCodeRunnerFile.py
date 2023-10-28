def max_credits(n, projects):
    projects.sort(key=lambda x: x[1])  # Sắp xếp các đồ án theo thứ tự tăng dần của ngày kết thúc
    # print(projects)
    dp = [0] * n  # Khởi tạo mảng dp
    dp[0] = projects[0][2]  # Số tín chỉ lớn nhất có thể đạt được tại ngày kết thúc của đồ án đầu tiên
    for i in range(1, n):
        prev = -1
        for j in range(i - 1, -1, -1):
            if projects[i][0] > projects[j][1]:
                prev = j
                break
        if prev == -1:
            dp[i] = max(dp[i - 1], projects[i][2])
        else:
            dp[i] = max(dp[i - 1], dp[prev] + projects[i][2])  # Cập nhật giá trị dp[i]
    return dp[n - 1]  # Trả về số lượng tín chỉ lớn nhất có thể nhận được


# Đọc input
n = int(input())
projects = []
for _ in range(n):
    a, b, p = map(int, input().split())
    projects.append((a, b, p))

# Gọi hàm max_credits và in kết quả
print(max_credits(n, projects))

'''
4
2 4 4
3 6 6
6 8 2
5 7 3	

7
'''