n,m=map(int,input().split())
L=0
R=100001
for i in range(m):
  l,r=map(int,input().split())
  L=max(L,l)
  R=min(R,r)
print(max(0,R-L+1))

  
