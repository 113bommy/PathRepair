import math,string,itertools,fractions,heapq,collections,re,array,bisect,copy
from itertools import chain, dropwhile, permutations, combinations
from collections import defaultdict, deque
import operator as op

# Guide:
#   1. construct complex data types while reading (e.g. graph adj list)
#   2. avoid any non-necessary time/memory usage
#   3. avoid templates and write more from scratch
#   4. switch to "flat" implementations

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
    a = MI(n,m)
    arr = LIST(m,n)
    for i,l in enumerate(a):
        for j,x in enumerate(l):
            arr[j][i] = x
    return arr


# BFS is probably overkill, as one can reach it by brute force (below)
def bfs(l, sgn, r, best,par=0):
    if len(r) ==1:
        # if par==1:
        #     return max(best, sgn(l,r[0]))
        return max(best, sgn(l,r[0]))
    if sng == op.add:
        if par==0:
            return max(bfs(op.add(l,r[1]),r[2],r[3:],best,par),
                       bfs(op.add(l,r[1]),r[2],r[3:],best,par+1))
        if r[1] == op.add:
            return bfs(op.add(l,r[1]),r[2],r[3:],best)
        else:
            return max()
def run_bfs(s):
    x = list(s)
    lst = [int(v) if i%2==0 else op.add if v=='+' else op.mul for i,v in enumerate(x)]
    # d = [int(i) for i in x[::2]]
    # g = x[1::2]
    b = bfs(lst[0], lst[1], lst[2:], 0)


def run2(s):
    best = eval(s)
    n = len(s)
    if n<=3:
        print(eval(s))
        return
    x = list(s)
    for i in range(1,n-2,2):
        if s[i] == '+' and (i==1 or s[i-2]=='*'):
            l=i-1
            for j in range(i+2,n,2):
                if s[j] == '*':
                    exp = s[:l]+ '(' + s[l:j]+')'+s[j:]
                    best = max(best, eval(exp))
            best = max(best, eval(s[:l]+ '(' + s[l:]+')'))
    print(best)

def run3(s):
    best = eval(s)
    n = len(s)
    if n<=3:
        print(eval(s))
        return
    m = [i for i,v in enumerate(s) if v=='*']
    l = [0,]
    r = [n,]
    for x in m:
        if x<n-2 and s[x+2]=='+':
            l.append(x+1)
        if x>2 and s[x-2]=='+':
            r.append(x)
    for v in l:
        for w in r:
            if v>=w: continue
            exp = s[:v]+ '(' + s[v:w]+')'+s[w:]
            best = max(best, eval(exp))
    print(best)

def run(s):
    best = eval(s)
    n = len(s)
    if n<=3:
        print(best)
        return
    for i in range(1,n-2,2):
        if s[i] == '+' and (i==1 or s[i-2]=='*'):
            for j in range(i+2,n,2):
                if s[j] == '*':
                    best = max(best, eval(s[:i-1]+ '(' + s[i-1:j]+')'+s[j:]))
            best = max(best, eval(s[:i-1]+ '(' + s[i-1:]+')'))
    print(best)


def main(info=0):
    s = input()
    run(s)



if __name__ == "__main__":
    main()
