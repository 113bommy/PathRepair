N=int(input())
A=list(map(int, input().split()))
A=sorted([(a,p) for p, a in enumerate(A)])[::-1]

dp=[[0]*(N+1) for _ in range(N+1)]
for i,(a,p) in enumerate(A):
  for j in range(i+1):
    #左詰
    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+(p-j)*a)
    #右詰
    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+((N-1-(i-j))-p)*a)
print(max(dp[-1]))