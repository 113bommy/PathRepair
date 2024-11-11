import sys
input = sys.stdin.readline
mod = 998244353

def sub(a, b):
    return (a % mod + mod - b % mod) % mod

n, = list(map(int, input().split()))
t = 1
dd = [t]
for _ in range(n):
    t=2*t%mod
    dd.append(t)

def pow2(b):
    return dd[b]

class SegTree:
    def __init__(self, init_val, n, ide_ele, seg_func):
        self.segfunc = seg_func
        self.num = 2**(n-1).bit_length()
        self.ide_ele = ide_ele
        self.seg=[self.ide_ele]*2*self.num
        for i in range(n):
            self.seg[i+self.num-1]=init_val[i]    
        for i in range(self.num-2,-1,-1) :
            self.seg[i]=self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
        
    def update(self, k, x):
        k += self.num-1
        self.seg[k] = x
        while k+1:
            k = (k-1)//2
            self.seg[k] = self.segfunc(self.seg[k*2+1],self.seg[k*2+2])
        
    def query(self, p, q):
        if q<=p:
            return self.ide_ele
        p += self.num-1
        q += self.num-2
        res=self.ide_ele
        while q-p>1:
            if p&1 == 0:
                res = self.segfunc(res,self.seg[p])
            if q&1 == 1:
                res = self.segfunc(res,self.seg[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = self.segfunc(res,self.seg[p])
        else:
            res = self.segfunc(self.segfunc(res,self.seg[p]),self.seg[q])
        return res

def mm(a, b, c, d, n):
    return sub(pow2(b+c) + pow2(c+d) + pow2(d+a) + pow2(a+b),
                pow2(a) + pow2(b) + pow2(c) + pow2(d))

xs, ys = [], []
for _ in range(n):
    x, y = list(map(int, input().split()))
    xs.append(x)
    ys.append(y)

ini = sorted(list(range(n)), key=lambda x:xs[x])
for i, yi in enumerate(sorted(list(range(n)), key=lambda x:ys[x])):
    ys[yi] = i 
nys = [ys[i] for i in ini]

ss1 = SegTree([0] * n, n, 0, lambda x,y:x+y)
r = 0
for i, y in enumerate(nys):
    ss1.update(y, 1)
    d = ss1.query(0, y)
    c = i - d
    b = (n-1) - y - c
    a = (n-1) - b - c - d
    r = (r + mm(a, b, c, d, n)) % mod

print(sub((pow2(n) * n) % mod, (r+n)%mod))
