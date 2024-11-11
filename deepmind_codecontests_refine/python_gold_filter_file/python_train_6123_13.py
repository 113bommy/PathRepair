from collections import deque
import sys
sys.setrecursionlimit(10**6)

N = int(input())
E = [[] for _ in range(N)]
for _ in range(N-1):
    x,y = map(int, input().split())
    E[x-1].append(y-1)
    E[y-1].append(x-1)
    
parents = [-1]*N
q = deque()
q.append(0)
while q:
    t = q.popleft()
    for i in E[t]:
        if i == parents[t]:
            continue
        q.append(i)
        parents[i] = t
        
mod = 10**9+7
dp = [[1]*2 for _ in range(N)]
flag = [0]*N

def f(v, j):
    if flag[v]:
        return dp[v][j]
    flag[v] = 1
    for i in E[v]:
        if i == parents[v]:
            continue
        dp[v][0] *= (f(i, 0) + f(i, 1))
        dp[v][1] *= f(i, 0)
        dp[v][0] %= mod
        dp[v][1] %= mod
    return dp[v][j]

print((f(0, 0)+f(0, 1))%mod)