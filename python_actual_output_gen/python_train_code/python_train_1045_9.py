N, M = map(int, input().split())
A = list(map(int, input().split()))

numbers = [None, 2, 5, 5, 4, 5, 6, 3, 7, 6]
dp = [0] * (N+1)
dp[0] = 0
for i in range(N+1):
    for a in A:
        j = i + numbers[a]
        if j <= N:
            dp[j] = max(dp[j], dp[i]*10 + a)
print(dp[N])