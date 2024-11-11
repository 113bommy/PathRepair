import bisect

f_inf = float("inf")
n = int(input())
A = [int(input()) for _ in range(n)][::-1]
dp = [f_inf for _ in range(n + 1)]

for a in A:
    idx = bisect.bisect_left(dp, a)
    dp[idx] = a

ans = bisect.bisect_left(dp, f_inf)
print(ans)
