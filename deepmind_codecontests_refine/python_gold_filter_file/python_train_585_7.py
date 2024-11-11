def f(x):
    res = (x // k1) * val
    e = x % k1
    if e <= k:
        res += e
    else:
        res += k + (e - k) / 2
    return res

k, d, t = map(int, input().split())
c = (k - 1) // d + 1
k1 = c * d
rem = -k % d
val = k + rem / 2
l = 0
r = 1e50
for i in range(500):
    m = (l + r) / 2
    if f(m) >= t:
        r = m
    else:
        l = m
print('%.10f' % r)