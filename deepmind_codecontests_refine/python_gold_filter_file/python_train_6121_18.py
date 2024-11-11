n=int(input())
A=list(map(int,input().split()))
ans=[0]*n
for i in range(n):
  a=A[i]
  ans[a-1]=i+1
print(*ans)