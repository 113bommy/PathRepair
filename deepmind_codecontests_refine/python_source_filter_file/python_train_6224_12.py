S = input()
M = 2019
dp = [0] * M
dp[0] = 1
t = 0
for i, s in enumerate(S[::-1]):
    t = (t + int(s) * (10 ** i)) % M
    dp[t] += 1

r = 0
for d in dp:
    r += d * (d - 1) // 2

print(r)
