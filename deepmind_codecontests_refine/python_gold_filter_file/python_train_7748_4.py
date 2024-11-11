N, K = map(int, input().split())
mod = 10 ** 9 + 7
dn = [[0]*(max(N, K) + 1)] + [[1]*(max(N, K) + 1)] + [[0]*(max(N, K) + 1) for _ in range(max(N, K) + 1)]
for i in range(1, max(N, K) + 1):
    for j in range(1, N + 1):
        for k in range(j, N + 1, j):
            dn[i+1][j] = (dn[i+1][j] + dn[i][k]) % mod
print((sum(dn[K]) - dn[K][0]) % mod)
