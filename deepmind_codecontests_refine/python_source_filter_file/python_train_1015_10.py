class SegTree:
    X_unit = 0
    X_f = max

    def __init__(self, N):
        self.N = N
        self.X = [0] * (N + N)

    def build(self, seq):
        for i, x in enumerate(seq, self.N):
            self.X[i] = x
        for i in range(self.N - 1, 0, -1):
            self.X[i] = self.X_f(self.X[i << 1], self.X[i << 1 | 1])

    def set_val(self, i, x):
        i += self.N
        self.X[i] = x
        while i > 1:
            i >>= 1
            self.X[i] = self.X_f(self.X[i << 1], self.X[i << 1 | 1])

    def fold(self, L, R):
        L += self.N
        R += self.N
        vL = self.X_unit
        vR = self.X_unit
        while L < R:
            if L & 1:
                vL = self.X_f(vL, self.X[L])
                L += 1
            if R & 1:
                R -= 1
                vR = self.X_f(self.X[R], vR)
            L >>= 1
            R >>= 1
        return self.X_f(vL, vR)

N,K = map(int,input().split())
ST = SegTree(300001)
for i in range(N):
    A = int(input())
    l = max(0,A-K)+1
    r = min(A+K,299999)+2
    M = ST.fold(l,r)
    ST.set_val(A+1,M+1)
print(ST.X[1])