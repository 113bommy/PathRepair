f=lambda:map(int,input().split())
n,m=f()
L,R=0,n
for i in range(m):
  l,r=f()
  L=max(L,l)
  R=min(R,r)
print(max(0,R-L+1))