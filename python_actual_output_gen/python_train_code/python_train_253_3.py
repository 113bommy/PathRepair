import sys
sys.setrecursionlimit(2147483647)
INF = float("inf")
MOD = 10**9 + 7 # 998244353
input = lambda:sys.stdin.readline().rstrip()
def resolve():
    n, k = map(int, input().split())
    dp = [0] * (k + 1)
    dp[0] = 1
    for a in map(int, input().split()):
        # accumulate dp
        S = [0] * (k + 2)
        for i in range(k + 1):
            S[i + 1] = S[i] + dp[i]
            if S[i + 1] >= MOD:
                S[i + 1] -= MOD
        # ndp[i] = dp[i - a] + ... + dp[i]
        dp = [S[i + 1] - S[max(0, i - a)] for i in range(k + 1)]

    print(dp[k])
resolve()