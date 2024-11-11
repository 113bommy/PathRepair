N = int(input())
A = [int(input()) for i in range(N)]

M = 998244353

S = sum(A)
dp = [0 for _ in range(S + 1)]
dp[0] = 1
for a in A:
    for i in range(S, a - 1, -1):
        dp[i] = (2 * dp[i] + dp[i - a]) % M
    for i in range(a - 1, -1, -1):
        dp[i] = (2 * dp[i]) % M
dp2 = [0 for _ in range(S + 1)]
dp2[0] = 1
for a in A:
    for i in range(S, a - 1, -1):
        dp2[i] = (dp2[i] + dp2[i - a]) % M
s = 0
for i in range((S + 1) // 2, S + 1):
    s = (s + dp[i]) % M
ans = (3**N - 3 * s) % M
if S % 2 == 0:
    ans = (3**N - 3 * s + 3 * dp2[S // 2]) % M
print(ans)
