import sys
from array import array  # noqa: F401
import typing as Tp  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    n = int(input())
    s = input().rstrip()
    tx, ty = map(int, input().split())
    acc_x, acc_y = [0] * (n + 1), [0] * (n + 1)
    for i, c in enumerate(s, start=1):
        acc_x[i] = acc_x[i - 1] + (1 if c == 'R' else -1 if c == 'L' else 0)
        acc_y[i] = acc_y[i - 1] + (1 if c == 'U' else -1 if c == 'D' else 0)

    if acc_x[-1] == tx and acc_y[-1] == ty:
        print(0)
        exit()
    if (abs(acc_x[-1] - tx) + abs(acc_y[-1] - ty)) & 1:
        print(-1)
        exit()

    ans = inf = 10**9

    for left in range(n):
        ok, ng = n + 1, left - 1

        while abs(ok - ng) > 1:
            mid = (ok + ng) >> 1
            dist = abs(acc_x[-1] - acc_x[mid] + acc_x[left] - tx)\
                + abs(acc_y[-1] - acc_y[mid] + acc_y[left] - ty)
            if dist <= mid - left:
                ok = mid
            else:
                ng = mid

        if ok < n + 1:
            ans = min(ans, ok - left)

    print(ans if ans < inf else -1)


if __name__ == '__main__':
    main()
