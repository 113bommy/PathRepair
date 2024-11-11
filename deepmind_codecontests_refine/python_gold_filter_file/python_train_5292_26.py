#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(N: int, A: "List[int]", B: "List[int]"):

    ma = INF
    mb = INF
    for a, b in zip(A, B):
        if a > b:
            if mb > b:
                ma = a
                mb = b
    if ma == INF:
        print(0)
    else:
        print(sum(A)-mb)

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    A = [int()] * (N)  # type: "List[int]"
    B = [int()] * (N)  # type: "List[int]"
    for i in range(N):
        A[i] = int(next(tokens))
        B[i] = int(next(tokens))
    solve(N, A, B)


if __name__ == '__main__':
    main()
