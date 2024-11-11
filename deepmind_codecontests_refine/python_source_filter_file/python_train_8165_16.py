from collections import Counter as C
n = int(input())
l = [*map(int, input().split())]
c = [(0, 0)] + sorted(C(l).items())
print(c)
dp = {}
for i in range(1, len(c)):
    dp[i] = max(
        dp.get(i - 1, 0) + (0 if c[i - 1][0] + 1 == c[i][0] else c[i][0] * c[i][1]), 
        dp.get(i - 2, 0) + c[i][1] * c[i][0]
    )
    
print(dp[len(c) - 1])