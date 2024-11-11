import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
MOD = 10**9+7

N = int(input())
XY = [tuple(map(int,input().split())) for i in range(N-1)]
es = [[] for _ in range(N)]
for x,y in XY:
    x,y = x-1,y-1
    es[x].append(y)
    es[y].append(x)

dp = [[1,1] for i in range(N)]
def rec(v,p=-1):
    for to in es[v]:
        if to==p: continue
        rec(to,v)
        dp[v][0] *= (dp[to][0] + dp[to][1])
        dp[v][1] *= dp[to][0]
        dp[v][0] %= MOD
        dp[v][1] %= MOD
rec(0)

print(sum(dp[0]) % MOD)