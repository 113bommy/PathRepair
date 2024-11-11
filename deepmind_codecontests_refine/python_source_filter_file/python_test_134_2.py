from sys import stdin
from math import gcd
t = int(stdin.readline())
for _ in range(t):
    n = int(stdin.readline())
    a = list(map(int, stdin.readline().split()))
    g1, g2 = 0, 0
    for i in range(n):
        if i % 2 == 0:
            g1 = gcd(g1, a[i])
        else:
            g2 = gcd(g2, a[i])
    for i in range(1, n, 2):
        if a[i] % g1 == 0:
            break
    else:
        print(g1)
        continue
    for i in range(0, n, 2):
        if a[i] % 2 == 0:
            break
    else:
        print(g2)
        continue
    print(0)