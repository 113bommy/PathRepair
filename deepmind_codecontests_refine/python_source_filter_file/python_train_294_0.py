import sys
readline = sys.stdin.readline

class Segtree:
    def __init__(self, A, intv, initialize = True, segf = max):
        self.N = len(A)
        self.N0 = 2**(self.N-1).bit_length()
        self.intv = intv
        self.segf = segf
        if initialize:
            self.data = [intv]*self.N0 + A + [intv]*(self.N0 - self.N)
            for i in range(self.N0-1, 0, -1):
                self.data[i] = self.segf(self.data[2*i], self.data[2*i+1]) 
        else:
            self.data = [intv]*(2*self.N0)
        
    def update(self, k, x):
        k += self.N0
        self.data[k] = x
        while k > 0 :
            k = k >> 1
            self.data[k] = self.segf(self.data[2*k], self.data[2*k+1])
    
    def query(self, l, r):
        L, R = l+self.N0, r+self.N0
        s = self.intv
        while L < R:
            if R & 1:
                R -= 1
                s = self.segf(s, self.data[R])
            if L & 1:
                s = self.segf(s, self.data[L])
                L += 1
            L >>= 1
            R >>= 1
        return s
    
    def binsearch(self, l, r, check, reverse = False):
        L, R = l+self.N0, r+self.N0
        SL, SR = [], []
        while L < R:
            if R & 1:
                R -= 1
                SR.append(R)
            if L & 1:
                SL.append(L)
                L += 1
            L >>= 1
            R >>= 1
        
        if reverse:
            for idx in (SR + SL[::-1]):
                if check(self.data[idx]):
                    break
            else:
                return -1
            while idx < self.N0:
                if check(self.data[2*idx+1]):
                    idx = 2*idx + 1
                else:
                    idx = 2*idx
            return idx - self.N0
        else:
            pre = self.data[l+self.N0]
            for idx in (SL + SR[::-1]):
                if not check(self.segf(pre, self.data[idx])):
                    pre = self.segf(pre, self.data[idx])
                else:
                    break
            else:
                return -1
            while idx < self.N0:
                if check(self.segf(pre, self.data[2*idx])):
                    idx = 2*idx
                else:
                    pre = self.segf(pre, self.data[2*idx])
                    idx = 2*idx + 1
            return idx - self.N0


INF = 10**9 + 7
N, E, T = map(int, readline().split())
X = list(map(int, readline().split()))
X = [0] + [x-X[0]  for x in X] + [INF]
E -= X[0]
dp = [0]*(N+2)
dpl = Segtree([0]*(N+2), INF, initialize = False, segf = min)
dpr = Segtree([0]*(N+2), INF, initialize = False, segf = min)
dpl.update(0, 0)
dpr.update(0, 0)

for i in range(1, N+1):
    di = X[i]
    dn = X[i+1]
    ok = i
    ng = -1
    while abs(ok-ng) > 1:
        med = (ok+ng)//2
        if (X[i] - X[med])*2 <= T:
            ok = med
        else:
            ng = med
    left = ok-1
    resr = dpr.query(left, i) + T + di
    resl = dpl.query(0, left) + 3*di
    dp[i] = min(resl, resr)
    dpl.update(i, dp[i] - di - 2*dn)
    dpr.update(i, dp[i] - di)

print(dp[N] + E - X[N])