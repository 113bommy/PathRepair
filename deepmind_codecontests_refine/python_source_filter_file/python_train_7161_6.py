import sys
readline = sys.stdin.readline
sys.setrecursionlimit(10**8)
mod = 10**9+7
#mod = 998244353
INF = 10**18
eps = 10**-7

# 01ナップサック問題
N,W = map(int,readline().split())
AB = [list(map(int,readline().split())) for i in range(N)]
AB.sort(key=lambda x: (x[1],x[0]))
dp = [0]*(W+1)

for (w,v) in AB:
    dpnew = dp[::]
    for j in range(W):
        dpnew[min(j+w,W)] = max(dp[min(j+w,W)],dp[j] + v)
    dp = dpnew

print(max(dp))
