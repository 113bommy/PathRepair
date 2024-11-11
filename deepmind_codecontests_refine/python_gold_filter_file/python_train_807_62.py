N=int(input())
A=list(map(int,input().split()))

d={}

for i,j in enumerate(A):
    d[i]=j

d=sorted(d.items(),key=lambda x:x[1],reverse=True)

dp=[[0]*(N+1) for _ in range(N+1)]

c=0
for k,v in d:
    for i in range(c+1):
        dp[i+1][c-i]=max(dp[i+1][c-i],dp[i][c-i]+abs(v*(k-i)))
        dp[i][c-i+1]=max(dp[i][c-i+1],dp[i][c-i]+abs(v*(N-(c-i)-k-1)))
    c+=1

ans=0
for i in range(N):
    ans=max(ans,dp[i][N-i])

print(ans)