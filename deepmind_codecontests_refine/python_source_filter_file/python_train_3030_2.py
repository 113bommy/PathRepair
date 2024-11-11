import sys
input=sys.stdin.readline
from collections import deque
n=int(input())
g=[[] for i in range(n)]
for _ in range(n-1):
  u,v=map(int,input().split())
  g[u-1].append(v-1)
  g[v-1].append(u-1)
a=list(map(int,input().split()))
idx=[0]*(n+1)
for i in range(n):
  idx[a[i]]=i
for i in range(n):
  g[i].sort(key=lambda x:idx[x])
b=[]
dq=deque([[-1,0]])
b.append(1)
while dq:
  par,ver=dq.popleft()
  for to in g[ver]:
    if par!=to:
      b.append(to+1)
      dq.append([ver,to])
if all(a[i]==b[i] for i in range(n)):
  print("Yes")
else:
  print("No")