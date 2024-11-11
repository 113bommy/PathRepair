#import numpy as np
import math
import collections
import bisect


def main():
    a, b, c, d = map(int, input().split())

    dp0 = [[1 for i in range(d + 1)] for j in range(c + 1)]
    dp1 = [[0 for i in range(d + 1)] for j in range(c + 1)]
    for i in range(c + 1):
        for j in range(d + 1):
            if j < b or i < a:
                dp0[i][j] = 0
                dp1[i][j] = 0
    for i in range(a, c + 1):
        for j in range(b, d + 1):
            # print(i, j, dp[i][j])
            if a == i and b == j:
                continue
            dp0[i][j] = ((i * dp0[i][j - 1]) % 998244353 + dp1[i][j - 1]) % 998244353
            dp1[i][j] = (j * (dp0[i - 1][j] + dp1[i - 1][j]) % 998244353) % 998244353

    print((dp0[c][d] + dp1[c][d]) % 998244353)


if __name__ == '__main__':
    main()
