import sys
from array import array  # noqa: F401
from typing import List, Tuple, TypeVar, Generic, Sequence, Union  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    n = int(input())
    a = sorted(map(int, input().split()))
    ans = 0

    for d in range(25, -1, -1):
        bit = 1 << d
        cnt = 0
        j = k = l = n - 1

        for i, x in enumerate(a):
            j, k, l = max(j, i), max(k, i), max(l, i)

            while i < j and a[j] >= bit - x:
                j -= 1
            while j < k and a[k] >= 2 * bit - x:
                k -= 1
            while k < l and a[l] >= 3 * bit - x:
                l -= 1

            cnt += k - j + n - 1 - l

        if cnt & 1:
            ans += bit

        for i in range(n):
            a[i] &= ~bit

        a.sort()

    print(ans)


if __name__ == '__main__':
    main()
