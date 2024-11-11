a = [int(input()) for _ in range(int(input()))]

dp = [[0] * 5 for _ in range(len(a) + 1)]

for i, x in enumerate(a):
    y = x % 2 + (x == 0) * 2
    z = (x + 1) % 2
    
    dp[i+1][0] = min(dp[i][0:1]) + x
    dp[i+1][1] = min(dp[i][0:2]) + y
    dp[i+1][2] = min(dp[i][0:3]) + z
    dp[i+1][3] = min(dp[i][0:4]) + y
    dp[i+1][4] = min(dp[i][0:5]) + x

print(min(dp[-1]))