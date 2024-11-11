h, n = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n)]
dp = [-1 for _ in range(h+1)]
dp[0] = 0
for i in range(1,h+1):
    dp[i] = min([dp[max(0, i-pw)]+ma for pw, ma in ab])
print(dp[h])