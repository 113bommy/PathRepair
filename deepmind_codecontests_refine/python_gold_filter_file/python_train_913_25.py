n=int(input())
A=sorted(map(int,input().split()))
ans=A[0]
for i in range(1,n):
  ans=(ans+A[i])/2
print(ans)
