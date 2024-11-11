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
    n = int(input())
    a = list(map(int, input().split()))

    stack = [(0, n, 0)]
    dp = {}

    while stack:
        l, r, base = stack[-1]
        min_depth = min(a[l:r])

        if (l, r, base) not in dp:
            dp[l, r, base] = -1
            i = 0
            for j in range(l, r):
                if a[j] == min_depth:
                    if i < j:
                        stack.append((i, j, min_depth))
                    i = j + 1
            if i < r:
                stack.append((i, r, min_depth))
        else:
            i, cost = 0, l
            for j in range(l, r):
                if a[j] == min_depth:
                    if i < j:
                        cost += dp[i, j, min_depth]
                    i = j + 1
            if i < r:
                cost += dp[i, r, min_depth]

            dp[l, r, base] = min(r - l, cost + min_depth - base)
            stack.pop()

    print(dp[0, n, 0])


if __name__ == '__main__':
    main()
