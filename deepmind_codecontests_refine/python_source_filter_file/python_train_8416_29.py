N,x=map(int,input().split())
A=list(map(int,input().split()))
t=0
for i in range(N-1):
  eat=max(0,A[i]+A[i+1]-x)
  A[i+1]-=eat
  t+=eat
print(t)