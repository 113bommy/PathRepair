# @author 

import sys

class SDigitSum:
    def solve(self):
        MOD = 10 ** 9 + 7

        k = input().strip()
        d = int(input())

        s = len(k)
        dp = [[0] * d for _ in range(s + 1)]
        dp[0][0] = 1
        for i in range(10):
            dp[1][i % d] += 1

        pre = [[0] * (d + 1) for _ in range(s + 1)]
        for i in range(d):
            pre[1][i] = pre[1][i - 1] + dp[1][i]
        for l in range(2, s):
            # cur is sum(dp[l - 1][(-lm + r) % d] for lm in range(1, 10)
            cur = sum(dp[l - 1][(-lm + 0) % d] for lm in range(1, 10))
            for r in range(d):
                # dp[l][r] = (dp[l - 1][r] + sum(dp[l - 1][(-lm + r) % d] for lm in range(1, 10))) % MOD
                dp[l][r] = (dp[l - 1][r] + cur) % MOD
                cur -= dp[l - 1][(r - 9) % d]
                cur += dp[l - 1][(r + 1 - 1) % d]


        ans = dp[s - 1][0]
        done = 0
        for i in range(s):
            lm = int(k[i])
            ans = (ans + sum(dp[s - 1 - i][(-done - (lm - v)) % d] for v in range(1, lm + 1 * (i != 0)))) % MOD
            done += lm

        if (sum(int(x) for x in k)) % d == 0:
            ans = (ans + 1) % MOD

        print((ans - 1) % MOD)

solver = SDigitSum()
input = sys.stdin.readline

solver.solve()
