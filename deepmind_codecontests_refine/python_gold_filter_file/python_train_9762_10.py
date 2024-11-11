# coding: utf-8
import sys

# from operator import itemgetter
sysread = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
printout = sys.stdout.write
sprint = sys.stdout.flush
# from heapq import heappop, heappush
# from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
import math
# from itertools import product, accumulate, combinations, product
# import bisect
# import numpy as np
# from copy import deepcopy
#from collections import deque
# from decimal import Decimal
# from numba import jit

INF = 1 << 50
EPS = 1e-8
mod = 998244353


def intread():
    return int(sysread())
def mapline(t=int):
    return map(t, sysread().split())
def mapread(t=int):
    return map(t, read().split())

class segtree:
    '''init_val : 1-indexed (init_val[0] = self.bin[1])'''
    def __init__(self, n, init = 0, init_val=None):
        self.n = n
        self.init = init
        self.k = math.ceil(math.log2(n))
        self.add_val = 1 << self.k

        self.bins = [self.init] * (1 << (self.k + 1))
        if init_val != None:
            self.update_set(init_val)
        self.caliculate()

    def __getitem__(self, idx):  # return idx-value
        return self.bins[idx + self.add_val]

    def update_set(self, vals):
        for idx, i in enumerate(range(self.add_val, self.add_val * 2)):
            if len(vals) > idx:
                self.bins[i] = vals[idx]
            else:continue

    def compare(self, l, r):
        return min(l ,r)

    def caliculate(self):
        k = self.k
        while k:
            for i in range(1<<k, 1<<(k+1)):
                if not i%2:
                    self.bins[i//2] = self.compare(self.bins[i], self.bins[i+1])
                else:continue
            k -= 1

    def update(self, idx, val, by=True):
        '''idx : 0-started index'''
        k = (1<<self.k) + idx
        if by:
            self.bins[k] += val
        else:
            self.bins[k] = val
        while k>1:
            self.bins[k // 2] = self.compare(self.bins[k // 2 * 2], self.bins[k // 2 * 2 + 1])
            k = k//2


    def eval(self, l, r):
        if l == r:
            return self.bins[l + self.add_val]
        ret = self.init
        l = (1 << self.k) + l
        r = (1 << self.k) + r
        #print(l, r)
        while True:
            #print(l, r)
            if r - l == 1:
                ret = self.compare(ret, self.bins[l])
                ret = self.compare(ret, self.bins[r])
                break
            elif l == r:
                ret = self.compare(ret, self.bins[l])
                break
            else:
                done = False
                if l % 2:
                    ret = self.compare(ret, self.bins[l])
                    l += 1
                    done = True
                if not r % 2:
                    ret = self.compare(ret, self.bins[r])
                    r -= 1
                    done = True
                if not done:
                    l = l // 2
                    r = r // 2
        #print(ret)
        return ret


def run():
    N, Q = mapline()
    X = segtree(N+1, init = INF)
    Y = segtree(N+1, init = INF)
    sub = 0
    for _ in range(Q):
        q, x = mapline()
        x -= 1
        if q == 1:
            v = X.eval(x, N-2)
            if v == INF:
                sub += N-2
                if Y[N-2] > x:
                    Y.update(N-2, x,by = False)
            else:
                sub += v-1
                if Y[v] > x:
                    Y.update(v, x, by = False)
        else:
            v = Y.eval(x, N - 2)
            if v == INF:
                sub += N - 2
                if X[N - 2] > x:
                    X.update(N - 2, x, by=False)
            else:
                sub += v - 1
                if X[v] > x:
                    X.update(v, x, by=False)
    print((N-2) ** 2 - sub)






if __name__ == "__main__":
    run()
