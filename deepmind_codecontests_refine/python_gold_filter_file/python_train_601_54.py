nl = lambda: list(map(int, input().split()))
sl = lambda: input().split()
n = lambda: int(input())
s = lambda: input()

N, M = nl()
S = nl()
T = nl()

dp = [0] * (M+1)
for i, s in enumerate(S):
    dp2 = dp[:]
    for j, t in enumerate(T):
        dp2[j+1] += dp2[j] - dp[j]
        if s == t:
            dp2[j+1] += dp[j] + 1
    dp = dp2

print((dp[M]+1) % 1000000007)
