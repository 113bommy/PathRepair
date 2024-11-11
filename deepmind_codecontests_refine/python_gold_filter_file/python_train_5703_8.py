# -*- coding: utf-8 -*-
import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
X = []
Y = []
P = []
for _ in range(N):
    x,y,p = map(int,readline().split())
    X.append(x)
    Y.append(y)
    P.append(p)

DX = [[0]*N for _ in range(1<<N)]
DY = [[0]*N for _ in range(1<<N)]

for i,x in enumerate(X):
    for k in range(1<<N):
        d = abs(x)
        for j,xx in enumerate(X):
            if (k>>j)&1:
                d = min(d,abs(x-xx))
        DX[k][i] = d * P[i]    
for i,y in enumerate(Y):
    for k in range(1<<N):
        d = abs(y)
        for j,yy in enumerate(Y):
            if (k>>j)&1:
                d = min(d,abs(y-yy))
        DY[k][i] = d * P[i]                                                

PC = [0]*(1<<N)
for i in range(1<<N):
    PC[i] = PC[i//2] + 1 if i % 2 else PC[i//2]

RA = []
for i in range(1<<N):
    t = []
    for j in range(N):
        if i>>j & 1:
            t.append(j)
    RA.append(t)

INF = 10**31
mm = (1 << N) - 1
ANS = [INF]*(N+1)

for i in range(1<<N):
    m = i^mm
    j = m
    dxi = DX[i]
    pci = PC[i]
    while True:
        dyj = DY[j]
        ans = 0
        for k in RA[i^j^mm]:
            ans += min(dxi[k],dyj[k])
        pc = pci + PC[j]
        if ans < ANS[pc]:
            ANS[pc] = ans       
        if j == 0:
            break
        j = m & (j - 1)
print(*ANS,sep = '\n')