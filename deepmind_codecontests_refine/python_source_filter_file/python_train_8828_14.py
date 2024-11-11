import sys
sys.setrecursionlimit(2 << 30)

n, m = [int(i) for i in input().split()]
al = [set() for _ in range(n)]
for _ in range(m):
    x, y = [int(i) for i in input().split()]
    al[x-1].add(y-1)

dp = [-1] * n


def rec(v):
    if dp[v] != -1:
        return dp[v]
    ret = 0
    for nv in al[v]:
        ret = max(ret, rec(nv) + 1)
    dp[v] = ret
    return ret


ans = 0
for v in range(n):
    ans = max(ans, rec(v))

print(ans)
