import sys
from fractions import gcd
N, M = map(int, input().split())
an = list(map(lambdax: int(x)//2, input().split()))

lcm = an[0]
for a in an[1:]:
    l = lcm*a//gcd(lcm, a)
    if not (l//lcm % 2 == l//a % 2):
        print(0)
        sys.exit()
    lcm = l
print((M//lcm+1)//2)