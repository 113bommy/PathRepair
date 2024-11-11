import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools
from collections import deque

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

DR = [1, -1, 0, 0]
DC = [0, 0, 1, -1]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

def query_cumsum2d(s, x1, y1, x2, y2):
    # [x1, x2) × [y1, y2)
    if x2 < x1:
        x1, x2 = x2, x1
    if y2 < y1:
        y1, y2 = y2, y1
    return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]

def main():
    N, K = LI()
    G = [[0 for _ in range(2*K)] for __ in range(2*K)]
    cumsum2d = [[0 for _ in range(2*K + 1)] for __ in range(2*K + 1)]
    xyc = []
    for _ in range(N):
        x, y, c =  LS()
        x = int(x)
        y = int(y)
        if c == 'W':
            x += K
        x = x % (2 * K)
        y = y % (2 * K)
        G[x][y] += 1
        xyc.append((x, y, c))
    for x in range(2*K):
        for y in range(2*K):
            cumsum2d[x+1][y+1] = (
                cumsum2d[x+1][y]
                + cumsum2d[x][y+1]
                - cumsum2d[x][y]
                + G[x][y]
            )
    ans = 0
    # import pdb
    # print('cum: ')
    # for row in cumsum2d:
    #     print(row)
    # print()
    # print('g: ')
    # for row in G:
    #     print(row)
    for x in range(K):
        for y in range(K):
            # pdb.set_trace()
            cnt = (
                  query_cumsum2d(cumsum2d, 0, 0, x, y)
                + query_cumsum2d(cumsum2d, x, y, x+K, y+K)
                + query_cumsum2d(cumsum2d, x+K, 0, 2 * K, y)
                + query_cumsum2d(cumsum2d, 0, y+K, x, 2 * K)
                + query_cumsum2d(cumsum2d, 2*K, 2*K, x+K, y+K)
            )

            ans = max(ans, cnt)
    print(ans)



main()

