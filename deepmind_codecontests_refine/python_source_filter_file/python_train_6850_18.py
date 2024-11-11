from collections import*
n,m,*t=map(int,open(0).read().split())
*w,s,t=[t-1for t in t]
e=[[]for _ in range(n)]
for u,v in zip(w[::2],w[1::2]):
  e[u].append(v)
INF=10**18
f=[[INF]*3for _ in range(n)]
f[s][0]=0
q=deque([(s,0)])
while q:
  v,m=q.popleft()
  if v==t and m==2:
    print(f[v][2])
    break
  for w in e[v]:
    if f[w][-~m%3]<INF:continue
    f[w][-~m%3]=f[v][m]+1
    q.append((w,-~m%3))
else:
  print(-1)