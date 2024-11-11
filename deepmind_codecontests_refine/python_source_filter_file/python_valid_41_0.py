n, m = map(int, input().split())
s = list(input())
a = [0] * (n + 1)
b = [0] * (n + 1)
c = [0] * (n + 1)
d = [0] * (n + 1)
e = [0] * (n + 1)
f = [0] * (n + 1)
pa, pb, pc, pd, pe, pf = 'abc', 'bca', 'cab', 'acb', 'cba', 'cab'
for i in range(n):
    if s[i] != pa[i % 3]:
        a[i] += 1
    if s[i] != pb[i % 3]:
        b[i] += 1
    if s[i] != pc[i % 3]:
        c[i] += 1
    if s[i] != pd[i % 3]:
        d[i] += 1
    if s[i] != pe[i % 3]:
        e[i] += 1
    if s[i] != pf[i % 3]:
        f[i] += 1
for i in range(1, n):
    a[i] += a[i - 1]
    b[i] += b[i - 1]
    c[i] += c[i - 1]
    d[i] += d[i - 1]
    e[i] += e[i - 1]
    f[i] += f[i - 1]
ans = []
for _ in range(m):
    L, R = map(lambda z: int(z) - 1, input().split())
    ans.append(min(a[R] - a[L - 1],
                   b[R] - b[L - 1],
                   c[R] - c[L - 1],
                   d[R] - d[L - 1],
                   e[R] - e[L - 1],
                   f[R] - f[L - 1]))
print('\n'.join(map(str, ans)))
               
