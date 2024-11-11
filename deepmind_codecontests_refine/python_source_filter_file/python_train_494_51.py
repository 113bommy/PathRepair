from math import gcd
n = int(input())
ab = {}
ans = 0
mod = 10 ** 9 + 7


def go(a, b):
    if a == 0 and b == 0:
        return 0, 0
    elif a == 0:
        return 0, 1
    elif b == 0:
        return 1, 0
    c = gcd(a, b)
    a, b = a // c, b // c
    if a < 0:
        a *= - 1
        b *= - 1
    return a, b


def la(a, b):
    r = max((a, b), go(b, -a))
    if r == (a, b):
        return r, 0
    else:
        return r, 1


zero = 0
for i in range(n):
    a, b = [int(i) for i in input().split()]
    a, b = go(a, b)
    if a == b == 0:
        zero += 1
    else:
        l, ind = la(a, b)
        if l in ab:
            ab[l][ind] += 1
        else:
            ab[l] = [0, 0]
            ab[l][ind] += 1
ans = 1
for i in ab:
    ans *= pow(2, ab[i][0], mod) + pow(2, ab[i][1], mod)-1
    ans %= mod
print(ans + zero-1)
