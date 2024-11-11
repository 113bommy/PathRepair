n,q=map(int,input().split())
a=[0]*(n-1)
c=[0 for i in range(n)]
for i in range(n-1):
  a[i]=list(map(int,input().split()))
 
a.sort()
 
for i in range(q):
  x,y=map(int,input().split())
  c[x-1]+=y
 
for i in range(n-1):
  c[a[i][1]-1]+=c[a[i][0]-1]
 
print(*c)