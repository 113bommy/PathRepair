import sys
input = sys.stdin.readline

MOD = 10**9 + 7
N = int(input())

dp = [0] * (N+10)
dp_cum = [0] * (N+10)

dp[1] = N-1; dp_cum[1] = N-1
dp[2] = N-1; dp_cum[2] = 2*(N-1)
for n in range(3,N+1):
    dp[n] = dp[n-1] + dp_cum[n-3]
    dp_cum[n] = (dp_cum[n-1] + dp[n]) % MOD

answer = sum(dp[1:N])*N + dp[-1] + 1
answer %= MOD
print(answer)