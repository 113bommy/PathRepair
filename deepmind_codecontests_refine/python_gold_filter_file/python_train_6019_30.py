n = int(input())
mod = 10**9+7
count = [0]*(2*10**5+1)
l = [0]+[int(input()) for i in range(n)]
dp = [0]*(n+1)
dp[0] = 1
for i in range(1,n+1):
    if l[i] == l[i-1]:
        dp[i] = dp[i-1]
        continue
    dp[i] = (dp[i-1]+count[l[i]])%mod
    count[l[i]] = dp[i]
print(dp[-1])