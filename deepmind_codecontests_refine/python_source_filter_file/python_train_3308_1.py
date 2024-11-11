# coding: utf-8
# Your code here!
import sys
read = sys.stdin.read
readline = sys.stdin.readline

#n,k,*a = map(int,read().split())

n, = map(int,readline().split())
vw = [[0,0]]+[list(map(int,readline().split())) for _ in range(n)]

def merge(av,aw,bv,bw):
    la,lb = len(aw),len(bw)
    rv = [0]*(la+lb)
    rw = [0]*(la+lb)
    ia = ib = 0
    for i in range(la+lb):
        if ib==lb or (ia < la and aw[ia] < bw[ib]):
            rv[i] = av[ia]
            rw[i] = aw[ia]
            ia += 1
        else:
            rv[i] = bv[ib]
            rw[i] = bw[ib]
            ib += 1
    return rv,rw

A = 9
N = min(1<<A,n+1)
memov = [[] for _ in range(N)]
memow = [[] for _ in range(N)]

memov[0] = [0]
memow[0] = [0]

#from itertools import acumulate
for i in range(1,N):
    v,w = vw[i]
    m2v = [v+v1 for v1 in memov[i>>1]]
    m2w = [w+w1 for w1 in memow[i>>1]]
    memov[i],memow[i] = merge(memov[i>>1],memow[i>>1],m2v,m2w)

    #memov[i] = list(accumulate(memov[i],max))
    for j in range(1,len(memov[i])):
        memov[i][j] = max(memov[i][j-1],memov[i][j])
    
def solve(lstv,lstw,dv,dw,l):
    ans = 0
    idx = len(lstw)-1
    #print(lstv,lstw,dv,dw,l)
    for v,w in zip(dv,dw):
        while idx >= 0 and lstw[idx] + w > l:
            idx -= 1
        if idx >= 0 and v+lstv[idx] > ans:
            ans = v+lstv[idx]
    print(ans)        
 
 

q, = map(int,readline().split())
for _ in range(q):
    u,l = map(int,readline().split())

    dv = [0]
    dw = [0]
    while u >= N:
        v,w = vw[u]
        m2v = [v+v1 for v1 in dv]
        m2w = [w+w1 for w1 in dw]
        dv,dw = merge(dv,dw,m2v,m2w)
        u >>= 1
    
    #for j in range(1,len(dv)):
    #    dv[j] = max(dv[j-1],dv[j])
    
    solve(memov[u],memow[u],dv,dw,l)

#print(memov)
#print(memow)

