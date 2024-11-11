n,k = map(int,input().split())
h = list(map(int,input().split()))
dp = [float("inf")]*n
dp[0] = 0
for i in range(1,n):
    dp[i] = min(dp[j]+abs(h[i]-h[j]) for j in range(max(0,i-k),i))
print(dp[-1])