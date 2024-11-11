n = int(input())
f = lambda: ''.join(input() for i in range(n))
a, b = f(), f()
g = lambda k: k // n + n * (n - 1 - k % n)
e = lambda k: k
h = lambda k: n * (n - 1 - k // n) + k % n
v = lambda k: n * (k // n) + n - 1 - k % n
for i in (v, h, e):
    for j in [e, g, lambda k: g(g(k)), lambda k: g(g(g(k)))]:
        if all(a[k] == b[i(j(k))] for k in range(n)): exit(print('Yes'))
print('No')