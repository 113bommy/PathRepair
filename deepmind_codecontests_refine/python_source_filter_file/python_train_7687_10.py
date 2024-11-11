import sys
sys.setrecursionlimit(10**7)
n, m = map(int, input().split())
ab = [[] for i in range(n)]
for i in range(m):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  ab[a].append(b)
  ab[b].append(a)

ary = []
def dfs(s,t):
  if len(t) == m:
    ary.append(t)
    return
  for i in ab[s]:
    if i not in t:
      dfs(i,t+[i])
  return
dfs(0,[0])

print (len(ary))