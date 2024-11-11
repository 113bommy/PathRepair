
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

n = int(input())
xs = list(map(int, input().split()))
x2i = {}
for i, x in enumerate(xs):
    x2i[x] = i
ss1 = SegTree([n] * n, n, n, min)
ss2 = SegTree([-1] * n, n, -1, max)

r = 0
for x in range(n):
    x = n - x
    rmi2 = ss1.query(x2i[x]+1, n)
    if rmi2 != n:
        ss1.update(rmi2, n)
    rmi = ss1.query(x2i[x]+1, n)
    if rmi2 != n:
        ss1.update(rmi2, rmi2)

    lmi = ss2.query(0, x2i[x])
    if lmi != -1:
        ss2.update(lmi, -1)
    lmi2 = ss2.query(0, x2i[x])
    if lmi != -1:
        ss2.update(lmi, lmi)
    a,b,c,d =(x2i[x] - lmi), (lmi - lmi2), (rmi - rmi2), (rmi2 - x2i[x])
    r += (a*c + b*d) * x
#    print(x, r)
#    print(rmi, rmi2, lmi, lmi2)
    ss1.update(x2i[x], x2i[x])
    ss2.update(x2i[x], x2i[x])
print(r)
