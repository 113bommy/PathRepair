N,K=map(int, input().split())


class SegmentTree:
    def __init__(self, init_value: list, segfunc, ide_ele):
        n = len(init_value)
        self.N0 = 1 << (n - 1).bit_length()
        self.ide_ele = ide_ele
        self.data = [ide_ele] * (2 * self.N0)
        self.segfunc = segfunc
        
        for i, x in enumerate(init_value):
            self.data[i + self.N0 - 1] = x
        for i in range(self.N0 - 2, -1, -1):
            self.data[i] = self.segfunc(self.data[2 * i + 1], self.data[2 * i + 2])
    
    # k: index , x: value
    def update(self, k: int, x):
        k += self.N0 - 1
        ############################
        self.data[k] = x
        ###########################
        while k:
            k = (k - 1) // 2
            self.data[k] = self.segfunc(self.data[k * 2 + 1], self.data[k * 2 + 2])

    def get(self, k):
        return self.query(k,k+1)
    
    # rightは開区間  l<=x<r
    def query(self, left: int, right: int):
        L = left + self.N0
        R = right + self.N0
        res = self.ide_ele
        ##########################
        a, b = [], []
        while L < R:
            if L & 1:
                a.append(L - 1)
                L += 1
            if R & 1:
                R -= 1
                b.append(R - 1)
            L >>= 1
            R >>= 1
        for i in a + b[::-1]:
            res = self.segfunc(res, self.data[i])
        ##########################
        return res



dp=[0]*(3*10**5+1)
seg=SegmentTree(dp, max, 0)
length=len(dp)
for i in range(N):
    a=int(input())
    if i==0:
        seg.update(a,1)
    else:
        left=max(0, a-K)
        right=min(length, a+K+1)
        now=seg.query(left, right)
        seg.update(a, now+1)

print(seg.query(0,length))
