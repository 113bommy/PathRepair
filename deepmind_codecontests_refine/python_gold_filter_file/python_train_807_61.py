import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

n = int(input())
A = list(map(int, input().split()))
L = [(a, i) for i, a in enumerate(A)]
L.sort(reverse=True)
dp = [[-1]*n for _ in range(n)]
def dfs(l, r):
    i = (n-1-r) + l
    a, idx = L[i]
    if i == n-1:
        res = max(idx-l, r-idx) * a
        return res
    if dp[l][r] != -1:
        return dp[l][r]
    res = max((idx-l)*a + dfs(l+1, r), (r-idx)*a + dfs(l, r-1))
    dp[l][r] = res
    return res
ans = dfs(0, n-1)
print(ans)