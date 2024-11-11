import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
N = int(input())
a = [0]
reva = [[] for _ in range(N + 1)]
for _ in range(N - 1): a.append(int(input()))
for i in range(N):
  if a[i] == 0: continue
  reva[a[i]].append(i + 1)
dp = [-1] * (N + 1)
def dfs(x):
  global dp
  if len(reva[x]) == 0:
    dp[x] = 1
    return 1
  t = []
  for y in reva[x]:
    t.append(dfs(y))
  t.sort(reverse = True)
  for i in range(len(t)):
    t[i] += i + 1
  dp[x] = max(t)
  return dp[x]
print(dfs(1) - 1)