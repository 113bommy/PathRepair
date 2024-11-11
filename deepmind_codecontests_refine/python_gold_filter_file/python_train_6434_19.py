N,M=map(int,input().split())
L=0
R=N

for _ in range(M):
  l,r=map(int,input().split())
  L=max(l,L)
  R=min(r,R)

print(max(R-L+1,0))
