def examC():
    N = I()
    d = defaultdict(int)
    for i in range(N):
        curD = defaultdict(int)
        S = SI()
        for s in S:
            curD[s]+=1
        if i==0:
            d = curD
            continue
        for s in alphabet:
            d[s] = min(d[s],curD[s])
    d = sorted(d.items())
    ans = ""
    for key,i in d:
        ans +=key*i
    print(ans)
    return

def examD():
    N, M = LI()
    X = LI(); Y = LI()
    distX = [0]*N; distY = [0]*M
    for i in range(N-1):
        distX[i+1] = X[i+1]-X[i]
    for i in range(M-1):
        distY[i+1] = Y[i+1]-Y[i]
    numX = [0]*N; numY = [0]*M
    for i in range(N):
        numX[i] = i*(N-i)
    for i in range(M):
        numY[i] = i*(M-i)
    LX = 0; LY = 0
    for i in range(N):
        LX += distX[i]*numX[i]
        LX %= mod
    for i in range(M):
        LY += distY[i]*numY[i]
        LY %= mod
#    print(numX,distX); print(numY,distY)
    ans = (LX*LY) % mod
    print(ans)
    return

def examE():
    S = SI(); T = SI()
    numaS = [0]*(len(S)+1)
    numaT = [0]*(len(T)+1)
    for i,s in enumerate(S):
        numaS[i+1] = numaS[i]
        if s=="A":
            numaS[i+1] +=1
    for i,s in enumerate(T):
        numaT[i+1] = numaT[i]
        if s=="A":
            numaT[i+1] +=1
#    print(numaS); print(numaT)
    Q = I()
    ans = ["YES"]*Q
    for i in range(Q):
        a,b,c,d = LI()
        curaS = numaS[b] - numaS[a-1]
        curbS = (b-a)-curaS+1
        curaT = numaT[d] - numaT[c-1]
        curbT = (d-c)-curaT+1
#        print(curaS,curbS,curaT,curbT)
        if (curaS%3+(curaS+curbS)%3)%3 != (curaT%3+(curaT+curbT)%3)%3:
#            if (curbS % 3 + (curaS + curbS) % 3) % 3 != (curbT % 3 + (curaT + curbT) % 3) % 3:
            ans[i]="NO"
    for v in ans:
        print(v)
    return

import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
alphabet = [chr(ord('a') + i) for i in range(26)]

if __name__ == '__main__':
    examE()
