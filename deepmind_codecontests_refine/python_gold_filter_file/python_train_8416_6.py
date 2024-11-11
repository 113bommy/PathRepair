N,x=map(int,input().split())
A=list(map(int,input().split()))
cnt=0
for i in range(N):
  cnt+=max(A[i]-x,0)
  A[i]=min(A[i],x)
for i in range(1,N):
  d=max(A[i]+A[i-1]-x,0)
  A[i]-=d
  cnt+=d
print(cnt)