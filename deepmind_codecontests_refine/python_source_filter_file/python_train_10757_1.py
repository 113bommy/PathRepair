start, end, k = input(), input(), int(input())
dp = [[start == end for _ in range(k + 1)], [start != end for _ in range(k + 1)]]
mod = int(1e9 + 7)
same = sum(end == (start[i: len(start)] + start[0: i]) for i in range(len(start)))
diff = len(start) - same
for i in range(1, k + 1):
    dp[0][i] = (dp[0][i - 1] * (same - 1) + dp[1][i - 1] * same) % mod
    dp[1][i] = (dp[0][i - 1] * diff + dp[1][i - 1] * (diff - 1)) % mod
print(dp[0][k])