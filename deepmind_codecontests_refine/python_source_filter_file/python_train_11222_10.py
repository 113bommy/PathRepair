N = int(input())
H = list(map(int,input().split()))

dp = [0] * (N+1)
dp[0] = 0
for i in range(1, N):
    if H[i] <= H[i-1]:
        dp[i+1] = dp[i] + 1
print(dp[-1])
