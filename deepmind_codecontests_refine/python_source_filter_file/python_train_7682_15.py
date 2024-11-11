N, M, K = map(int, input().split())
MOD = 10 ** 9 + 7

P = 100005
fact = [0] * P
fact[0] = 1
for i in range(1, P):
    fact[i] = fact[i - 1] * i
    fact[i] %= MOD

rfact = [0] * P
rfact[P - 1] = pow(fact[P - 1], MOD - 2, MOD)
for i in range(P - 2, -1, -1):
    rfact[i] = rfact[i + 1] * (i + 1)
    rfact[i] %= MOD


def comb(n, k):
    return fact[n] * rfact[k] * rfact[n - k] % MOD


num = 0
for d in range(1, N):
    num += d * (N - d) * (M ** 2)
    num %= MOD

for d in range(1, M):
    num += d * (M - d) * (N ** 2)
    num %= MOD

num *= comb(N * M - 2, K - 2)
print(num % MOD)

