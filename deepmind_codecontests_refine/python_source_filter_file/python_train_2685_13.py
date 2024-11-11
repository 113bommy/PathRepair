from math import gcd, ceil


def lcm(a, b):
    return (a*b)//gcd(a, b)


n, m = map(int, input().split())
a = list(map(int, input().split()))

for i in range(n):
    a[i] = a[i]//2

lcm_v = a[0]
for i in range(1, n):
    lcm_v = lcm(lcm_v, a[i])

ok = True
for aa in a:
    if (lcm_v//aa) % 2 != 1:
        ok = False
        break

if ok:
    ans = ((m//lcm_v)+1)//2
print(ans)