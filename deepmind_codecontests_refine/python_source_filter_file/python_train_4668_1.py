def examA():
    N = I()
    ans = 0
    print(ans)
    return

# 参考 https://atcoder.jp/contests/agc021/submissions/8392122
def examB():
    def norm2(vec):
        return math.sqrt(vec[0] ** 2 + vec[1] ** 2)
    # any 2 points must have different position.
    def ConvexHull(point_list):
        pos2idx = {point_list[i]: i for i in range(len(point_list))}
        y_val = defaultdict(list)
        x_list = sorted(list(set([p[0] for p in point_list])))
        for x, y in point_list:
            y_val[x].append(y)

        upper = [(x_list[0], max(y_val[x_list[0]]))]
        lower = [(x_list[0], min(y_val[x_list[0]]))]
        prev = float('inf')
        for xi in x_list[1:]:
            x0, y0 = upper[-1]
            x1, y1 = xi, max(y_val[xi])
            if (y1 - y0) / (x1 - x0) < prev:
                upper.append((x1, y1))
                prev = (y1 - y0) / (x1 - x0)
            else:
                while True:
                    x0, y0 = upper[-1]
                    if len(upper) == 1:
                        upper.append((x1, y1))
                        break
                    x00, y00 = upper[-2]
                    if (y1 - y0) / (x1 - x0) > (y1 - y00) / (x1 - x00):
                        upper.pop()
                    else:
                        prev = (y1 - y0) / (x1 - x0)
                        upper.append((x1, y1))
                        break

        prev = -float('inf')
        for xi in x_list[1:]:
            x0, y0 = lower[-1]
            x1, y1 = xi, min(y_val[xi])
            if (y1 - y0) / (x1 - x0) > prev:
                lower.append((x1, y1))
                prev = (y1 - y0) / (x1 - x0)
            else:
                while True:
                    x0, y0 = lower[-1]
                    if len(lower) == 1:
                        lower.append((x1, y1))
                        break
                    x00, y00 = lower[-2]
                    if (y1 - y0) / (x1 - x0) < (y1 - y00) / (x1 - x00):
                        lower.pop()
                    else:
                        prev = (y1 - y0) / (x1 - x0)
                        lower.append((x1, y1))
                        break

        # return upper, lower
        # return [pos2idx[xy] for xy in upper], [pos2idx[xy] for xy in lower]

        upper_idx, lower_idx = [pos2idx[xy] for xy in upper], [pos2idx[xy] for xy in lower]
        if upper_idx[-1] == lower_idx[-1]:
            upper_idx.pop()
        CH_idx = upper_idx
        CH_idx.extend(reversed(lower_idx))
        if CH_idx[0] == CH_idx[-1] and len(CH_idx) > 1:
            CH_idx.pop()
        return CH_idx

    N = I()
    P = [[]for _ in range(N)]
    D = defaultdict(int)
    for i in range(N):
        x,y = LI()
        P[i] = (x,y)
        D[(x,y)] = i
    C = ConvexHull(P)
    ans = [0]*N
    if len(C)==2:
        for c in C:
            ans[c] = 0.5
        for v in ans:
            print(v)
        return
    #print(C)
    for i,c in enumerate(C):
        s, t, u = C[i - 1], C[i], C[(i + 1) % len(C)]
        x0, y0 = P[s]
        x1, y1 = P[t]
        x2, y2 = P[u]
        vec0 = (y0 - y1, x1 - x0)
        vec1 = (y1 - y2, x2 - x1)
        ans[t] =  math.acos((vec0[0] * vec1[0] + vec0[1] * vec1[1]) / (norm2(vec0) * norm2(vec1))) / (2 * math.pi)
    for v in ans:
        print(v)
    return

def examC():
    ans = 0
    print(ans)
    return

def examD():
    S = SI()
    N = len(S)
    K = I()
    if K>100:
        K = 100
    dp = [[[0]*(K+1) for _ in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(K+1):
            dp[i][i][j] = 1
    for i in range(2,N+1):
        for k in range(K+1):
            for l,r in enumerate(range(i-1,N)):
                if S[l]==S[r]:
                    dp[l][r][k] = dp[l+1][r-1][k] + 2
                else:
                    if k>0:
                        dp[l][r][k] = max(dp[l+1][r][k],dp[l][r-1][k],dp[l+1][r-1][k-1]+2)
                    else:
                        dp[l][r][k] = max(dp[l + 1][r][k], dp[l][r - 1][k])
    ans = max(dp[0][-1])
    #print(dp)
    print(ans)
    return

def examE():
    ans = 0
    print(ans)
    return

def examF():
    ans = 0
    print(ans)
    return

from decimal import Decimal as dec
import sys,bisect,itertools,heapq,math,random
from copy import deepcopy
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
def I(): return int(input())
def LI(): return list(map(int,sys.stdin.readline().split()))
def DI(): return dec(input())
def LDI(): return list(map(dec,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet,_ep
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
_ep = 10**(-12)
alphabet = [chr(ord('a') + i) for i in range(26)]

sys.setrecursionlimit(10**7)

if __name__ == '__main__':
    examD()

"""
142
12 9 1445 0 1
asd dfg hj o o
aidn
"""