#!/usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
import sys, random, itertools, math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
sqrt = math.sqrt
def LI(): return list(map(int, input().split()))
def LF(): return list(map(float, input().split()))
def LI_(): return list(map(lambda x: int(x)-1, input().split()))
def II(): return int(input())
def IF(): return float(input())
def LS(): return list(map(list, input().split()))
def S(): return list(input().rstrip())
def IR(n): return [II() for _ in range(n)]
def LIR(n): return [LI() for _ in range(n)]
def FR(n): return [IF() for _ in range(n)]
def LFR(n): return [LI() for _ in range(n)]
def LIR_(n): return [LI_() for _ in range(n)]
def SR(n): return [S() for _ in range(n)]
def LSR(n): return [LS() for _ in range(n)]
mod = 1000000007
inf = float('INF')
import time

#A
def A():
    s = S()
    t = S()
    ans = 0
    for i in range(3):
        if s[i] == t[i]:
            ans += 1
    print(ans)
    return

#B
def B():
    a, b = LI()
    ans = 0
    b -= 1
    while b > 0:
        b -= a - 1
        ans += 1
    print(ans)

    return

#C
def C():
    n = II()
    h = LI()
    i = 0
    ans = 0
    while i < n:
        down = i+1
        while down < n:
            if h[down - 1] >= h[down]:
                down += 1
            else:
                break
        ans = max(ans, down - i - 1)
        i = down
    print(ans)
    return

#D
def D():
    n = II()
    print(n * (n - 1) // 2)
    return

#E
def E():
    start = time.time()
    n = II()
    a = LIR_(n)
    ans = 0
    tern = [0] * n
    while 1:
        ans += 1
        f = True
        c = defaultdict(int)
        for i in range(n):
            if c[i]:
                continue
            if tern[i] == n - 1:
                continue
            rival = a[i][tern[i]]
            if c[rival]:
                continue
            if tern[rival] == n - 1:
                continue
            if a[rival][tern[rival]] == i:
                c[i] += 1
                c[rival] += 1
                tern[rival] += 1
                tern[i] += 1
                f = False
        if time.time() - start >= 1:
            print(n * (n - 1) // 2)
            return
        if f:
            if tern == [n - 1] * n:
                print(ans-1)
                return
            else:
                print(-1)
                return
    return

# F
# 解説AC
# 偏角に対する類題はこれ
# https://atcoder.jp/contests/abc033/tasks/abc033_d
# しかし重要なのはそこではなくある頂点に対して
# そこに近づくために使用するベクトルはどれかというのを
# ある頂点へのベクトルとのなす角が90°以内のベクトルであれば
# 問答無用で追加可能という点
# 2次元を1次元に落とし込むときに必要な考え方！
# なぜ思いつけない！
# 偏角でソートして全探索でも可 
def F():
    n = II()
    lis = []
    for _ in range(n):
        x, y = LI()
        arg = math.atan2(y, x) / math.pi * 180
        lis.append((arg, x, y))
        lis.append((arg + 360, x, y))
    lis.sort()
    i = 0
    k = 0
    tmpx = 0
    tmpy = 0
    ans = 0
    while i < n:
        arg, x, y = lis[i]
        while k < n:
            karg, kx, ky = lis[k]
            if karg <= arg + 180:
                tmpx += kx
                tmpy += ky
                ans = max(ans, sqrt(tmpx ** 2 + tmpy ** 2))
                k += 1
            else:
                tmpx -= x
                tmpy -= y
                ans = max(ans, sqrt(tmpx ** 2 + tmpy ** 2))
                break
        i += 1
    print(ans)
    return

#Solve
if __name__ == '__main__':
    F()
