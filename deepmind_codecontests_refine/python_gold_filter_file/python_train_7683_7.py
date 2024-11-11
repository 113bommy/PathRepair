#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**8)
INF = float("inf")


def bit(n, k):
    return (n >> k) & 1


def solve(N: int, a: "List[List[int]]"):
    DP = [0]*(1 << N)
    flag = [False]*(1 << N)

    def rec(S):
        if flag[S]:
            return DP[S]
        flag[S] = True

        ans = 0
        for i in range(N):
            for j in range(i+1, N):
                if bit(S, i) and bit(S, j):
                    ans += a[i][j]
        T = (S-1) & S
        while T > 0:
            ans = max(ans, rec(T)+rec(S ^ T))
            T = (T-1) & S
        DP[S] = ans
        return ans
    print(rec((1 << N)-1))
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    a = [[int(next(tokens)) for _ in range(N)]
         for _ in range(N)]  # type: "List[List[int]]"
    solve(N, a)


if __name__ == '__main__':
    main()
