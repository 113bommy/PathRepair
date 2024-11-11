import sys,math,copy,queue,itertools,bisect,collections
from heapq import *
sys.setrecursionlimit(10**7)
LI = lambda : [int(x) for x in sys.stdin.readline().split()]
NI = lambda : int(sys.stdin.readline())
INF = 10**18
MOD = 10**9 + 7
DD = ((1,0),(-1,0),(0,1),(0,-1))

n,a,b,c = LI()
z = [a,b,c]
s = [sys.stdin.readline().rstrip() for _ in range(n)]
ans = []
for i in range(n):
    x = s[i]
    p = -1
    if x == 'AB': j=0;k=1;l=2
    elif x == 'AC': j=0;k=2;l=1
    elif x == 'BC': j=1;k=2;l=0
    if z[j] > z[k]:
        z[j] -= 1; z[k] += 1
        p = k
    else:
        z[j] += 1; z[k] -= 1
        p = j
    if (z[j] == 0 or z[k] == 0) and z[l] == 0:
        if i < n-1:
            y = s[i+1]
            if x == 'AB': j1=0;k1=1;l1=3
            elif x == 'AC': j1=0;k1=2;l1=1
            elif x == 'BC': j1=1;k1=2;l1=0
            if z[j1] == 0 and z[k1] == 0:
                if z[j] == 0:
                    z[j] += 2; z[k] -= 2
                    p = j
                else:
                    z[j] -= 2; z[k] += 2
                    p = k
    if min(z) < 0:
        print('No')
        exit(0)
    if p==0:ans.append('A')
    elif p==1:ans.append('B')
    else: ans.append('C')
print('Yes')
print(*ans,sep='\n')




