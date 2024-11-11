N, K, *A = map(int, open(0).read().split())

dp = [False] * (2 * K + 1)
for i in range(1, K + 1):
    if not dp[i]:
        for a in A:
            dp[i + a] = True

if dp[K]:
    print("First")
else:
    print("Second")