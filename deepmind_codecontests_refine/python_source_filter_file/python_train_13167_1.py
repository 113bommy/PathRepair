import math,string,itertools,fractions,heapq,collections,re,array,bisect
from itertools import chain, dropwhile, permutations, combinations
from collections import defaultdict

def VI(): return list(map(int,input().split()))
def I(): return int(input())
def LIST(n,m=None): return [0]*n if m is None else [[0]*m for i in range(n)]
def ELIST(n): return [[] for i in range(n)]
def MI(n=None,m=None): # input matrix of integers
    if n is None: n,m = VI()
    arr = LIST(n)
    for i in range(n): arr[i] = VI()
    return arr
def MS(n=None,m=None): # input matrix of strings
    if n is None: n,m = VI()
    arr = LIST(n)
    for i in range(n): arr[i] = input()
    return arr
def MIT(n=None,m=None): # input transposed matrix/array of integers
    if n is None: n,m = VI()
    # a = MI(n,m)
    arr = LIST(m,n)
    for i in range(n):
        v = VI()
        for j in range(m):
            arr[j][i] = v[j]
    # for i,l in enumerate(a):
    #     for j,x in enumerate(l):
    #         arr[j][i] = x
    return arr




def run2(n,m,u,v,w,x):
    # correct, but time limit exceeded.
    g = ELIST(n+1) # list of vertices; Adjacency list
    for i in range(m):
        g[u[i]].append((v[i],w[i],i+1))
        g[v[i]].append((u[i],w[i],i+1))
    # index priority queue with deque and priorities
    pq = []
    marked = [False] * (n+1)
    pq.append((0,0,x,0))
    sg = []
    wmax = -w[-1] # to fix the issue that start doesn't have edge weight
    while len(pq)!=0:
        wi,lw,i,ei = heapq.heappop(pq)
        if not marked[i]:
            marked[i] = True
            sg.append(ei)
            wmax += w[ei-1]
            #print(i,wi,ei, wmax)
            for j,wj,ej in g[i]:
                if not marked[j]:
                    heapq.heappush(pq, (wi+wj,wj,j,ej))
    sg = sg[1:]
    print(wmax)
    for i in sg:
        print(i,end=" ")
    print()
def main2(info=0):
    n,m = VI()
    u,v,w = MIT(m,3)
    x = I()
    run(n,m,u,v,w,x)


def run(n,m,g,x):
    pq = [(0,0,x,0)]
    marked = [False] * (n+1)
    sg = []
    wtot = 0
    while len(pq)!=0:
        wi,lw,i,ei = heapq.heappop(pq)
        if not marked[i]:
            marked[i] = True
            sg.append(str(ei))
            wtot += lw
            for j,wj,ej in g[i]:
                if not marked[j]:
                    heapq.heappush(pq, (wi+wj,wj,j,ej))
    print(wtot)
    print(" ".join(sg))
def main(info=0):
    n,m = VI()
    g = ELIST(n+1)
    for i in range(m):
        u,v,w = VI()
        g[u].append((v,w,i+1))
        g[v].append((u,w,i+1))
    x = I()
    run(n,m,g,x)

if __name__ == "__main__":
    main()
