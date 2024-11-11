n, k = map(int, input().split())
A = list(map(int, input().split()))

for i in range(min(30, k)):
    DP = [0] * (n+1)
    for j in range(n):
        light = A[j]
        DP[max(0, j-light)] += 1
        DP[min(n, j+light+1)] -= 1

    for j in range(1, n):
        DP[j] += DP[j-1]

    A = DP[:-1]

print(*A)