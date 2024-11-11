import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify, nlargest
from copy import deepcopy
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_1(): return list(map(lambda x:int(x)-1, sys.stdin.readline().split()))
def inps(): return sys.stdin.readline()
def inpsl(x): tmp = sys.stdin.readline(); return list(tmp[:x])
def err(x): print(x); exit()

#####segfunc#####
def segfunc(x,y):
    return x+y
#################
class LazySegTree_RAQ:
    """
    init(init_val, ide_ele): 配列init_valで初期化 O(N)
    add(l, r, x): 区間[l, r)にxを加算 O(logN)
    query(l, r): 区間[l, r)をsegfuncしたものを返す O(logN)
    """
    def __init__(self, init_val, segfunc, ide_ele):
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        self.lazy = [0] * 2 * self.num
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])
    def gindex(self, l, r):
        l += self.num
        r += self.num
        lm = l >> (l & -l).bit_length()
        rm = r >> (r & -r).bit_length()
        while r > l:
            if l <= lm:
                yield l
            if r <= rm:
                yield r
            r >>= 1
            l >>= 1
        while l:
            yield l
            l >>= 1
    def propagates(self, *ids):
        for i in reversed(ids):
            v = self.lazy[i]
            if v==0:
                continue
            self.lazy[i] = 0
            self.lazy[2 * i] += v
            self.lazy[2 * i + 1] += v
            self.tree[2 * i] += v
            self.tree[2 * i + 1] += v
    def add(self, l, r, x):
        *ids, = self.gindex(l, r)
        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                self.lazy[l] += x
                self.tree[l] += x
                l += 1
            if r & 1:
                self.lazy[r - 1] += x
                self.tree[r - 1] += x
            r >>= 1
            l >>= 1
        for i in ids:
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1]) + self.lazy[i]
    def query(self, l, r):
        *ids, = self.gindex(l, r)
        self.propagates(*ids)
        res = self.ide_ele
        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                res = self.segfunc(res, self.tree[r - 1])
            l >>= 1
            r >>= 1
        return res

n,k = inpl()
segs = [] 
for i in range(n):
    l,r = inpl()
    segs.append((l,r,i+1))
segs.sort(key=lambda x:x[0])
# segs.sort(key=lambda x:abs(x[0]-x[1]))
# print(segs)
st = LazySegTree_RAQ([0]*200010,max,-1)
res = []
for l,r,i in segs:
    if st.query(l,r+1)<k:
        st.add(l,r+1,1)
    else: res.append(i)
print(len(res))
print(*res)