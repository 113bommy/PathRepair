n = int(input())
a = list(map(int, input().split()))

dp = [1] * n

for i in range(1,n):
    if a[i] <= a[i-1] * 2:
        dp[i] = dp[i-1] + 1

print(max(dp))