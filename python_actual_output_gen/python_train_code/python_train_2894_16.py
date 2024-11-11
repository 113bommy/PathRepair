N,x=list(map(int,input().split()))
A=list(map(int,input().split()))

cnt=0
pre=0

for i in range(N):
  dif=max(A[i]+pre-x,0)
  cnt+=dif
  arr[i]-=dif
  pre=arr[i]
  
print(cnt)