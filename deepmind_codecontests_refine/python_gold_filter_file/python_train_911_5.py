import sys
from collections import deque
readline = sys.stdin.readline

N = int(readline())
P = list(map(int, readline().split()))

geta = N+2
G = [0]*(geta*geta)

for v in range(-1-(-N//2), -1, -1):
    l = v+1
    r = N-v
    for i in range(geta):
        G[i*geta+l] = v
        G[i*geta+r] = v
        G[l*geta+i] = v
        G[r*geta+i] = v

for i in range(geta):
    G[i*geta] = -1
    G[i*geta + geta-1] = -1
    G[i] = -1
    G[geta*(geta-1)+i] = -1

Pn = []

for p in P:
    a, b = divmod(p-1, N)
    Pn.append((1+a)*geta+1+b)

DIREC = (1, -1, geta, -geta)
ans = 0
used = [False]*(geta*geta)
for p in Pn:
    ans += G[p]
    res = G[p]
    for d in DIREC:
        res = min(res, G[p+d])
    if G[p] != res:
        G[p] = res
        Q = [p]
        while Q:
            vn = Q.pop()
            for d in DIREC:
                vf = vn + d
                if not used[vf]:
                    if G[vf] > G[vn] + 1:
                        G[vf] = G[vn] + 1
                        Q.append(vf)
                else:
                    if G[vf] > G[vn]:
                        G[vf] = G[vn]
                        Q.append(vf)
                    
    used[p] = True
print(ans)