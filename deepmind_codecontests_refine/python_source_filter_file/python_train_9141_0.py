N = int(input())
A = list(map(int, input().split()))
INF = float("inf")
B = [[A[i], -INF] for i in range(1 << N)]
for i in range(N):
    for j in range(1 << N):
        if j & (1 << i):
            tmp = B[j] + B[j ^ (1 << i)]
            tmp = sorted(tmp, reverse=True)
            B[j] = tmp[:2]

ans = -INF
for i in range(1, 1 << N):
    ans = max(ans, sum(B[i]))
    print(sum(B[i]))