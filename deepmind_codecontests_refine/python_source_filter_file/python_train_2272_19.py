from collections import Counter

N, K, *DC = map(int, open(0).read().split())

D = tuple(zip(*[iter(DC[:K * K])] * K))
C = tuple(zip(*[iter(DC[K * K:])] * N))

A = [Counter() for _ in range(3)]
for k in range(K):
    for i in range(N):
        for j in range(N):
            A[(i + j) % 3][k] += D[C[i][j] - 1][k]

ans = float("inf")
for i in range(K):
    for j in range(K):
        for k in range(K):
            if i == j or j == k or k == i:
                continue
            ans = min(ans, A[0][i] + A[1][j] + A[2][k])

print(ans)