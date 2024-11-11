N=int(input())
A=list(map(int,input().split()))
ans=0
for i in range(N):
  for j in range(i,N):
    ans+=A[i]*A[j]
print(ans)