import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
MOD = 10**9+7

n = int(input())
T = [[] for _ in range(n)]
for _ in range(n-1):
  x, y = map(int, input().split())
  x -= 1
  y -= 1
  T[x].append(y)
  T[y].append(x)
dp = [[-1]*n for _ in range(2)]
def dfs(color, i, par=-1):
  if dp[color][i] != -1:
    return dp[color][i]
  res = 1
  if color == 0:
    for v in T[i]:
      if v == par:
        continue
      res *= dfs(0, v, i) + dfs(1, v, i)
      res %= MOD
  else:
    for v in T[i]:
      if v == par:
        continue
      res *= dfs(0, v, i)
      res %= MOD
  dp[color][i] = res
  return res
ans = dfs(0, 0) + dfs(1, 0)
ans %= MOD
print(ans)