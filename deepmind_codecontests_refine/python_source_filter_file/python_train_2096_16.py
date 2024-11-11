from math import gcd
for _ in range(int(input())):
    a = int(input())
    k = a/gcd(a, 180)
    n = a/gcd(a, 180)
    if k == n-1: print(n+n)
    else: print(n)