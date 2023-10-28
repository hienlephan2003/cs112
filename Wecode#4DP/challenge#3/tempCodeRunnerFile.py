def combinationSum(s):
    MOD = 10 ** 9 + 7
    dp = [0] * (s + 1)
    dp[0] = 1

    if s >= 7:
        dp[s] = (2 ** (s - 1) - 1) % MOD
    else:
        dp[s] = (2 ** (s - 1)) % MOD

    return dp[s] % MOD


s = int(input())
print(combinationSum(s))

'''
1 2 3 4  5   6   7   
1 2 4 8 16  32  63

'''
