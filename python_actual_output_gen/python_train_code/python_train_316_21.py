n=int(input())
A=sorted(map(int,input().split()))
ans=0
for i in range(n-1):
  ans=(ans+A[i])/2
print(ans)