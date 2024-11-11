'''
研究室PCでの解答
'''
import math
#import numpy as np
import queue
import bisect
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)
mod = 10**9+7
dir = [(-1,0),(1,0),(0,-1),(0,1)]
alp = "abcdefghijklmnopqrstuvwxyz"

class Binary_Indexed_Tree:
    #Binary_Indexed_Tree
    #A1 ... AnのBIT(1-indexed)
    def __init__(self,n):
        self.N = n
        self.BIT = [0]*(n+1)
        self.l2 = 2**(len(format(n,'b'))-1)

    #A1 ~ Aiまでの和 O(logN)
    def query(self,idx):
        res_sum = 0
        while idx > 0:
            res_sum += self.BIT[idx]
            idx -= idx&(-idx)
        return res_sum

    #Ai += x O(logN)
    def update(self,idx,x):
        while idx <= self.N:
            self.BIT[idx] += x
            idx += idx&(-idx)
        return

    def lower_bound(self,w):
        if w <= 0:
            return 0
        x = 0
        k = self.l2
        while k > 0:
            if x+k <= self.N and self.BIT[x+k] < w:
                w -= self.BIT[x+k]
                x += k
            k //= 2
        return x+1

    def upper_bound(self,w):
        x = 0
        k = self.l2
        while k > 0:
            if x+k <= self.N and self.BIT[x+k] <= w:
                w -= self.BIT[x+k]
                x += k
            k //= 2
        return x

def main():
    n = int(ipt())
    ans = 0
    a = [int(i) for i in ipt().split()]
    pl = [-1]*(n+1)
    for i,ai in enumerate(a):
        pl[ai] = i+1

    bt = Binary_Indexed_Tree(n)

    for i in range(1,n+1):
        pi = pl[i]
        bi = bt.query(pl[i])
        lb = bt.lower_bound(bi)
        ub = bt.upper_bound(bi)
        ans += (pi-lb)*(ub-pi+1)*i
        bt.update(pi,1)

    print(ans)

    return None

if __name__ == '__main__':
    main()
