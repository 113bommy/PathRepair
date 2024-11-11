import sys
input = sys.stdin.readline

class SegmentTree(object):
 
    def __init__(self, init_array, seg_func=min, seg_func_null=10 ** 9 + 7):
 
        self.seg_func = seg_func
        self.seg_func_null = seg_func_null
        self.n = 1
        while self.n < len(init_array):
            self.n *= 2
        self.dat = [0] * (2 * self.n - 1)
        for i in range(len(init_array)):
            self.dat[self.n - 1 + i] = init_array[i]
        for i in range(self.n - 2, -1, -1):
            self.dat[i] = self.seg_func(self.dat[2 * i + 1], self.dat[2 * i + 2])
 
    def update(self, k, a):
        k += self.n - 1
        self.dat[k] = a
        while k > 0:
            k = (k - 1) // 2
            self.dat[k] = self.seg_func(self.dat[k * 2 + 1], self.dat[k * 2 + 2])
 
    def query(self, p, q):
        # [p, q)
        if q <= p:
            return self.seg_func_null
 
        p += self.n - 1
        q += self.n - 2
        res = self.seg_func_null
 
        while q - p > 1:
            if p & 1 == 0:
                res = self.seg_func(res, self.dat[p])
            if q & 1 == 1:
                res = self.seg_func(res, self.dat[q])
                q -= 1
            p = p // 2
            q = (q-1) // 2
        if p == q:
            res = self.seg_func(res, self.dat[p])
        else:
            res = self.seg_func(self.seg_func(res, self.dat[p]), self.dat[q])
 
        return res
 
N = int(input())
X = [0]*N
D = [0]*N
XD = [None]*N
for i in range(N):
    X, D = (int(i) for i in input().split())
    XD[i] = (X, D)
XD.sort()

import bisect
seg = SegmentTree(list(range(N)), max, -1)
L = list(range(N))

for i in range(N)[::-1]:
    x, d = XD[i]
    b = bisect.bisect_left(XD, (x+d-0.5, d))-1
    m = seg.query(i,b+1)
    seg.update(i,m)
    L[i] = m

ans = [0]*N
res = 1
for i in range(N)[::-1]:
    if L[i] == i:
        ans[i] = res
        res *= 2
    else:
        ans[i] = ans[L[i]]
        res += ans[i]
    res %= 998244353
print(res)
