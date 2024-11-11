def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    return x % m

a, b, n = map(int, input().split())
c = str(a) + str(b)
f, mod, ans = [1], 1000000007, 0
for i in range(1, n + 1):
    f.append(f[-1] * i % mod)
s = a * n
for i in range(n + 1):
    if all(i in c for i in str(s)):
        ans += f[n] * modinv(f[i] * f[n - i], mod) % mod
    s += b - a
print(ans)