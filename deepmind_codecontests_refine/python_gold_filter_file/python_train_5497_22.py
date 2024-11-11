N, K = map(int, input().split())
mod = 10**9+7

n = 1
A = []
while True:
    A.append(N//n)
    if N//(n+1) < n+1: break
    n += 1
A.append(n)

L = 2*n
dp = [[0]*L for _ in range(K)]
for l in range(n):
    dp[0][l] = 1

i = 0
for l in reversed(range(n, L)):
    dp[0][l] = A[i] - A[i+1]
    i += 1

for k in range(1, K):
    s = 0
    for l in reversed(range(L)):
        s = (s+dp[k-1][L-l-1]) % mod
        dp[k][l] = s * dp[0][l] % mod

ans = 0
for l in range(L):
    ans = (ans + dp[K-1][l]) % mod

print(ans)