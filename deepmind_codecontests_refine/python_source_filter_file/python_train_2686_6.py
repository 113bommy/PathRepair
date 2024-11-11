p = int(input())


def div(a, b):
    n = len(a)
    m = len(b)
    res = [0] * (n - m + 1)
    tmp = pow(b[-1], p - 2, p)
    for i in range(n - m, -1, -1):
        t = a[i + m - 1] * tmp % p
        res[i] = t
        for j in range(m):
            a[i + j] = (a[i + j] - t * b[j]) % p
    return res


a = list(map(int, input().split()))
ans = [0] * p
f = [0] * (p + 1)
f[0] = 1
for i in range(p):
    for j in range(p, 0, -1):
        f[j] += f[j - 1]
        f[j - 1] = -f[j - 1] * i
        f[j] %= p
for i in range(p):
    if a[i] == 1:
        fm = div(f[:], [-i, 1])
        t = 1
        r = 0
        for v in fm:
            r += v * t
            t = t * i % p
        t = pow(r, p - 2, p)
        for j in range(len(fm)):
            ans[j] += fm[j] * t % p
for i in range(p):
    ans[i] %= p
print(' '.join(map(str, ans)))
