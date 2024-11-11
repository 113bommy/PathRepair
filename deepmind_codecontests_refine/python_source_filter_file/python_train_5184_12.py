N = int(input())
As = list(map(int, input().split()))
dp = [0] * 100000
mod = 10**9 + 7
ans = 1
dp[0] = 3
for a in As:
    a += 1
    ans *= dp[a-1]-dp[a]
    ans %= mod
    dp[a] += 1
print(ans%mod)