def examC():
    ABC = LI(); ABC.sort()
    judge = ABC[2]*2-ABC[1]-ABC[0]
    ans = judge//2 + (judge%2)*2
    print(ans)
    return

def examD():
    def judge(A,B):
        if A==B:
            return (A-1)*2
        cur = int((A*B)**0.5)
        if cur**2==A*B:
            return (cur-1)*2 -1
        if cur*(cur+1)>=A*B:
            return cur*2 -2
        else:
            return cur*2-1
    Q = I()
    ans = []
    for _ in range(Q):
        a,b = LI()
        ans.append(judge(a,b))
    for v in ans:
        print(v)
    return

def examE():
    N = I()
    ans = 0; minc = inf
    for i in range(N):
        a, b = LI()
        ans +=a
        if a>b:
            minc = min(minc,b)
    ans =max(ans-minc,0)
    print(ans)
    return

import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,inf
mod = 10**9 + 7
inf = 10**18

if __name__ == '__main__':
    examE()
