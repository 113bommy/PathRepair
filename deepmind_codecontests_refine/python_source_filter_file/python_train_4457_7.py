#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS():return [list(x) for x in sys.stdin.readline().split()]
def S(): return list(sys.stdin.readline())[:-1]
def IR(n):
    return [I() for i in range(n)]
def LIR(n):
    return [LI() for i in range(n)]
def SR(n):
    return [S() for i in range(n)]
def LSR(n):
    return [LS() for i in range(n)]

sys.setrecursionlimit(1000000)
mod = 1000000007

#A
def A():
    n = I()
    print(3*n**2)
    return

#B
def B():
    n,d = LI()
    f = [1]*(n+2*d+2)
    ans = 0
    for i in range(n):
        if f[i]:
            for j in range(i,i+2*d+1):
                f[j] = 0
            ans += 1
    print(ans)
    return

#C
def C():
    n = I()
    a = IR(n)
    mi = max(a)
    if a.count(mi) > 1:
        for i in range(n):
            print(mi)
    else:
        b = [a[i] for i in range(n)]
        b.sort()
        b = b[::-1]
        for i in range(n):
            if mi != a[i]:
                print(mi)
            else:
                print(b[1])

    return

#D
def D():
    n = I()
    a = LI()
    b = [0]*(n+1)
    for i in range(1,n+1)[::-1]:
        j = 2*i
        k = 0
        while j <= n:
            k ^= b[j]
            j += i
        if a[i-1]^k:
            b[i] = 1
    ans = []
    for i in range(n+1):
        if b[i]:
            ans.append(i)
    print(len(ans))
    if ans:
        print(*ans)
    return

#E
def E():
    n = I()
    a = IR(n)
    mi = []
    ans = 0
    for i in range(n):
        j = bisect.bisect_right(mi,-a[i])
        if j == len(mi):
            mi.append(-a[i])
        else:
            mi[j] = -a[i]
    print(len(mi))
    return

#F 箱根駅伝DP
def F():
    n,K = LI()
    dp = [[[0]*(K+100) for j in range(n+1)] for i in range(n+1)] #dp[i][j][k] : i段目、j個保留の時にスコアがkとなるパターン数(保留した点の数だけ、スコアは加算されていく,保留点が段をまたいでスコアが増えていくイメージ)
    dp[0][0][0] = 1
    for i in range(n):
        for j in range(i+1):
            for k in range(K+1):
                #パターン1 : i+1段目で両方結ぶ
                nj = j
                dp[i+1][nj][k+2*nj] += dp[i][j][k]
                dp[i+1][nj][k+2*nj] %= mod
                #パターン2 : i+1段目で両方結ばない
                nj = j+1
                dp[i+1][nj][k+2*nj] += dp[i][j][k]
                dp[i+1][nj][k+2*nj] %= mod
                #パターン3 : i+1段目で片側ともう片方の保留点を結ぶ
                nj = j
                x = j*2 #結ぶ相方の選び方((右or左)*(保留点の数))
                dp[i+1][nj][k+2*nj] += dp[i][j][k]*x
                dp[i+1][nj][k+2*nj] %= mod
                #パターン4 : i+1段目で両側ともう片方の保留点を結ぶ
                nj = j-1
                x = j*j #結ぶ相方の選び方(左側の保留点*右側の保留点)
                dp[i+1][nj][k+2*nj] += dp[i][j][k]*x
                dp[i+1][nj][k+2*nj] %= mod
    print(dp[n][0][K])
    return

#Solve
if __name__ == "__main__":
    F()
