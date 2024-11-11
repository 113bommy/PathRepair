import sys
f = sys.stdin

n = int(f.readline())
s = [list(map(int, line.split())) for line in f]

p = [[i==j for j in range(n + 1)] for i in range(n + 1)]
c = [0] + [c for c,w in s]
sum_w = [0] + [w for c,w in s]
for i in range(1, len(sum_w)):
    sum_w[i] += sum_w[i - 1]
    
for length in range(n):
    for i in range(1, n + 1 - length):
        j = i + length
        if not p[i][j]:
            continue
        if j + 1 <= n:
            if sum_w[j] - sum_w[i - 1] <= c[j + 1]:
                p[i][j + 1] = True
        if sum_w[j] - sum_w[i - 1] <= c[i - 1]:
            p[i - 1][j] = True

dp = [999999999] * (n + 1)
dp[0] = 0
for b in range(1,n + 1):
    for e in range(1,n + 1):
        if p[b][e]:
            dp[e] = min(dp[e], dp[b - 1] + 1)

print(dp[-1])