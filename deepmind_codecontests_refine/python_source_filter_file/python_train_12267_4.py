import sys
N,K=map(int,input().split())
if K==0:
  print(N)
  sys.exit()
ans=0
for b in range(1,N+1):
  v=N//b
  r=N-b*v
  ans+=(v*(max(0,b-K))+max(0,r-K+1))
print(ans)