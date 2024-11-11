from bisect import bisect_left


def read():
    return [int(c) for c in input().split()]


def sieve(n=101000):
    ans = [True] * (n + 1)
    ans[0] = False
    ans[1] = False
    for i in range(2, n // 2 + 1):
        if ans[i]:
            mul = 2 * i
            while mul < n + 1:
                ans[mul] = False
                mul += i

    return [i for i, e in enumerate(ans) if e]


def main():
    n, m = read()
    matrix = [read() for _ in range(n)]

    primes = sieve()

    rows = [0] * n
    cols = [0] * m
    for r in range(n):
        for c in range(m):
            sup_prime = bisect_left(primes, matrix[r][c])
            cur = sup_prime - matrix[r][c]
            rows[r] += cur
            cols[c] += cur

    print(min(rows + cols))


if __name__ == "__main__":
    main()