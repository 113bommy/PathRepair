from bisect import bisect_right
from sys import setrecursionlimit

setrecursionlimit(10**8)
n = int(input())
A = list(map(int, input().split()))
gr = []
for i in range(n):
    gr.append([])
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    gr[a].append(b)
    gr[b].append(a)
ans = [0] * n
dp = [10 ** 10 for i in range(1 + n)]
dp[0] = -10 ** 10
kek = 1
used = {0}


def dfs(v):
    global kek
    j = bisect_right(dp, A[v] - 1)
    old = -1
    if dp[j - 1] < A[v] < dp[j]:
        old = dp[j]
        dp[j] = A[v]
        if kek == j:
            for h in range(kek + 1, 1 + n):
                if dp[h] == 10 ** 10:
                    kek = h
                    break
            if kek == j:
                kek = n + 1
    ans[v] = kek - 1
    for u in gr[v]:
        if u not in used:
            used.add(u)
            dfs(u)
    dp[j] = old
    if kek > j and old == 10 ** 10:
        kek = j


dfs(0)
print(*ans)