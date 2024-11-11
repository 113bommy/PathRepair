import io
import os
from collections import defaultdict
from sys import stdin, stdout
input = stdin.readline


def main():
    n = int(input())
    a = sorted(map(int, input().split()))
    s = set(a)
    res = []
    pow2 = [2**i for i in range(1, 31)]
    for val in a:
        for p in pow2:
            if val+p in s and val+2*p in s:
                res.append(val)
                res.append(val+p)
                res.append(val+2*p)
                break
        if res:
            break

    if not res:
        for val in a:
            for p in pow2:
                if val+p in s:
                    res.append(val)
                    res.append(val+p)
                    break
            if res:
                break

    if not res:
        res.append(a[0])

    print(len(res))
    print(*res)


if __name__ == '__main__':
    main()
