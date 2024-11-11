import sys
input = sys.stdin.readline

class RmaxQ:
    def __init__(self, original):
        self.n = len(original)
        self.INF = -(2**31)
        self.N0 = 1 << (self.n-1).bit_length()
        self.seg = [self.INF]*(self.N0 << 1)
        for i, j in enumerate(original, self.N0):
            self.seg[i] = j
        for i in range(self.N0-1, 0, -1):
            self.seg[i] = max(self.seg[2*i], self.seg[2*i+1])

    def get(self, i):
        return self.seg[i+self.N0]
        
    def update(self, i, x):
        i += self.N0
        self.seg[i] = x
        while i > 1:
            y = self.seg[i ^ 1]
            if y >= x:
                break
            i >>= 1
            self.seg[i] = x
                

    def add(self, i, d):
        self.update(i, self.get(i)+d)

    def query(self, l, r):
        res = self.INF
        l += self.N0
        r += self.N0
        while l < r:
            if r & 1:
                res = max(res, self.seg[r-1])
            if l & 1:
                res = max(res, self.seg[l])
                l += 1
            l >>= 1
            r >>= 1
     
        return res
        
n = int(input())
H = list(map(int, input().split()))
A = list(map(int, input().split()))
dp = RmaxQ([0]*(n+1))
for i in range(n):
  h, a = H[i], A[i]
  dp.update(h, max(dp.get(h), dp.query(0, h)+a))
ans = dp.query(0, n+1)
print(ans)