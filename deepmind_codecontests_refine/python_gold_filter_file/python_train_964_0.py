def examA():
    T = I()
    ans = []
    for _ in range(T):
        N = I()
        B = LI()
        if sum(B)==0:
            print("NO")
            continue
        print("YES")
        B.sort()
        for i in range(N):
            cur = []
            now = 0
            for j in range(N):
                now += B[i-j]
                if now==0:
                    break
                cur.append(B[i-j])
            if len(cur)==N:
                print(" ".join(map(str,cur)))
                break
    return

def examB():
    T = I()
    ans = []
    for _ in range(T):
        N, K = LI()
        S = SI()
        L = []
        W = 0
        WW = 0
        cur = 0
        l = -inf
        flag_W = False
        for s in S:
            if s=="W":
                WW += 1
                if flag_W:
                    cur += 2
                    continue
                if l>0:
                    L.append(l)
                l = 0
                flag_W = True
                W += 1
                cur += 1
            else:
                flag_W = False
                l += 1
        #print("途中")
        #print(cur,l)


        #print(L)
        if WW==0:
            cur = max(0,2*K-1)
        elif K==0:
            pass
        elif N-WW<=K:
            cur = 2*N-1
        else:
            L.sort()
            for i in range(len(L)):
                a = L[i]
                if a<=K:
                    cur += 1 + 2*a
                    K -= a
                else:
                    cur += 2*K
                    K = 0
                    break
            if K>0:
                cur += 2*K

        ans.append(min(2*N-1,cur))
    for v in ans:
        print(v)
    return

def examC():
    T = I()
    ans = []
    for _ in range(T):
        cur = 0
        ans.append(cur)
    for v in ans:
        print(v)
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
import sys,bisect,heapq
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

sys.setrecursionlimit(2*10**5)

if __name__ == '__main__':
    examB()

"""
1
6 1
LLLWWL

"""