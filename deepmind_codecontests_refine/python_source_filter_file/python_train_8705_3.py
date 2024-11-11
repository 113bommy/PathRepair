from bisect import *
f = lambda: map(int, input().split())
n, m = f()
t = list(f())
def g(x, i, n, s):
    if i < n:
        g(x, i + 1, n, s + t[i])
        g(x, i + 1, n, s)
    else: x.add(s % m)
k = n >> 1
x, y = set(), set()
g(x, 0, k, 0)
g(y, k, n, 0)
y = sorted(y)
print(max(i + y[bisect(y, m - i) - 1] for i in x))