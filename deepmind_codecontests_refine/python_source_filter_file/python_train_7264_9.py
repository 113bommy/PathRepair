import sys
input = sys.stdin.readline
import bisect
MOD = 998244353
n = int(input())
XD = sorted([list(map(int, input().split())) for _ in range(n)])
X, D = zip(*XD)


C = list(range(n))

class RmaxQ:
    def __init__(self, original):
        self.n = len(original)
        self.INF = -float("inf")
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
            i >>= 1
            self.seg[i] = max(self.seg[2*i], self.seg[2*i+1])
                
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
    
seg = RmaxQ(C)
for i in range(n):
  x, d = XD[n-1-i]
  t = bisect.bisect_left(X, x+d
  seg.update(n-1-i, max(t, seg.query(n-1-i, t)))

dp = [0]*(n+1)
l = [0]*n
l[-1] = n
dp[-1] = 1
for i in range(n):
  x, d = XD[n-1-i]
  m = bisect.bisect_left(X, x+d)
  t = seg.query(n-1-i, m)
  dp[n-1-i] = dp[n-i] + dp[t]
  dp[n-1-i] %= MOD
print(dp[0])