n, b = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
k = [0, 0]
dp = []
for i in range(len(a) - 1):
    k[a[i] % 2] += 1
    if k[0] == k[1]:
        dp.append(abs(a[i] - a[i - 1]))

dp.sort()
sm = 0
i = 0
while i < len(dp):
    if dp[i] + sm > b:
        break
    sm += dp[i]
    i += 1
print(i)
