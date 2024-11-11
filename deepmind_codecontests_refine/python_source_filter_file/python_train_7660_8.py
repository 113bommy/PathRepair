import math,string,itertools,collections,re,fractions,array,copy
import bisect
import heapq
from itertools import chain, dropwhile, permutations, combinations
from collections import deque, defaultdict, OrderedDict, namedtuple, Counter, ChainMap


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

def main(info=0):
    n = I()
    a = VI()
    z = [i for i in range(n) if a[i]==0]
    i=0
    j=0
    x = [j for j in range(z[0], -1, -1)]
    print(z)
    for i in range(1, len(z)):
        d = z[i]-z[i-1]
        x += [j for j in range(1, d//2)]
        if d%2 == 1 and d>2: x += [d//2, ]
        x += [j for j in range(d//2, -1, -1)]
    x += [j for j in range(1, n-z[-1])]
    print(" ".join(str(j) for j in x))



if __name__ == "__main__":
    main()
