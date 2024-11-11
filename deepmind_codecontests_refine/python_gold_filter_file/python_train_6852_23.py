#!/usr/bin/env python3
import sys
try:
    from typing import List
except ImportError:
    pass


class BIT:
    def __init__(self, n: int):
        self.tr = [0] * (n + 1)

    def add(self, n: int, v: int):
        while n < len(self.tr):
            self.tr[n] += v
            n += n & -n

    def cumsum(self, n: int):
        ans = 0
        while n > 0:
            ans += self.tr[n]
            n -= n & -n
        return ans


def solve(N: int, a: "List[int]"):

    def f(m):
        s = [0] * (N + 1)
        for i, ai in enumerate(a):
            s[i + 1] = s[i] + (-1 if ai < m else 1)
        ms = min(s)
        b = BIT(max(s) - ms + 1)
        t = 0
        for si in s:
            t += b.cumsum(si - ms + 1)
            b.add(si - ms + 1, 1)
        return t >= -(-(N * (N + 1) // 2) // 2)

    lb = 0
    rb = max(a) + 1
    while lb + 1 < rb:
        m = (lb + rb) // 2
        if f(m):
            lb = m
        else:
            rb = m

    print(lb)


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    a = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, a)


if __name__ == '__main__':
    main()
