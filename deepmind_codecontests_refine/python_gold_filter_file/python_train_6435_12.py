mod = 10**9 + 7

K = list(map(int, list(input())))
D = int(input())
keta = len(K)

dp = [[[0]*D for i in range(2)] for j in range(keta+1)]
dp[0][1][0] = 1

from itertools import product
for i, j, k in product(range(keta), range(2), range(D)):
    max_n = K[i] if j else 9
    for l in range(max_n+1):
        dp[i+1][j and l == max_n][(k+l)%D] += dp[i][j][k]
        dp[i+1][j and l == max_n][(k+l)%D] %= mod

ans = 0
for i in range(2):
    ans += dp[-1][i][0]
    ans %= mod
print(max(0, (ans - 1)%mod))