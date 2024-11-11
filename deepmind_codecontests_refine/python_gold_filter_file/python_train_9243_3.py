def examA():
    N = DI()/dec(7)
    ans = N
    print(N)
    return

def examB():
    # 0許容(i += 1)
    class Bit():
        def __init__(self, n):
            self.size = n
            self.tree = [0] * (n + 1)
            return

        def sum(self, i):
            i += 1
            s = 0
            while i > 0:
                s += self.tree[i]
                i -= i & -i
            return s

        def add(self, i, x=1):
            i += 1
            # i==0 はだめ => 全部+1するとか
            while i <= self.size:
                self.tree[i] += x
                i += i & -i
            return

        def search(self, x):
            # 二分探索。和がx以上となる最小のインデックス(>= 1)を返す
            # maspyさんの参考　よくわかってない
            i = 0
            s = 0
            step = 1 << ((self.size).bit_length() - 1)
            while step:
                if i + step <= self.size and s + self.tree[i + step] < x:
                    i += step
                    s += self.tree[i]
                step >>= 1
            return i

        def debug(self, k):
            return [self.sum(i) for i in range(k)]

        def inversion(self, A=[3, 10, 1, 8, 5]):
            res = 0
            for i, p in enumerate(A):
                self.add(p, 1)
                res += i + 1 - self.sum(p)
            return res
    N = I()
    S = SI()
    r = deque()
    g = deque()
    b = deque()
    bottom = Bit(3*N)
    top = Bit(3*N)
    mid = []
    for i,s in enumerate(S):
        if s == "R":
            if g and b:
                A = sorted([i, g.pop(), b.pop()])
                bottom.add(A[0])
                top.add(A[2])
                mid.append(A[1])
            else:
                r.appendleft(i)
        elif s=="G":
            if r and b:
                A = sorted([i, r.pop(), b.pop()])
                bottom.add(A[0])
                top.add(A[2])
                mid.append(A[1])
            else:
                g.appendleft(i)
        elif s=="B":
            if r and g:
                A = sorted([i, r.pop(), g.pop()])
                bottom.add(A[0])
                top.add(A[2])
                mid.append(A[1])
            else:
                b.appendleft(i)

    ans = 1
    for i in range(N):
        m = mid[i]
        cur = (bottom.sum(m)-i)*(i+1-top.sum(m))
        #print(cur)
        ans *= cur
        ans %= mod2
    for i in range(1,N+1):
        ans *= i
        ans %= mod2
    print(ans)
    return

def examC():
    ans = 0
    print(ans)
    return

def examD():
    ans = 0
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

from decimal import getcontext,Decimal as dec
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
_ep = dec("0.000000000001")
alphabet = [chr(ord('a') + i) for i in range(26)]
alphabet_convert = {chr(ord('a') + i): i for i in range(26)}

getcontext().prec = 28

sys.setrecursionlimit(10**7)

if __name__ == '__main__':
    examB()

"""
142
12 9 1445 0 1
asd dfg hj o o
aidn
"""