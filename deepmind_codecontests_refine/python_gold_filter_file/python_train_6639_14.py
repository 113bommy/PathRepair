n = int(input())
A = list(map(int, input().split()))

dp = [0] * (10**6+1)

for a in A:
    dp[a] += 1

for i in range(1, len(dp)):
    if dp[i]:
        for j in range(i+i, len(dp), i):
            dp[j] = 0
print(dp.count(1))
