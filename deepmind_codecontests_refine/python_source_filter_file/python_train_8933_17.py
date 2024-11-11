N, A, B, K = map(int, input().split())

mod = 998244353
fact = [1] * (N + 1)
ifact = [1] * (N + 1)


def init():
    for i in range(N):
        fact[i + 1] = fact[i] * (i + 1) % mod
        ifact[i + 1] = pow(fact[i + 1], mod - 2, mod)


def comb(x, y):
    if y < 0 or y > x:
        return 0
    return (fact[x] * ifact[x - y] * ifact[y]) % mod


ans = 0
init()
for a in range(N):
    n = K - a * A
    if n < 0:
        break
    if n % B == 0:
        ans += (comb(N, a) * (comb(N, n // B))) % mod
print(ans % mod)
