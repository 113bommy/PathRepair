n = int(input())
A = [(a, i) for i, a in enumerate(map(int, input().split()))]
A.sort(reverse=True)
dp = [[0]*(n+1) for _ in range(n+1)]
ans = 0
for L in range(n+1):
    for R in range(n+1):
        if n <= L+R-1:
            continue
        a, i = A[L+R-1]
        if 0 <= R-1:
            dp[L][R] = max(dp[L][R], dp[L][R-1]+abs((n-R)-i)*a)
        if 0 <= L-1:
            dp[L][R] = max(dp[L][R], dp[L-1][R]+abs(i-(L-1))*a)
        ans = max(ans, dp[L][R])
print(ans)
