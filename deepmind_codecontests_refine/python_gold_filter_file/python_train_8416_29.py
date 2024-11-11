N,x=map(int,input().split())
A=[0]+list(map(int,input().split()))
t=0
for i in range(N):
  eat=max(0,A[i]+A[i+1]-x)
  A[i+1]-=eat
  t+=eat
print(t)