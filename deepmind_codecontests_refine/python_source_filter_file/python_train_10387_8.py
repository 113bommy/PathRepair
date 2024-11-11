"""
セグメント木
func：二項演算の関数（モノイドである必要あり）
e：単位元（モノイドにおける）
update, find, bisect, 全てにおいて, 1-indexとなっている。
(大抵の場合、Atcoderの問題文の表記のままの値を、メソッドに代入すれば良い)
"""
class SegmentTree:
    def __init__(self, n, func, e, arrange=None):
        self.init(n)
        self.func = func
        self.e = e
        self.make_arrange(arrange)
    
    def init(self, n):
        self.inf = pow(2, 32)
        self.n = n
        self.N = 1
        while self.N < self.n:
            self.N *= 2
        self.size = self.N * 2
    
    def make_arrange(self, arrange):
        self.set_arrange(arrange)
        self.construct(arrange)

    def set_arrange(self, arrange):
        if arrange == None:
            self.segment = [self.e]*(self.size)
            return
        self.segment = [0]*(self.N) + arrange + [self.e]*(self.size-self.N-self.n)
    
    def construct(self, arrange):
        if arrange == None:
            return
        for i in range(self.N-1, 0, -1):
            self.segment[i] = self.func(self.segment[2*i], self.segment[2*i+1])
    
    def update(self, i, x):
        i += (self.N - 1)
        self.segment[i] = x
        while i > 1:
            i = i//2
            self.segment[i] = self.func(self.segment[2*i], self.segment[2*i+1])
    

    def count(self, l, r):
        res = self.e
        l += self.N-1
        r += self.N
        while r > l:
            if l & 1:
                res = self.func(res, self.segment[l])
                l += 1
            if r & 1:
                r -= 1
                res = self.func(res, self.segment[r])
            l >>= 1
            r >>= 1
        return res
    

    def bisect_sub(self, a, b, k, l, r, x):
        if r <= a or b <= l:
            return b+1
        if self.segment[k+1] < x:
            return b+1
        if k >= self.N:
            return r
        
        find_l = self.bisect_sub(a, b, 2*k+1, l, (l+r)//2, x)
        if find_l <= b:
            return find_l

        find_r = self.bisect_sub(a, b, 2*k+2, (l+r)//2, r, x)
        return find_r

    def bisect(self, l, r, x):
        return self.bisect_sub(l-1, r, 0, 0, self.size-self.N, x)
    

def main():
    n, q = map(int, input().split())
    p = list(map(int, input().split()))
    seg = SegmentTree(n, max, 0, arrange=p)

    res = []
    for i in range(q):
        a, b, c = list(map(int, input().split()))
        if a == 1:
            seg.update(b, c)
        elif a == 2:
            ans = seg.count(b, c)
            res.append(ans)
        else:
            ans = seg.bisect(b, n, c)
            res.append(ans)

    print(*res, sep="\n")
            

    
if __name__ == "__main__":
    main()


