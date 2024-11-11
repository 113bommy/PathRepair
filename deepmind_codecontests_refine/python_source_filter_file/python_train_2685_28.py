from math import gcd
import sys

N, M = map(int, input().split())
A = list(map(int, input().split()))

lcm = 1
for a in A:
    gcd_ = gcd(lcm, a//2)
    lcm = lcm * (a // 2 // gcd_)
for a in A:
    if lcm // (a // 2) % 2 == 1:
        print(0)
        sys.exit()

print(M // lcm - M // (2 * lcm))
