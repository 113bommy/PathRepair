#!/usr/bin/env python3
#%% for atcoder uniittest use
import sys
input= lambda: sys.stdin.readline().rstrip()
def pin(type=int):return map(type,input().split())
def tupin(t=int):return tuple(pin(t))
#%%code

def resolve():
    N,M,P=pin()
    edge=[]#0-index
    for i in range(M):
        a,b,c=pin()
        edge.append((a-1,b-1,P-c))
    #print(edge)
    
    #Bellman–Ford algorithm?
    inf = float("inf")
    ans=[inf]*N#0-index
    ans[0]=0

    for i in range(N*2):
        for j in range(M):
            t,f,p=edge[j]
            ans[f]=min(ans[f],ans[t]+p)
            if  ans[f]>ans[t]+p:
                ans[f]=0-inf
    #    print(ans)
        if i==N:
            temp=ans[-1]
        if i==N*2-1:
            if ans[-1]<temp:
                ans[-1]=0-inf
    t=(0-ans[-1])
    



    if t==inf:s=-1
    elif t<0:s=0
    else:s=t
    print(s)
#%%submit!
resolve()