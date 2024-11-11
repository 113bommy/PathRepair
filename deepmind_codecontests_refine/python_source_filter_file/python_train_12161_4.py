N,M,C=map(int,input().split())
B=list(map(int,input().split()))
ans=0
for i in range(N):
  A=list(map(int,input().split()))
  d=0
  for j,k in zip(A,B):
    d+=A*B
  if d>-C:
    ans+=1
print(ans)
  