class SegTree:
    def __init__(self, a, func):
        self.n = 2**(len(a) - 1).bit_length()
        self.f = func
        self.d = [0] * (2 * self.n - 1)
        self.d[self.n - 1:self.n - 1 + len(a)] = a
        for i in reversed(range(self.n - 1)):
            self.d[i] = self.f(self.d[2 * i + 1], self.d[2 * i + 2])

    def update(self, i, v):
        i += self.n - 1
        self.d[i] = v
        while i:
            i = (i - 1) // 2
            self.d[i] = self.f(self.d[2 * i + 1], self.d[2 * i + 2])

    def query(self, l, r):
        assert l <= r
        l += self.n
        r += self.n
        s = self.d[l - 1]
        while l < r:
            if l & 1:
                s = self.f(s, self.d[l - 1])
                l += 1
            if r & 1:
                r -= 1
                s = self.f(s, self.d[r - 1])
            l //= 2
            r //= 2
        return s

def main():
    N = int(input())
    H = list(map(int, input().split()))
    A = list(map(int, input().split()))
    S = SegTree([0] * N, max)

    for h, a in zip(H, A):
        S.update(h - 1, S.query(0, h - 1) + a)
    return S.query(0, N)

print(main())
