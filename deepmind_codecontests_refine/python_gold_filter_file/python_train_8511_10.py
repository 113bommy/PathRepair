def mod_inv(a, MOD):
    """ 前提: aとMODが互いに素であること """
    b = MOD
    u = 1
    v = 0
    while b:
        t = a // b
        a -= t * b
        u -= t * v
        a, b = b, a
        u, v = v, u
    u %= MOD
    return u


def prime_factorize(n):
    i = 2
    res = {}
    while i * i <= n:
        if n % i != 0:
            i += 1
            continue
        res[i] = 0
        while n % i == 0:
            res[i] += 1
            n //= i
        i += 1
    if n != 1:
        res[n] = 1
    return res


def solve(n):
    pf = prime_factorize(n)
    l = len(pf)
    pfk = []
    for i, p in enumerate(pf):
        pfk.append(p ** pf[p])

    ans = 10 ** 18

    for bit in range(1 << l):
        a = 1
        for d in range(l):
            if bit & (1 << d):
                a *= pfk[d]
        b = n // a

        if a == 1:
            k = n - 1
        elif b == 1:
            k = n
        else:
            m = mod_inv(b, a)
            k = b * m - 1
        # print(a, b, m, k)

        if k > 0 and k * (k + 1) // 2 % n == 0:
            ans = min(ans, k)
        else:
            ans = min(ans, k + n)

    return ans


n = int(input())
ans = solve(n)
print(ans)

# import random
#
# for n in range(1, 10000):
#     a = solve(n)
#     i = -1
#     for i in range(1, 2 * n + 1):
#         if i * (i + 1) // 2 % n == 0:
#             break
#     # print(n, a, i)
#     assert a == i
