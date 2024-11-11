k=input()
n=len(k)
d=int(input())
mod=10**9+7
dp=[[[0]*2 for _ in range(d)] for i in range(n)]
for num in range(int(k[0])+1):
    if num==int(k[0]):
        dp[0][num%d][0]=1
    else:
        dp[0][num%d][1]=1
for i in range(1,n):
    num=int(k[i])
    for l in range(10):
        for j in range(d):
            if l<num:
                dp[i][(j+l)%d][1]+=dp[i-1][j][0]
            elif l==num:
                dp[i][(j+l)%d][0]+=dp[i-1][j][0]
            dp[i][(j+l)%d][1]+=dp[i-1][j][1]
            dp[i][(j+l)%d][1]%=mod
            dp[i][(j+l)%d][0]%=mod
print((sum(dp[n-1][0])-1)%mod)