import queue 
n,m = map(int, input().split())

ma = [[] for i in range(n+1)]
for i in range(m):
  a,b = map(int, input().split())
  ma[a].append(b)
  ma[b].append(a)

ans = 0
def dfs(i):
  global ans
  if all(reach[1:]):
    ans += 1
  for j in ma[i]:
    if reach[j] == 1:
      continue
    reach[j] = 1
    dfs(j)
    reach[j] = 0

reach=[0]*(n+1)
reach[1] = 1
dfs(1)
print(ans)