import sys
sys.setrecursionlimit(10**6)
n,k = map(int,input().split())
a = [int(i)-1 for i in input().split()]
edg = [[] for i in range(n)]
for i in range(1,n):
  edg[a[i]].append(i)
ans = [0] * n
ans[0] = a[0] != 0
def dfs(now):
  res = 0
  for e in edg[now]:
    res = max(res, dfs(e)+1)
  if res == k - 1 and a[now] != 0:
    ans[now] = 1
    res = -1
  return res
      
dfs(0)
print(sum(ans))
