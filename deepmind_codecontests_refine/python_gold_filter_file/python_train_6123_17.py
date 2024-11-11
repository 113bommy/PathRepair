import sys
sys.setrecursionlimit(100000)
n = int(input())
G = [[] for i in range(n)]
for i in range(n-1):
    x, y = map(int, input().split())
    G[x-1].append(y-1)
    G[y-1].append(x-1)
p = 10**9+7
Q = [0]
V = [False for i in range(n)]
C = [[] for i in range(n)]
while Q:
    x = Q.pop()
    V[x] = True
    for y in G[x]:
        if not V[y]:
            C[x].append(y)
            Q.append(y)
DP = [[None, None] for i in range(n)]
def dp(i, c):
    if DP[i][c] != None:
        return DP[i][c]
    tmp = 1
    for j in C[i]:
        if c == 0:
            tmp = (tmp*(dp(j, 0)+dp(j, 1))) % p
        else:
            tmp = (tmp*dp(j, 0)) % p
    DP[i][c] = tmp
    return DP[i][c]
print((dp(0, 0)+dp(0, 1))%p)
