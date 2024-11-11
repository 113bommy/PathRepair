n, a, b, k = map(int, input().split())
mod = 10**9 + 9  # prime
s = input()


def func(string):
    if string == "+":
        return 1
    return -1


def rev(d):
    return pow(d, mod-2, mod)


R = b*rev(a) % mod

seq = [func(s[i]) for i in range(k)]
if n + 1 <= k:
    ans = sum(seq[i]*pow(a, n-i, mod)*pow(b, i, mod)
              for i in range(n + 1)) % mod
    print(ans)
    exit()
S0 = sum(seq[i]*pow(a, n-i, mod)*pow(b, i, mod) for i in range(k)) % mod
u, v = divmod(n + 1, k)
ans = 0
if R != 1:
    ans += S0*(pow(R, u, mod) - 1)*rev(R - 1)
else:
    ans += u*S0
if v > 0:
    left = sum(seq[i]*pow(a, n-i, mod)*pow(b, i, mod)
               for i in range(v - 1)) % mod
    ans += pow(R, u, mod)*left % mod

print(ans % mod)

