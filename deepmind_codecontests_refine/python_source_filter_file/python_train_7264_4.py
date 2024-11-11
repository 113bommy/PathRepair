def examA():
    S = SI()
    if S=="AAA" or S=="BBB":
        print("No")
    else:
        print("Yes")
    return

def examB():
    N, A, B = LI()
    loop = N//(A+B)
    ans = loop*A + min(A,N%(A+B))
    print(ans)
    return

def examC():
    A, B = LI()
    ans = -1
    for i in range(1,20000):
        if i*8//100==A:
            if i*10//100==B:
                ans = i
                break
    print(ans)
    return

def examD():
    S = SI()
    Q = I()
    rev = 0
    L = ""; R = ""
    for _ in range(Q):
        q = LSI()
        if q[0]=="1":
            rev += 1
        else:
            c = int(q[1])
            if (c+rev)%2==1:
                L += q[2]
            else:
                R += q[2]
    ans = ""
    if rev%2==0:
        ans = L[::-1] + S + R
    else:
        ans = R[::-1] + S[::-1] + L
    print(ans)
    return

def examE():
    N, P = LI()
    S = SI()
    A = [0]*(N+1)
    cur = 0
    if P==5:
        ans = 0
        for i in range(N):
            if int(S[N-1-i])%5==0:
                ans += N-i
        print(ans)
        return
    elif P==2:
        ans = 0
        for i in range(N):
            if int(S[N-1-i])%2==0:
                ans += N-i
        print(ans)
        return

    for i in range(N):
        s = int(S[N-1-i])
        cur += s*pow(10,i,P)
        A[i+1] = cur%P
    D = [0]*P
    for a in A:
        D[a] += 1
    ans = 0
    #print(A)
    for d in D:
        ans += d*(d-1)//2

    print(ans)
    return

def examF():
    def dfs(n, s):
        #input()
        #print(n,s)
        cur = 1
        can = sum(X[s])
        for i in range(s,n):
            if X[i][0]>=can:
                V[s] = cur
                return cur, i
            if i==n-1:
                return cur,i
            now, visited = dfs(n, i+1)
            cur += now
        V[s] = cur
        return cur, n
    N = I()
    X = [LI()for _ in range(N)]
    X.sort()
    V = [[]for _ in range(N)]
    neg = 0
    ans = dfs(N,0)
    print(V)

    print(ans)
    return

def examF2():
    N = I()
    X = [LI()for _ in range(N)]
    N += 1
    X.sort()
    parent = [-1] * N
    #print(X)

    stack = [(inf,-1)]
    for i,(x,d) in enumerate(X):
        d += x
        # x座標近いやつからチェック
        # 届かないやつ排除
        while(stack[-1][0]<=x):
            stack.pop()
        parent[i] = stack[-1][1]
        stack.append((d,i))

    #print(parent)
    dp = [1]*N
    ans = 1
    for i in range(N-1)[::-1]:
        p = parent[i]
        if p==-1:
            ans *= dp[i]+1
            ans %= mod
            continue
        dp[p] *= dp[i]+1
        dp[p] %= mod

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

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    examF2()

"""

"""