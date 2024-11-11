import fractions
import math

def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)


n, m = list(map(int, input().split()))
a = list(map(lambda x: int(x) // 2, input().split()))
lcm_all = 1
for e in a:
    lcm_all = lcm(lcm_all, e)
    if (lcm_all // e) % 2 == 0:
        print(0)
        exit()
print(math.ceil(m / lcm_all) // 2)
