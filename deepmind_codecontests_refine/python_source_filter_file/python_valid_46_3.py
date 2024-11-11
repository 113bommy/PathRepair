class SegTree:
    def __init__(self, init_val, ide_ele, segfunc):
        self.n = len(init_val)
        self.num = 2**(self.n-1).bit_length()
        self.ide_ele = ide_ele
        self.segfunc = segfunc
        self.seg = [ide_ele]*2*self.num
        # set_val
        for i in range(self.n):
            self.seg[i+self.num] = init_val[i]
        # built
        for i in range(self.num-1, 0, -1):
            self.seg[i] = self.segfunc(self.seg[2*i], self.seg[2*i+1])

    def update(self, k, x):
        k += self.num
        self.seg[k] = x
        while k:
            k = k >> 1
            self.seg[k] = self.segfunc(self.seg[2*k], self.seg[2*k+1])

    def query(self, l, r):
        if r <= l:
            return self.ide_ele
        l += self.num
        r += self.num
        lres = self.ide_ele
        rres = self.ide_ele
        while l < r:
            if r & 1:
                r -= 1
                rres = self.segfunc(self.seg[r], rres)
            if l & 1:
                lres = self.segfunc(lres, self.seg[l])
                l += 1
            l = l >> 1
            r = r >> 1
        res = self.segfunc(lres, rres)
        return res

    def __str__(self): # for debug
        arr = [self.query(i,i+1) for i in range(self.n)]
        return str(arr)

def segfuncm(x, y):
    if x <= y:
        return x
    else:
        return y

def segfuncM(x, y):
    if x >= y:
        return x
    else:
        return y

INF = 1 << 60

def main():
    n = int(input())
    C = list(map(int, input().split()))

    CS = [0]*(n+1)
    for i in range(n):
        if i%2 == 0:
            CS[i+1] = CS[i]+C[i]
        else:
            CS[i+1] = CS[i]-C[i]
    #print(CS)
    segm = SegTree(CS, INF, segfuncm)
    segM = SegTree(CS, -INF, segfuncM)

    ans = 0
    for l in range(n):
        if l%2 == 1:
            continue
        for r in range(l, n):
            if r%2 == 0:
                continue
            x = CS[r]-CS[l+1]
            #print(l, r, x)
            a = C[l]
            b = C[r]
            m = segm.query(l+2, r+1)-CS[l+1]
            #print(segm.query(l+1, r+1), CS[l+1])
            M = segM.query(l+2, r+1)-CS[l+1]
            #print(segM.query(l+1, r+1), CS[l+1])
            p = max(1, 1-x, -m, M-x)
            q = min(a, b-x)
            #print(l, r, p, q, m, M)
            if q < p:
                continue
            else:
                ans += q-p+1


    print(ans)

if __name__ == '__main__':
    main()
