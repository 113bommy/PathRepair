from functools import reduce

n, m = map(int, input().split())

mod = 10 ** 9 + 7
ans = 0
c = 1
p1 = 1
p2 = reduce(lambda ac, v: ac * v % mod, range(m, m - n, -1), 1)
for i in range(n + 1):
    if i > 0:
        c = (c * (n - i + 1) * pow(i, mod - 2, mod)) % mod
        p1 = (p1 * (m - i + 1)) % mod
        p2 = (p2 * pow(m - i + 1, mod - 2, mod)) % mod
    x = c * p1 * (p2 ** 2)
    if i % 2 == 0:
        ans += x
    else:
        ans -= x
    ans %= mod
print(ans)
