n,m=map(int,input().split())
L,R=10**18,0
for i in range(m):
  l,r=map(int,input().split())
  L=max(L,l)
  R=min(R,r)
if R<L:
  print(0)
else:
  print(R-L+1)