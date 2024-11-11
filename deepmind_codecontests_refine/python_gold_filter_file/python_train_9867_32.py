import sys

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')

def solve():
    mod = 998244353
    a, b, c, d = nm()
    n, m = c-a, d-b
    dp = [[0]*(m+1) for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(n):
        dp[i+1][0] = dp[i][0] * b % mod
    for i in range(m):
        dp[0][i+1] = dp[0][i] * a % mod
    for i in range(1, n+1):
        for j in range(1, m+1):
            dp[i][j] = (dp[i][j-1] * (a + i) + dp[i-1][j] * (b + j) - dp[i-1][j-1] * (a + i - 1) * (b + j - 1)) % mod
    # if a < 10:
    #     prn(dp)
    print(dp[n][m])

    return

solve()
