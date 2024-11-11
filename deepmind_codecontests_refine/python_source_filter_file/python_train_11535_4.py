# -*- coding: utf-8 -*-
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
write = sys.stdout.write
# template


def resolve():
    ofs = 80
    h, w = map(int, readline().split())
    A = [list(map(int, readline().split())) for i in range(h)]
    B = [list(map(int, readline().split())) for i in range(h)]
    dp = [[0]*w for _ in range(h)]
    x = abs(A[0][0]-B[0][0])
    dp[0][0] |= ((1 << (ofs+x)) | (1 << (ofs-x)))

    for i in range(h):
        for j in range(w):
            x = abs(A[i][j]-B[i][j])
            t = 0
            if(i-1 >= 0):
                t |= dp[i-1][j]
            if(j-1 >= 0):
                t |= dp[i][j-1]
            dp[i][j] |= ((t << x) | (t >> x))

    for i, s in enumerate(bin(dp[-1][-1])[-ofs-1:]):
        if(s == '1'):
            print(i)
            return


if __name__ == "__main__":
    INF = float("inf")
    MOD = 10**9+7
    resolve()
