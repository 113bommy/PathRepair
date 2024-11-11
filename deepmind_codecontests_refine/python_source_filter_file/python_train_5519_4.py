N=int(input())
M=[input().split()[2:]for _ in[0]*N]
q=[0]
d=[0]+[-1]*~-N
while q:
 u=q.pop()
 for v in M[u]:
  v=int(v)-1
  if d[v]<0:d[v]=d[u]+1;q+=[v]
for i in range(N):print(i+1,d[i])
