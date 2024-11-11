import math
import decimal
import functools


@functools.lru_cache(maxsize=None)
def factorial(n):
    return math.factorial(n)


@functools.lru_cache(maxsize=None)
def binomial(k, n):
    if k > n // 2:
        return product(range(k + 1, n + 1)) / factorial(n - k)
    else:
        return product(range(n - k + 1, n + 1)) / factorial(k)


def P(k, n, m):
    return k ** 2 / n * binomial(k, n) * product((m - i) / (m * n - i) for i in range(k)) * product(
        (m * n - i - (n - k)) / (m * n - i) for i in range(k, n))


def product(iterable):
    res = 1
    for e in iterable:
        res *= e
    return res


def solve(n, m):
    return sum(P(k, n, m) for k in range(1, min(n, m) + 1))


if __name__ == '__main__':
    n, m = map(int, input().split())
    print(solve(n, m))
