def pow1(x, base):
    if base == 0:
        return 1
    sq = pow1(x, base // 2)
    sq = (sq * sq) % mod

    if base % 2:
        sq *= x
    return sq


def sum_range(n):
    return ((n * (n + 1)) % mod) // 2


n, mod = int(input()), 1000000007
level = pow1(2, n)
print(sum_range(level) % mod)
