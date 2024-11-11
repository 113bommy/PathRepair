N,M=map(int,input().split())
L,R=0,N
for _ in range(M):
  l,r=map(int,input().split())
  L=max(l,L)
  R=min(r,R)
print(R-L+1)