import sys
readline = sys.stdin.readline
class Lazysegtree:
    def __init__(self, A, fx, ex, fm, initialize = True):
        #作用の単位元をNoneにしている
        #fa(operator, idx)の形にしている、data[idx]の長さに依存する場合などのため
        self.N = len(A)
        self.N0 = 2**(self.N-1).bit_length()
        self.ex = ex
        self.lazy = [None]*(2*self.N0)
        if initialize:
            self.data = [self.ex]*self.N0 + A + [self.ex]*(self.N0 - self.N)
            for i in range(self.N0-1, -1, -1):
                self.data[i] = self.fx(self.data[2*i], self.data[2*i+1]) 
        else:
            self.data = [self.ex]*(2*self.N0)
    def fx(self, x, y):
        return (x+y)%MOD
    def fm(self, o, p):
        o1 = o>>32
        return ((o1)*(p>>32)%MOD)<<32 + (o1*(p&mask) + (o&mask))%MOD

    
    def fa(self, ope, idx):
        """
        TO WRITE
        """
        k = idx.bit_length()
        return ((ope>>32)*self.data[idx] + (self.N0>>(k-1))*(ope&mask))%MOD
        
    
    def __repr__(self):
        s = 'data'
        l = 'lazy'
        cnt = 1
        for i in range(self.N0.bit_length()):
            s = '\n'.join((s, ' '.join(map(str, self.data[cnt:cnt+(1<<i)]))))
            l = '\n'.join((l, ' '.join(map(str, self.lazy[cnt:cnt+(1<<i)]))))
            cnt += 1<<i
        return '\n'.join((s, l))
    
    def _ascend(self, k):
        k = k >> 1
        c = k.bit_length()
        for j in range(c):
            idx = k >> j
            self.data[idx] = self.fx(self.data[2*idx], self.data[2*idx+1])
            
    def _descend(self, k):
        k = k >> 1
        idx = 1
        c = k.bit_length()
        for j in range(1, c+1):
            idx = k >> (c - j)
            if self.lazy[idx] is None:
                continue
            self.data[2*idx] = self.fa(self.lazy[idx], 2*idx) 
            self.data[2*idx+1] = self.fa(self.lazy[idx], 2*idx+1)
            if self.lazy[2*idx] is not None:
                self.lazy[2*idx] = self.fm(self.lazy[idx], self.lazy[2*idx])
            else:
                self.lazy[2*idx] = self.lazy[idx]
            if self.lazy[2*idx+1] is not None:
                self.lazy[2*idx+1] = self.fm(self.lazy[idx], self.lazy[2*idx+1])
            else:
                self.lazy[2*idx+1] = self.lazy[idx]
            self.lazy[idx] = None
            
            
    def query(self, l, r):
        L = l+self.N0
        R = r+self.N0
        self._descend(L//(L & -L))
        self._descend(R//(R & -R)-1)
        
        sl = self.ex
        sr = self.ex                                                                   

        while L < R:
            if R & 1:
                R -= 1
                sr = self.fx(self.data[R], sr)
            if L & 1:
                sl = self.fx(sl, self.data[L])
                L += 1
            L >>= 1
            R >>= 1
        return self.fx(sl, sr)
    
    def operate(self, l, r, x):
        L = l+self.N0
        R = r+self.N0

        Li = L//(L & -L)
        Ri = R//(R & -R)
        self._descend(Li)
        self._descend(Ri-1)
        
        while L < R :
            if R & 1:
                R -= 1
                self.data[R] = self.fa(x, R)
                if self.lazy[R] is None:
                    self.lazy[R] = x
                else:
                    self.lazy[R] = self.fm(x, self.lazy[R])
            if L & 1:
                self.data[L] = self.fa(x, L)
                if self.lazy[L] is None:
                    self.lazy[L] = x
                else:
                    self.lazy[L] = self.fm(x, self.lazy[L])
                L += 1
            L >>= 1
            R >>= 1
        
        self._ascend(Li)
        self._ascend(Ri-1)

MOD = 998244353
mask = (1<<32) - 1
    

N, Q = map(int, readline().split())
A = list(map(int, readline().split()))

T = Lazysegtree(A, None, 0, None, initialize = True)

Ans = []
for _ in range(Q):
    t, *s = readline().split()
    if t == '0':
        l, r, b, c = map(int, s)
        T.operate(l, r, (b<<32)+c)
    else:
        l, r = map(int, s)
        Ans.append(T.query(l, r))

print('\n'.join(map(str, Ans)))
