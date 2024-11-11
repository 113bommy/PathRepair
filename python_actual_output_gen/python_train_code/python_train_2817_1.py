n=int(input())
A=list(map(int,input().split()))
ans=10**9
sumA=sum(A)

for i in range(n-1):
  x+=A[i]
  ans=min(ans,abs(sumA-x*2))

print(ans)