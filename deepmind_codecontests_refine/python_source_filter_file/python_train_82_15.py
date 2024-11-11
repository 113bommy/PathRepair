import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

import math
import decimal

ctx = decimal.Context(prec=1, rounding=decimal.ROUND_CEILING)

for i in range(int(input())):
    a, b, c, d = map(int, input().split())

    if a < b:
        print('No')
        continue

    if b > d:
        print('No')
        continue

    if c >= b:
        print('Yes')
        continue

    g = gcd(b, d)
    r = a % g
    # FYI: https://stackoverflow.com/questions/2795946/getting-ceil-of-decimal-in-python
    #_max = (int(((decimal.Decimal(b, context=ctx) - decimal.Decimal(r, context=ctx)) / decimal.Decimal(g, context=ctx)).to_integral_exact(context=ctx)) * g) + r - g

    # math.ceilは精度不足でエラーになる: https://cocoinit23.com/math-floor-ceil-error/
    _max = (int(math.ceil((b - r) / g)) * g) + r - g

    # OK: (a + b - 1) // b: https://nariagari-igakusei.com/cpp-division-round-up/
    #_max = ((b - r + g - 1)//g) * g + r - g
    if c < _max:
        print('No')
    else:
        print('Yes')
