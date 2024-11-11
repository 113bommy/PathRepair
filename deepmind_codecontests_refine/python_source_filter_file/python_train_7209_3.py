import sys
from array import array  # noqa: F401
import typing as Tp  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def output(*args):
    sys.stdout.buffer.write(
        ('\n'.join(map(str, args)) + '\n').encode('utf-8')
    )


def main():
    t = int(input())
    ans_a = [''] * t

    for ti in range(t):
        if ti:
            input()
        n, m = map(int, input().split())
        a = [10**9 + 100] * (m + 1)
        acc = [0] * (m + 1)
        b = [0] * (m + 1)
        for i, (ai, bi) in enumerate(sorted([list(map(int, input().split())) for _ in range(m)], reverse=True), start=1):
            acc[i] = a[i] = ai
            b[i] = bi

        for i in range(1, m):
            acc[i + 1] += acc[i]

        ans = acc[min(n, m)] + max(0, n - m) * max(b)
        l = m

        for i in sorted(range(1, m + 1), key=lambda i: -b[i]):
            while a[l] < b[i]:
                l -= 1
            if l >= n:
                continue
            if a[l] > a[i]:
                ans = max(ans, acc[l] + a[i] + b[i] * (n - l - 1))
            else:
                ans = max(ans, acc[l] + b[i] * (n - l))

        ans_a[ti] = str(ans)

    output(*ans_a)


if __name__ == '__main__':
    main()
