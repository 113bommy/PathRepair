from fractions import gcd
from functools import reduce

n, m = map(int, input().split())
a = [int(i) for i in input().split()]
c = 0
while a[0] % 2 == 0:
    a[0] //= 2
    c += 1
a[0] *= 2**c
for ai in a[1:]:
    if ai % 2 or (ai // 2) % 2 == 0:
        print(0)
        break
else:
    lcm = reduce(lambda x, y: x * y // gcd(x, y), a) // 2
    print(m // lcm - m // (2 * lcm))