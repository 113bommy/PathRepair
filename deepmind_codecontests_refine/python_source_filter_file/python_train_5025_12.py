from sys import stdin
from collections import deque
def NC_Dij(lis,start):

    ret = [float("inf")] * len(lis)
    ret[start] = 0
    
    q = deque([start])
    plis = [i for i in range(len(lis))]

    while len(q) > 0:
        now = q.popleft()

        for nex in lis[now]:

            if ret[nex] > ret[now] + 1:
                ret[nex] = ret[now] + 1
                plis[nex] = now
                q.append(nex)

    return ret,plis

tt = int(stdin.readline())

for loop in range(tt):

    n,a,b,da,db = map(int,stdin.readline().split())
    N = n
    a -= 1
    b -= 1
    lis = [ [] for i in range(n)]

    for i in range(n-1):
        u,v = map(int,stdin.readline().split())
        u -= 1
        v -= 1
        lis[u].append(v)
        lis[v].append(u)

    if 2*da > db:
        print ("Alice")
        continue

    fa,tmp = NC_Dij(lis,a)
    if fa[b] <= da:
        print ("Alice")
        continue

    mv = 0
    for i in range(N):
        if fa[i] > fa[mv]:
            mv = i

    fv,tmp = NC_Dij(lis,mv)
    if max(fv) <= 2*da:
        print ("Alice")
    else:
        print ("Bob")
    
