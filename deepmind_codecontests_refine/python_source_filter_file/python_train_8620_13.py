# @author 

import sys

class OMatching:
    def solve(self):
        from collections import defaultdict

        def numberOfSetBits(i):
            i = i - ((i >> 1) & 0x55555555)
            i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
            return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24

        MOD = 10 ** 9 + 7

        n = int(input())
        a = []
        for i in range(n):
            a.append([int(_) for _ in input().split()])


        dp = [[0] * ((1 << n) + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        by_1 = defaultdict(list)
        for j in range(1 << n):
            by_1[numberOfSetBits(j)].append(j)
        for j in range(1 << n):
            by_1[bin(j).count('1')].append(j)

        for i in range(1, n + 1):
            for j in by_1[i - 1]:
                for k in range(n):
                    if (j >> k) & 1 or a[i - 1][k] == 0:
                        continue
                    dp[i][j | (1 << k)] += dp[i - 1][j]
                    dp[i][j | (1 << k)] %= MOD

        # [print(item) for item in dp]

        print(sum(dp[n]))

solver = OMatching()
input = sys.stdin.readline

solver.solve()
