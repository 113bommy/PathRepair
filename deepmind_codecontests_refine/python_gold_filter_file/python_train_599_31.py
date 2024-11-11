import sys
def input(): return sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 7)
MOD = 998244353

N, S = map(int, input().split())
A = list(map(int, list(input().split())))

ans = 0
dp = [[0]*(S+1) for _ in range(N+1)]
for i in range(N):
    dp[i][0] += 1       # Lがiからを足す
    for j in range(S+1):
        dp[i+1][j] += dp[i][j]             # A[i]を選ばない
        dp[i+1][j] %= MOD
        if j+A[i]<=S:
            dp[i+1][j+A[i]] += dp[i][j]    # A[i]を選ぶ
            dp[i+1][j+A[i]] %= MOD
    ans += dp[i+1][S]    # Rがiまでを足す
    ans %= MOD

print(ans)