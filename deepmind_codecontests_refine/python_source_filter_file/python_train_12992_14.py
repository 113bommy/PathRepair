def Z_algorithm(s):
    N = len(s)
    Z_alg = [0]*N

    Z_alg[0] = N
    i = 1
    j = 0
    while i < N:
        while i+j < N and s[j] == s[i+j]:
            j += 1
        Z_alg[i] = j
        if j == 0:
            i += 1
            continue
        k = 1
        while i+k < N and k + Z_alg[k]<j:
            Z_alg[i+k] = Z_alg[k]
            k += 1
        i += k
        j -= k
    return Z_alg

import sys
from fractions import gcd

sys.setrecursionlimit(1500000)

s=input()
t=input()
n=len(s)
m=len(t)
if n!=m:
    s=(m//n+1)*s
    data=Z_algorithm(t+'?'+s)
    bool=[False for i in range(0,n)]
    for i in range(m+1,m+1+n):
        if data[i]==m:
            bool[i-m-1]=True

    g=gcd(n,m)
    for i in range(0,g):
        for j in range(0,n//g):
            if not bool[i+j*g]:
                break
        else:
            print(-1)
            exit()

    ans=[[] for i in range(0,g)]
    for i in range(0,g):
        ans[i].append(bool[i])
        x=(i+m)%n
        while x!=i:
            ans[i].append(bool[x])
            x=(x+m)%n

    from itertools import groupby
    answer=0
    for i in range(0,g):
        a=groupby(ans[i])
        d=[]
        for key,group in a:
            g=len(list(group))
            d.append([key,g])
        if d:
            if d[0][0] and d[-1][0]:
                d[-1][1]+=d[0][1]
        for j in range(len(d)):
            if d[j][0]:
                answer=max(answer,d[j][1])
    print(answer)


else:
    s=2*s
    data=Z_algorithm(t+'?'+s)
    for i in range(m+1,n+m+1):
        if data[i]==m:
            print(-1)
            break
    else:
        print(0)