import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**7)
n=int(input())
t=[[] for i in range(n)]
for i in range(1,n):
  a=int(input())
  t[a-1].append(i)
def dfs(v):
  if not t[v]:
    return 0
  l=[dfs(i)+1 for i in t[v]]
  l.sort()
  for i in range(len(t[v])-1):
    l[i+1]=max(l[i+1],l[i]+1)
  return l[-1]
print(dfs(0))