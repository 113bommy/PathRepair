MOD = 10 ** 9 + 7
K = int(input())
M = len(input())
N = M + K

pow25 = [1] * (N + 1)
fac = [1] * (N + 1)
inv = [1] * (N + 1)
for x in range(1, N + 1):
    fac[x] = fac[x - 1] * x % MOD
    pow25[x] = pow25[x - 1] * 25 % MOD
inv[N] = pow(fac[N], MOD-2, MOD)
for x in range(N - 1, -1, -1):
    inv[x] = inv[x + 1] * (x + 1) % MOD

def binom(n, k):
    return fac[n] * inv[n - k] % MOD * inv[k] % MOD

ans = 0
for k in range(M, N + 1):
    ans += binom(N, k) * pow25[N - k] % MOD
    ans %= MOD
print(ans)