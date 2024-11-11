N, K = map(int, input().split())
A = list(map(int, input().split()))
Acum = 0
mod = 10 ** 9 + 7


dp = [0]*(K+1)
dp[0] = 1

for a in A:
    Acum += a
    newDP = [0]*(K+1)
    for i in range(min(Acum, K) + 1):
        if i == 0:
            newDP[i] = 1
            continue
        dp[i] += dp[i - 1]
        newDP[i] = dp[i]
        if i > a:
            newDP[i] -= dp[i - a - 1]
        newDP[i] %= mod
    dp = newDP[::]

ans = dp[K]
print(ans)
