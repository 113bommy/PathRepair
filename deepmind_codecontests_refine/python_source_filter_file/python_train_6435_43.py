#!/usr/bin/env python3
import sys
INF = float("inf")

MOD = 1000000007  # type: int


def array(*args, initial=0):
    def forstr(N):
        return "[{} for _ in range("+str(N)+")]"

    a = args[-1]
    ans = eval(forstr(a).format(initial))
    if len(args) == 1:
        return ans
    else:
        return array(*args[:-1], initial=ans)


def solve(K: int, D: int):
    K = str(K)
    N = len(str(K))
    DP = array(N+1, 2, D, initial=0)
    DP[0][0][0] = 1
    for i in range(N):
        for j in range(2):
            lim = 9 if j else int(K[i])
            for k in range(D):
                for d in range(lim+1):
                    DP[i+1][j or d < lim][(k+d) % D] += DP[i][j][k]
                    DP[i+1][j or d < lim][(k+d) % D] %= MOD
    print(DP[N][0][0]+DP[N][1][0]-1)

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    K = int(next(tokens))  # type: int
    D = int(next(tokens))  # type: int
    solve(K, D)


if __name__ == '__main__':
    main()
