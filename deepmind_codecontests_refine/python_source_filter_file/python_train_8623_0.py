import sys
readline = sys.stdin.readline
from heapq import heappop as hpp, heappush as hp
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
            return idx
        else:
            for idx in (SL + SR[::-1]):
                if check(self.data[idx]):
                    break
            else:
                return -1
            while idx < self.N0:
                if check(self.data[2*idx]):
                    idx = 2*idx
                else:
                    idx = 2*idx + 1
            return idx

N = int(readline())

inf = 1<<32
P = list(map(int, readline().split()))

Pi = [None]*(N+1)
for i in range(N):
    Pi[P[i]] = i

inf = 1<<32
Peven = [P[i] if not i&1 else inf for i in range(N)]
Podd = [P[i] if i&1 else inf for i in range(N)]

Teven = Segtree(Peven, inf, initialize = True, segf = min)
Todd = Segtree(Podd, inf, initialize = True, segf = min)
N0 = 2**(N-1).bit_length()

Q = [(Teven.query(0, N0), 0, N0)]
for i in range(N//2):
    t1, l, r = hpp(Q)
    K = []
    if not l&1:
        p1 = Pi[t1]
        t2 = Todd.query(l, r)
        p2 = Pi[t2]
        Teven.update(p1, inf)
        Todd.update(p2, inf)
    else:
        p1 = Pi[t1]
        t2 = Teven.query(l, r)
        p2 = Pi[t2]
        Todd.update(p1, inf)
        Teven.update(p2, inf)
    if l < p1:
        K.append((l, p1))
    if p2 < r:
        K.append((p2+1, r))
    if p1 + 1 < p2:
        K.append((p1+1, p2))
    for l, r in K:
        if not l&1:
            mq = Teven.query(l, r)
        else:
            mq = Todd.query(l, r)
        hp(Q, (mq, l, r))
    sys.stdout.write('{} {} '.format(t1, t2))
sys.stdout.write('\n')