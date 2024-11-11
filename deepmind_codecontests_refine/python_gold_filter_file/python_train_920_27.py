n,x=map(int,input().split())
A=[int(i) for i in input().split()]
B=[float("inf")]*n
ans=float("inf")
for i in range(n):
  ans_i=i*x
  for j in range(n):
    B[j]=min(B[j],A[j-i])
    ans_i+=B[j]
  ans=min(ans,ans_i)
print(ans)