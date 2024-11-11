def comb(n, r, p):
    return fac[n] * facinv[r] * facinv[n - r] % p


def comb_pre(N_UNTIL, p):
    for i in range(2, N_UNTIL + 1):
        fac.append(fac[i - 1] * i % p)
        inv.append(-inv[p % i] * (p // i) % p)
        facinv.append(facinv[-1] * inv[-1] % p)


fac = [1, 1]
facinv = [1, 1]
inv = [0, 1]

K = int(input())
S = input()
N = len(S)
MOD = 1_000_000_007
comb_pre(N + K - 1, MOD)
ans = 0
for i in range(K + 1):
    tmp = pow(25, K - i, MOD)
    tmp *= comb(N + K - i - 1, K - i, MOD)
    tmp %= MOD
    tmp *= pow(26, i, MOD)
    tmp %= MOD
    ans += tmp
    ans %= MOD
print(ans)
