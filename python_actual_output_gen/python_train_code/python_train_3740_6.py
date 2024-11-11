from sys import stdin

n, m = [int(x) for x in stdin.readline().split()]
a = [int(x) for x in stdin.readline().split()]

i = 0
res = []
for t in range(1, 1000000000):
    if t < a[i] and m >= t:
        res.append(t)
        m -= t
    elif t == a[i]:
        i += 1
    if m < t or i == len(a):
        break
if m > a[-1]:
    res.append(a[-1] + 1)
    m -= a[-1] + 1
    while m > res[-1]:
        m -= res[-1] + 1
        res.append(res[-1] + 1)

print(len(res))
print(' '.join([str(x) for x in res]))
