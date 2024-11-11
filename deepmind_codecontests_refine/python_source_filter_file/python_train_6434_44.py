n,m=map(int,input().split())
L=100000
R=100000
for i in range(m):
  l,r=map(int,input().split())
  L=max(L,l)
  R=min(R,r)
print(max(0,R-L+1))

  
