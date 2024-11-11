N,M=map(int,input().split())
L=0
R=10000
for i in range(M):
  l,r=map(int,input().split())
  L=max(L,l)
  R=min(r,R)
if L>R :
  print(0)
else :
  print(R-L+1)