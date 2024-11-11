def mulmod(x, y, mod=10**9 + 7):
    return x * y % mod


def comb(n, k, mod=10**9 + 7):
    from functools import reduce
    k = min(k, n - k)
    x = reduce(mulmod, range(n - k + 1, n + 1), 1)
    y = reduce(mulmod, range(1, k + 1), 1)
    return x * pow(y, mod - 2, mod) % mod


def solve(string):
    n, m, k = map(int, string.split())
    mod = 10**9 + 7
    base = n * m * (n + m) * (n * m - 1) // 6 % mod
    return str(base * comb(n * m - 2, k - 2) % mod)


if __name__ == '__main__':
    print(solve(input()))
