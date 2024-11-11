N=int(input())
a=list(map(int,input().split()))
A=[0]*(N+1)
B=sum(a)
for i in range(N):
  A[i+1]=A[i]+a[i]
s=10**15
for i in range(1,N+1):
  t=min(s,abs(2*A[i]-B))
print(t)
  
