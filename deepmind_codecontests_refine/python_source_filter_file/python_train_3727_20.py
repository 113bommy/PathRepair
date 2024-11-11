#!/usr/bin/env python3
import sys
from heapq import heapify, heappush, heappop


def solve(N: int, A: "List[int]", B: "List[int]"):

    lh = []
    for i, b in enumerate(B):
        heappush(lh, [-b, i])

    count = 0
    while lh:
        b, i = heappop(lh)
        a, b = A[i], B[i]
        c = B[i-1]+B[(i+1) % N]
        if b > a and b >= c:
            d, m = divmod(b-a, c)
            if d == 0:
                break
            count += d
            B[i] = a+m
            if m != 0:
                heappush(lh, [-B[i], i])

    if A != B:
        count = -1

    print(count)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    A = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    B = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, A, B)


if __name__ == '__main__':
    main()
