from math import gcd

n = int(input())
a = list(map(int, input().split()))
m = 10E10

for i in range(n):
    g = None
    for j in range(i, n):
        if g is None:
            g = gcd(a[i], a[j])
        else:
            g = gcd(g, a[j])

        if g == 1:
            m = min(m, j - i)

if m == 10E10:
    print(-1)
else:
    print(m + n - a.count(1))
