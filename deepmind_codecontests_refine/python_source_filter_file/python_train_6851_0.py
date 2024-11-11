#!/usr/bin/env python3
import sys

INF = float('inf')

def solve(n: int, A: "List[int]"):
    dp = [[INF] * 5  for _ in range(n + 1)]
    dp[0][0] = 0
    dp[0][1] = 0
    dp[0][2] = 0
    for i in range(n):
        for j in range(5):
            if j == 0 or j == 4:
                extra = A[i]
            elif j == 1 or j == 3:
                extra = A[i] % 2 if A[i] > 1 else 2
            else:
                extra = (A[i] + 1) % 2
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + extra)
            for k in range(j + 1, 5):
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + extra)
        #print(dp[i + 1])
    print(min(dp[n]))
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    L = int(next(tokens))  # type: int
    A = [ int(next(tokens)) for _ in range(L) ]  # type: "List[int]"
    solve(L, A)

if __name__ == '__main__':
    main()
