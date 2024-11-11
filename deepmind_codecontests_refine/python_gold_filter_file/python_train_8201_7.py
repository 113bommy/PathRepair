def examA():
    W = {'Sunny':'Cloudy','Cloudy':'Rainy','Rainy':'Sunny'}
    S = SI()
    ans = W[S]
    print(ans)
    return

def examB():
    R = {"R","U","D"}
    L = {"L","U","D"}
    S = SI()
    ans = "Yes"
    for i,s in enumerate(S):
        if i%2==0 and s in R:
            continue
        if i%2==1 and s in L:
            continue
        ans = "No"
        break
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
    # https://tjkendev.github.io/procon-library/python/string/z-algorithm.html
    def z_algo(S):
        N = len(S)
        A = [0] * N
        i = 1; j = 0
        A[0] = l = len(S)
        while i < l:
            while i + j < l and S[j] == S[i + j]:
                j += 1
            if not j:
                i += 1
                continue
            A[i] = j
            k = 1
            while l - i > k < j - A[k]:
                A[i + k] = A[k]
                k += 1
            i += k; j -= k
        return A
    N = I()
    S = SI()
    ans = 0
    for i in range(N):
        Z = z_algo(S[i:])
        for k,n in enumerate(Z[1:]):
            cur = min(k+1,n)
            ans = max(ans,cur)
    print(ans)
    return

def examF():
    # 参考 prd_xxxさん
    def gauss_jordan(bs):
        rank = 0
        pivot_cols = []
        for col in reversed(range(61)):
            pivot = -1
            for i, row in enumerate(bs[rank:]):
                if row & (1 << col):
                    pivot = rank + i
                    break
            if pivot < 0: continue
            pivot_cols.append(col)
            bs[pivot], bs[rank] = bs[rank], bs[pivot]
            for i, row in enumerate(bs):
                if i != rank and row & (1 << col):
                    bs[i] ^= bs[rank]
            rank += 1
        return bs
    N = I()
    A = LI()
    bitlen = max(A).bit_length()

    even = {}
    for i in range(N):
        for j in range(bitlen):
            if A[i]&(1<<j):
                if j in even:
                    even[j] ^= 1
                else:
                    even[j] = 0
    #print(even)
    A2 = [0]*N
    for i in range(N):
        for j in range(bitlen):
            if j in even and even[j]:
                A2[i] += A[i]&(1<<j)
    #print(A2)
    ans = 0
    for key,e in even.items():
        if e==0:
            ans += 1<<key
    L = gauss_jordan(A2); L.sort(reverse=True)
    #print(ans)
    #print(L)
    now = L[0]
    for i in range(1,N):
        l = L[i]
        if l==0:
            break
        n = l.bit_length()-1
        #print(n,now)
        if now&(1<<n)>0:
            continue
        now ^= l
    #print(now)
    ans += now*2
    print(ans)
    return

import traceback
import sys,copy,bisect,itertools,heapq,math,random
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet,_ep
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
_ep = 10**(-12)
alphabet = [chr(ord('a') + i) for i in range(26)]

if __name__ == '__main__':
    examF()

"""

"""