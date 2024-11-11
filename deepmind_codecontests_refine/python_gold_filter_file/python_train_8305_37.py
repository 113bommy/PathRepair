class SegTree():
    def segfunc(self, x, y):
        return x+y

    def __init__(self, ide, n, init_val):
        self.ide_ele = ide
        self.num = 2**(n-1).bit_length()
        self.seg = [self.ide_ele] * 2 * self.num
        for i in range(n):
            self.seg[i+self.num-1] = init_val[i]    
        for i in range(self.num-2,-1,-1):
            self.seg[i] = self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
    def update(self, k, x):
        k += self.num-1
        self.seg[k] = x
        while k:
            k = (k-1)//2
            self.seg[k] = self.segfunc(self.seg[k*2+1], self.seg[k*2+2])
    def query(self, p, q):#p <= x < q
        if q<=p:
            return self.ide_ele
        p += self.num-1
        q += self.num-2
        res = self.ide_ele
        while q-p>1:
            if p&1 == 0:
                res = self.segfunc(res, self.seg[p])
            if q&1 == 1:
                res = self.segfunc(res, self.seg[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = self.segfunc(res, self.seg[p])
        else:
            res = self.segfunc(self.segfunc(res, self.seg[p]), self.seg[q])
        return res

def main():
    n = int(input())
    P = list(map(int, input().split()))
    ans = 0
    arr = [[P[i], i] for i in range(n)]
    arr.sort(key=lambda x: -x[0])
    seg = SegTree(0, n, [0]*n)
    for v, idx in arr:
        seg.update(idx, 1)
        if idx < n-1 and seg.query(idx+1, n) > 0:
            L, R = idx, n
            while L+1 < R:
                M = (L+R)//2
                if seg.query(idx+1, M+1) < 1:
                    L = M
                else:
                    R = M
            x = R
            L, R = x, n
            while L+1 < R:
                M = (L+R)//2
                if seg.query(idx+1, M+1) < 2:
                    L = M
                else:
                    R = M
            r_range = R - x
            L, R = -1, idx
            while L+1 < R:
                M = (L+R+1)//2
                if seg.query(M, idx) == 0:
                    R = M
                else:
                    L = M
            l_range = idx - L
            ans += v * l_range * r_range
            #print("right : ", v, l_range, r_range)
        if 0 < idx and seg.query(0, idx) > 0:
            L, R = idx, n
            while L+1 < R:
                M = (L+R)//2
                if seg.query(idx+1, M+1) == 0:
                    L = M
                else:
                    R = M
            r_range = R - idx
            L, R = 0, idx
            while L+1 < R:
                M = (L+R)//2
                if seg.query(M, idx) < 1:
                    R = M
                else:
                    L = M
            x = L
            L, R = -1, x
            while L+1 < R:
                M = (L+R+1)//2
                if seg.query(M, idx) < 2:
                    R = M
                else:
                    L = M
            l_range = x - L
            ans += v * l_range * r_range
            #print("right : ", v, l_range, r_range)
        #print("ans : ", v, ans)
    print(ans)

if __name__ == "__main__":
    main()