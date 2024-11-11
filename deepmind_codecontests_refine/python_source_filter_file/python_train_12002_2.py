import sys

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for k in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for k in range(c)] for k in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10**19
MOD = 10**9 + 7
EPS = 10**-10

N, M, K = MAP()

dp = list3d(M+1, M//2+1, K, -1)
nxt = [0] * K
dp[0][0][0] = 0
for i in range(N):
    row = LIST()

    for j in range(M):
        for k in range(M//2+1):
            for l in range(K):
                if dp[j][k][l] != -1:
                    dp[j+1][k][l] = max(dp[j+1][k][l], dp[j][k][l])
                    if k+1 <= M//2:
                        dp[j+1][k+1][(l+row[j])%K] = max(dp[j+1][k+1][(l+row[j])%K], dp[j][k][l] + row[j])
    
    for k in range(M//2+1):
        for l in range(K):
            nxt[l] = max(nxt[l], dp[M][k][l])
    dp = list3d(M+1, M//2+1, K, -1)
    dp[0][0] = nxt
    nxt = [0] * K

ans = dp[0][0][0]
print(ans)
