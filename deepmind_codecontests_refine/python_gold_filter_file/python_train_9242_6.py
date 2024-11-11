N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

inv_t = [0, 1] + [0] * (N - 1)
for i in range(2, N + 1):
    inv_t[i] = inv_t[MOD % i] * (MOD - MOD // i) % MOD

A.sort()
ans = 0
C = 1
for i in range(K, N + 1):
    ans += (A[i - 1] - A[N - i]) * C
    ans %= MOD
    C = C * i * inv_t[i - K + 1]
    C %= MOD
print(ans)
