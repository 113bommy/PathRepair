n,m=map(int,input().split())
A={int(input()) for _ in range(m)}
dp=[1]+[0]*(n+1)
for i in range(n):
    if i in A:
        continue
    dp[i+1] += dp[i]
    dp[i+2] += dp[i]
print(dp[n]%(10**9 + 7))