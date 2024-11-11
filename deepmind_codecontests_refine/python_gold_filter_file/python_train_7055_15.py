N, M = map(int, input().split())
MOD = 10 ** 9 + 7


# 逆元の前計算
factorial = [1, 1]
inverse = [1, 1]
invere_base = [0, 1]
for i in range(2, N + M + 1):
    factorial.append((factorial[-1] * i) % MOD)
    invere_base.append((-invere_base[MOD % i] * (MOD // i)) % MOD)
    inverse.append((inverse[-1] * invere_base[-1]) % MOD)


def nCr(n, r):
    if not 0 <= r <= n:
        return 0
    return factorial[n] * inverse[r] * inverse[n - r] % MOD


def nPr(n, r):
    if not 0 <= r <= n:
        return 0
    return nCr(n, r) * factorial[r] % MOD


ans = pow(nPr(M, N), 2, MOD)
for k in range(1, N + 1):
    x = nCr(M, k) * nPr(N, k) * pow(nPr(M - k, N - k), 2, MOD) % MOD
    if k % 2 == 1:
        x = -x
    ans += x
    ans %= MOD

print(ans)
