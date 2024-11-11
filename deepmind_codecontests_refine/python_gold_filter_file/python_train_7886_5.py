import sys
sys.setrecursionlimit(10 ** 9)
n,m = map(int, input().split())
ab = []
c = [set() for i in range(n)]

for i in range(m):
  a = list(map(int, input().split()))
  a.sort()
  x,y = a[0]-1,a[1]-1
  c[x].add(y)
  c[y].add(x)

def dfs(s):
  if vis[s] == False:
    ary.append(s)
    vis[s] = True
    for j in c[s]:
      dfs(j)

vis = [False for i in range(n)]

ans= []

for i in range(n):
  ary = []
  dfs(i)
  if len(ary) == 0:
    continue
  ans.append(len(ary))

print (len(ans)-1)