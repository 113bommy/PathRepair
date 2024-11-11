import math
#import numpy as np
import queue
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)

def main():
    s = input()
    t = input()
    ns = len(s)+1
    nt = len(t)+1
    ssa = [0]*ns
    ssb = [0]*ns
    sta = [0]*nt
    stb = [0]*nt
    for i,si in enumerate(s):
        if si == "A":
            da = 1
            db = 0
        else:
            da = 0
            db = 1
        ssa[i+1] = ssa[i]+da
        ssb[i+1] = ssb[i]+db
    for i,ti in enumerate(t):
        if ti == "A":
            da = 1
            db = 0
        else:
            da = 0
            db = 1
        sta[i+1] = sta[i]+da
        stb[i+1] = stb[i]+db

    q = int(ipt())
    for _ in range(q):
        a,b,c,d = map(int,ipt().split())
        da = ssa[b]-ssa[a-1]-sta[d]+sta[c-1]
        db = ssb[b]-ssb[a-1]-stb[d]+stb[c-1]
        if (da-db)%3 == 0:
            print("YES")
        else:
            print("NO")

    return

if __name__ == '__main__':
    main()
