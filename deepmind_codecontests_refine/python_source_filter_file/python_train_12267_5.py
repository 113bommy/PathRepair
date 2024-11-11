,K=map(int,input().split())
def f(b):
  d=max(b-K,0)*(N//b)+max(N%b-K+1,0)
  return d
ans=0
if K==0:
  print(N**2)
  exit()
  
for i in range(1,N+1):
  ans+=(f(i))
print(ans)