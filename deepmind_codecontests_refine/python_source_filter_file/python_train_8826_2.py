#!/usr/bin/env python3
import sys
from collections import Counter
from itertools import accumulate
from collections import defaultdict
INF = float("inf")


def solve(N: int, A: "List[int]"):
    c = Counter(A)
    d = Counter(c.values())
    d = tuple(accumulate([d[i] for i in range(N, -1, -1)])[::-1])
    S = [0]*(N+1)
    for i in range(1, N+1):
        S[i] = S[i-1] + d[i]

    def isOK(y):
        return S[y] < K*y

    def binary_search(x):
        ng = -1
        ok = len(x)+1

        while abs(ok - ng) > 1:
            mid = (ok + ng)//2
            if isOK(mid):
                ok = mid
            else:
                ng = mid
        return ng, ok

    for K in range(1, N+1):
        ng, ok = binary_search(range(N))
        print(ng)

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    A = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, A)


if __name__ == '__main__':
    main()
