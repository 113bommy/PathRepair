from sys import stdin
from collections import defaultdict
from math import gcd


def main():
    MOD = 1000000007

    N, *AB = map(int, stdin.buffer.read().split())

    d = defaultdict(int)
    n_zeros = 0

    for a, b in zip(AB[::2], AB[1::2]):
        if a == 0 and b == 0:
            n_zeros += 1
            continue

        g = gcd(a, b)
        a, b = a // g, b // g

        if a * b > 0 or a == 0:
            c = (abs(a), abs(b))
        else:
            c = (-abs(a), -abs(b))

        d[c] += 1

    ans = 1
    n_not_paired = 0
    for ab, n in d.items():
        ab_pair = (-ab[1], -ab[0])
        if ab_pair in d:
            if ab[0] > 0:
                m = d[ab_pair]
                ans = ans * (pow(2, n, MOD) + pow(2, m, MOD) - 1) % MOD
        else:
            n_not_paired += n

    ans = (ans * pow(2, n_not_paired, MOD) + n_zeros - 1) % MOD
    print(ans)


if __name__ == '__main__':
    main()
