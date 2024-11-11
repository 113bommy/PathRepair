n,k = map(int,input().split())
h = list(map(int,input().split()))
dp = [float("inf")]*n
dp[0] = 0

for i in range(1,n):
    for s in range(min(k,i)+1):
        dp[i] = min(dp[i],dp[i-s]+abs(h[i]-h[i-s]))

print(dp[-1])