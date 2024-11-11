class SegmentTree():
    def segfunc(self, x, y):
        return max(x, y)
    
    def __init__(self, a): #a:リスト
        n = len(a)
        self.ide_ele = 0 #単位元
        self.num = 2**((n-1).bit_length()) #num:n以上の最小の2のべき乗
        self.seg = [self.ide_ele]*2*self.num
        
        #set_val
        for i in range(n):
            self.seg[i+self.num-1] = a[i]
        #built
        for i in range(self.num-2,-1,-1):
            self.seg[i] = self.segfunc(self.seg[2*i+1], self.seg[2*i+2])
        
        
    def update(self, k, x):
        k += self.num-1
        self.seg[k] = x
        while k:
            k = (k-1)//2
            self.seg[k] = self.segfunc(self.seg[k*2+1], self.seg[k*2+2])
            
    def query(self, p, q):
        if q <= p:
            return self.ide_ele
        p += self.num-1
        q += self.num-2
        res = self.ide_ele
        while q - p > 1:
            if p&1 == 0:
                res = self.segfunc(res, self.seg[p])
            if q&1 == 1:
                res = self.segfunc(res, self.seg[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = self.segfunc(res,self.seg[p])
        else:
            res = self.segfunc(self.segfunc(res,self.seg[p]),self.seg[q])
        return res

N = int(input())
h = list(map(int, input().split()))
a = list(map(int, input().split()))
dp = [0] * N
S = SegmentTree(dp)
for i in range(N):
    tmp = S.query(0,h[i]-1)
    S.update(h[i]-1, tmp+a[i])
print(S.query(0,N))