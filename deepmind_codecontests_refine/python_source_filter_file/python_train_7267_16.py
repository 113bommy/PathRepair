# @author 

import sys

class JSushi:
    def solve(self):
        n = int(input())
        a = [int(_) for _ in input().split()]

        u, v, w = a.count(1), a.count(2), a.count(3)

        dp = [[[0] * (n + 2) for _ in range(n + 2)] for _ in range(n + 2)]
        for k in range(n + 1):
            for j in range(n + 1):
                for i in range(n + 1 - j - k):
                    if i == j == k == 0:
                        continue
                    s = i + j + k
                    x = 0
                    x += dp[i][j + 1][k - 1] * k
                    x += dp[i + 1][j - 1][k] * j
                    x += dp[i - 1][j][k] * i
                    x += n
                    x /= s
                    dp[i][j][k] = x

        print(dp[u][v][w])


solver = JSushi()
input = sys.stdin.readline

solver.solve()
