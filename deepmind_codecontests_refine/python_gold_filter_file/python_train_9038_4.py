def examA():
    N = I()
    T = LI()
    A = LI()
    S = [-1]*N
    S[0] = T[0]; S[-1]=A[-1]
    ans = 1
    for i in range(1,N):
        if T[i]==T[i-1]:
            continue
        S[i] = T[i]
    flag = -1
    for i in range(N):
        if S[i]==A[i]:
            flag = i
            break
    if not (A[flag]==A[0] and A[flag]==T[-1]):
        print(0)
        return
    for i in range(N-1)[::-1]:
        if A[i]==A[i+1]:
            continue
        if S[i]==-1:
            S[i] = A[i]
        else:
            S[i] = max(S[i],A[i])
    #print(S)
    P = []
    pindex = []
    for i in range(N):
        if S[i]==-1:
            continue
        P.append(S[i])
        pindex.append(i)
    flag_U = True
    for i in range(len(P)-1):
        if P[i+1]>P[i]:
            if not flag_U:
                print(0)
                return
        elif P[i+1]<P[i]:
            flag_U = False
    ans = 1
    p = -1
    for i in range(N):
        if S[i]==-1:
            cur = min(P[p + 1], P[p])
            ans *= cur
            ans %= mod
        else:
            p += 1

    print(ans)
    return

def examB():
    T = I()
    A = LI()

    ans = 0
    print(ans)
    return

def examC():
    def dfs(n,s,edges,visited):
        cost = BC[s]
        now = []
        for i in edges[s]:
            if visited[i]:
                continue
            visited[i] = True
            cur,visited = dfs(n,i,edges,visited)
            now.append((cur, i))
        now.sort()
        for c,i in now:
            cost += c-now[0][0]
            children[i] = c-now[0][0]
        return cost,visited

    N, M = LI()
    V = [[]for _ in range(N)]
    for i in range(N-1):
        p = I()
        V[i+1].append(p)
        V[p].append(i+1)
    children = [-1]*N
    BC = defaultdict(int)
    for i in range(M):
        b, c = LI()
        BC[b] = c
    visited = [False]*N
    visited[0] = True
    ans = dfs(N,0,V,visited)
    print(children)
    print(ans)
    return

def examD():
    N, K = LI()
    W = [LI()for _ in range(N)]
    l = 0; r = 10**20
    while(r-l>1):
        now = (l+r)//2
        cur = 0
        for i in range(N):
            if now>=W[i][0]:
                cur += ((now-W[i][0])//W[i][1]+1)
        if cur<K:
            l = now
        else:
            r = now
    ans = r
    print(ans)
    return

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
    examD()

"""

"""