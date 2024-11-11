from sys import stdin
import sys
#import numpy as np
import collections
from functools import cmp_to_key
import heapq

##  input functions for me
def rsa(sep = ''):
    if sep == '' :
        return input().split() 
    else: return input().split(sep)
def rip(sep = ''):
    if sep == '' :
        return map(int, input().split()) 
    else: return map(int, input().split(sep))
def ria(sep = ''): 
    return list(rip(sep))
def ri(): return int(input())
def rd(): return float(input())
def rs(): return input()
##

compo = []
cs = []
N = 0
M = 0
A = None
B = None
E = None

def main():
    global compo,cs,N,M,A,B,E
    N, M = rip()
    A = [0] * M
    B = [0] * M
    for i in range(M):
        A[i], B[i] = rip()
        A[i] -= 1
        B[i] -= 1
    
    E = [[] for i in range(N)]
    for i in range(M):
        E[A[i]].append(B[i])
    
    compo = [-1] * N

    def dfs(cmp, route, hs):
        global compo,cs,N,M,A,B,E
        if(len(cs) > 0) : return
        now = route[len(route) - 1]
        for nxt in E[now]:
            if compo[nxt] == -1:
                compo[nxt] = cmp
                route.append(nxt)
                hs.add(nxt)
                dfs(cmp, route, hs)
                hs.remove(nxt)
                route.pop(-1)
            elif compo[nxt] == cmp:
                if nxt in hs:
                    cs = route[route.index(nxt):]
                return
            else:
                return


    cs = []
    c = 0
    for i in range(N):
        if(compo[i] != -1): continue
        c += 1
        a = []
        hs = set()
        a.append(i)
        hs.add(i)
        compo[i] = c
        dfs(c, a, hs)

    if len(cs) == 0:
        print(-1)
        sys.exit(0)
    
    l = cs
    while(True):
        di = dict()
        for i in range(len(l)):
            di[l[i]] = l[(i + 1) % len(l)]
        edx = -1
        for i in range(M):
            if A[i] in di and B[i] in di:
                if di[A[i]] != B[i]:
                    edx = i
                    break
        
        if edx == -1:
            print(len(l))
            print("\n".join([str(n + 1) for n in l]))
            sys.exit(0)
        
        di[A[edx]] = B[edx]
        nl = [A[edx], B[edx]]
        while True:
            nxt = di[nl[-1]]
            if nxt != nl[0]:
                nl.append(nxt)
            else:
                break
        l = nl

if __name__ == "__main__":
    main()
