n,m = map(int,input().split())
edg = [[] for i in range(n)]

for _ in range(m):
  a,b = map(int,input().split())
  a-=1
  b-=1
  edg[a].append(b)
  edg[b].append(a)
  
check1 = [0] * n
check0 = [0] * n

from collections import deque

q = deque()
q.append((0,1))
check0[0] = 1

while q:
  p,t = q.pop()
  for e in edg[p]:
    if t:
      if check1[e]:continue
      check1[e] = 1
      q.appendleft((e,0))
    else:
      if check0[e]:continue
      check0[e] = 1
      q.appendleft((e,1))
ans = 0
sc0 = sum(check0)
sc1 = sum(check1)
for i in range(n):
  if check0[i]:
    if check1[i]:
      ans += n - 1
    else:
      ans += sc0
  else:
      ans += sc1
print(ans//2 - m)
      
