class BinaryIndexedTree:
    def __init__(self, N, f=max, id=0):
        self.N = N
        self.bit = [id] * (self.N+1)
        self.f = f
        self.id = id

    def query(self, i):
        res = self.id
        while i > 0:
            res = self.f(res, self.bit[i])
            i -= i & -i
        return res

    def update(self, i, x):
        while i <= self.N:
            self.bit[i] = self.f(self.bit[i], x)
            i += i & -i

def main():
    N,*A=map(int, open(0).read().split())
    L,R=[0]*N,[0]*N
    bit=BinaryIndexedTree(N, max, -1)
    for i,a in enumerate(A):
        L[a-1]=i-bit.query(a)
        bit.update(a, i)
    bit=BinaryIndexedTree(N, max, -1)
    for i,a in enumerate(A[::-1]):
        R[a-1]=i-bit.query(a)
        bit.update(a, i)
    print(sum(L[i]*R[i]*(i+1) for i in range(N)))

if __name__ == "__main__":
    main()