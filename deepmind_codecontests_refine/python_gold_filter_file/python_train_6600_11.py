from math import gcd
a, b, c, d = map(int, input().split())
if a / b > c / d:
    a *= d; c *= b
    print((a - c) // gcd(a - c, a), a // gcd(a - c, a), sep = '/')
else:
    c *= b; a *= d
    print((c - a) // gcd(c - a, c), c // gcd(c - a, c), sep = '/')
