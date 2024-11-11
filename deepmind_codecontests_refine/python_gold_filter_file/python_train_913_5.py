N=int(input())
A=sorted(list(map(int,input().split())))
ans=A[0]
for i in range(1,N):
  ans=(ans+A[i])/2
print(ans)