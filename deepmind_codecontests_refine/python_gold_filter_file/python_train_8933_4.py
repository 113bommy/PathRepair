n, a, b, k = map(int, input().split())
MOD = 998244353

a_max =  min(k // a, n) + 1
pair = []
for i in range(a_max):
    if (k - a * i) % b == 0:
        j = (k - a * i) // b
        if j <= n:
            pair.append([i % MOD,j % MOD])

inv = [0] * (n + 1)
inv[1] = 1
for i in range(2, n + 1):
    inv[i] = (-(MOD // i) * inv[MOD % i]) % MOD

nCr = [0] * (n + 1)
nCr[0] = 1
for r in range(1, n + 1):
    nCr[r] = (nCr[r - 1] * (n - r + 1) * inv[r]) % MOD

result = 0
for p in pair:
    result += (nCr[p[0]] % MOD) * (nCr[p[1]] % MOD)

if result == 0:
    print(1)
else:
    print(result % MOD)