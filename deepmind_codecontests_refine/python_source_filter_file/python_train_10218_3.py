import math

n, k = map(int, input().split())
a, b = map(int, input().split())
MOD = n * k

x, y = 10 ** 9, 0
for s in [(1 - a + MOD) % MOD, 1 + a]:
    for i in range(n):
        t = k * i + 1

        el1 = (t - b + MOD) % MOD
        if el1 == 0:
            el1 = MOD
        l1 = (el1 - s + MOD)
        m = MOD // math.gcd(l1, MOD)
        x, y = min(x, m), max(y, m)

        el2 = (t + b + MOD) % MOD
        if el2 == 0:
            el2 = MOD
        l2 = (el2 - s + MOD)
        m = MOD // math.gcd(l2, MOD)
        x, y = min(x, m), max(y, m)


print(x if x != 10 ** 9 else 0, y)
