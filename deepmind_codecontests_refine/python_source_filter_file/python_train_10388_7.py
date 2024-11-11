from bisect import bisect
from sys import setrecursionlimit

setrecursionlimit(10000000)

N = int(input())
A = tuple(map(int,input().split()))
adj = [list() for _ in range(N)]
for _ in range(N-1):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    adj[a].append(b)
    adj[b].append(a)


res = [None]*N
dp = [float('inf') for _ in range(N)]

def rec(v, ml):
    """
    dp[l]: min tail value of increasing subsequence of length l+1
    """
    a = A[v]
    i = bisect(dp, a)
    ml += int(ml == i)
    res[v] = ml

    orig = dp[i]
    dp[i] = a
    for u in adj[v]:
        if res[u] is None:
            rec(u, ml)
    dp[i] = orig

rec(0, 0)

print(*res, sep='\n')
