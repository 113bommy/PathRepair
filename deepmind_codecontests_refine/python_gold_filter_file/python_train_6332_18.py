n,m=map(int,input().split())
p=list(map(int,input().split()))
pa=list(range(n))
def find(u):
  if u!=pa[u]:pa[u]=find(pa[u])
  return pa[u]
for i in range(m):
  a,b=map(int,input().split())
  a=find(a-1)
  b=find(b-1)
  if a!=b:pa[a]=b
c=0
for i in range(n):
  if find(p[i]-1)==find(i):c+=1
print(c)