import sys
from array import array  # noqa: F401
from typing import List, Tuple, TypeVar, Generic, Sequence, Union  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    n, m = map(int, input().split())
    if n < 3:
        if m == 0:
            print([1, 2][:n])
        else:
            print(-1)
        exit()

    ans = [1, 2]

    for i in range(3, n + 1):
        if ((i - 1) >> 1) >= m:
            ans.append(2 * i - 2 * m - 1)
            m = 0
            break
        ans.append(i)
        m -= (i - 1) >> 1

    for i in range(n - len(ans)):
        ans.append(10**8 + i * 10000)

    if m == 0:
        print(*ans)
    else:
        print(-1)


if __name__ == '__main__':
    main()
