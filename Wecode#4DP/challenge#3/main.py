def combinationSum(s):
    MOD = 10 ** 9 + 7
    dp = [0] * (s + 1)
    dp[0] = 1

    for i in range(1, s+1):
        for j in range(1, 7):
            if i - j >= 0:
                dp[i] = (dp[i] + dp[i - j]) % MOD
    return dp[s] % MOD


s = int(input())
print(combinationSum(s))

'''
1 2 3 4  5   6   7   
1 2 4 8 16  32  63

'''
