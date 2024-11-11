n = int(input())
a = list(map(int,input().split()))
b = []
for i in range(n):
    b.append([a[i],i])
b.sort()
b = b[::-1]
print(b)
dp = [[0]* (n+1) for i in range(n+1)]
cnt = 0
for i,j in b:
    for k in range(cnt+1):
        dp[cnt-k][k+1] = max(dp[cnt-k][k] + abs(n-1-j-k)*i,dp[cnt-k][k+1])
        dp[cnt-k+1][k] = max(dp[cnt-k][k] + abs(j-(cnt-k))*i,dp[cnt-k+1][k])
    cnt+=1
ans = 0
for k in range(n):
    ans = max(ans,dp[n+1-k-1][k])
print(ans)