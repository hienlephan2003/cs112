def unique_combination_sums(arr):
    results = []

    # Hàm quay lui để tạo các tổ hợp
    def backtrack(path, start, subset_sum):
        if subset_sum not in results:
            results.append(subset_sum)

        for i in range(start, len(arr)):
            path.append(arr[i])
            subset_sum += arr[i]
            backtrack(path, i + 1, subset_sum)
            path.pop()
            subset_sum -= arr[i]

    # Sắp xếp mảng đầu vào để loại bỏ các tổ hợp trùng nhau
    arr.sort()

    # Gọi hàm quay lui ban đầu
    backtrack([], 0, 0)

    return results


# Test
n = int(input())
lengths = list(map(int, input().split()))
combination_sums = unique_combination_sums(arr)
print("Tổng các tổ hợp không trùng nhau là:")
print(*combination_sums)
