k = int(input())
s = input()
n = len(s)
mod = 10 ** 9 + 7

fac = [1] * (n + k + 2)
for i in range(1, n + k + 1):
    fac[i] = fac[i - 1] * i % mod


def c(n, k):
    return fac[n] * pow(fac[n - k] * fac[k] % mod, mod - 2, mod) % mod


ans = 0
for i in range(k + 1):
    ans += c(n - 1 + k - i, k - i) * \
        pow(25, k - i, mod) * pow(26, i, mod) % mod
    ans %= mod
print(ans)
