from heapq import heappush, heappop
from collections import deque,defaultdict,Counter
import itertools
from itertools import permutations,combinations
import sys
import bisect
import string
import math
import time
import random
def I():
    return int(input())
def MI():
    return map(int,input().split())
def LI():
    return [int(i) for i in input().split()]
def LI_():
    return [int(i)-1 for i in input().split()]
def show(*inp,end='\n'):
    if show_flg:
        print(*inp,end=end)
YN=['Yes','No']
mo=10**9+7
inf=float('inf')
ts=time.time()
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
show_flg=False
#show_flg=True

V,E=MI()
g=[[] for _ in range(V+1)]
for i in range(E):
    u,v,d=MI()
    g[u].append((v,d))
    g[v].append((u,d))

T=I()
order=[0]*T
for i in range(T):
    n=I()
    if n>0:
        oid,v=MI()
        order[i]=v

def rand_move():
    move=[]
    state=0 # on vertex
    cur=1
    
    for t in range(T//2):
        print(-1)
    for t in range(T//2,T*10):
        if state==0:
            r=len(g[cur])
            dest,dist=g[cur][random.randint(0,r-1)]
            state=1
            move.append(dest)
            dist-=1
            if dist==0:
                state=0
                cur=dest
        else:
            move.append(dest)
            dist-=1
            if dist==0:
                state=0
                cur=dest
    return move

for i in range(1,V+1):
    show(i,g[i])
move=rand_move()
for i in move:
    print(i)
