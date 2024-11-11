import sys
input = sys.stdin.readline

n = int(input())
h = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]


class SegmentTree:
    def __init__(self, a, func=max, one=-10 ** 18):
        self.logn = (len(a) - 1).bit_length()
        self.n = 1 << self.logn
        self.func = func
        self.one = one

        self.b = [self.one] * (2 * self.n - 1)
        for i, j in enumerate(a):
            self.b[i + self.n - 1] = j
        for i in reversed(range(self.n - 1)):
            self.b[i] = self.func(self.b[i * 2 + 1], self.b[i * 2 + 2])

    def get_item(self, i):
        return self.b[i + self.n - 1]

    def update(self, index, x):
        i = index + self.n - 1
        self.b[i] = x
        while i != 0:
            i = (i - 1) // 2
            self.b[i] = self.func(self.b[i * 2 + 1], self.b[i * 2 + 2])

    def update_func(self, index, x):
        i = index + self.n - 1
        self.b[i] = self.func(self.b[i], x)
        while i != 0:
            i = (i - 1) // 2
            self.b[i] = self.func(self.b[i * 2 + 1], self.b[i * 2 + 2])

    def get_segment(self, l, r):
        l += self.n
        r += self.n
        s = self.one
        t = self.one
        while l < r:
            if l & 1:
                s = self.func(s, self.b[l - 1])
                l += 1
            if r & 1:
                r -= 1
                t = self.func(self.b[r - 1], t)
            l >>= 1
            r >>= 1
        return self.func(s, t)


seg = SegmentTree([0]*(n+1))

for i in range(n):
    j = seg.get_segment(0, h[i] + 1)
    seg.update_func(h[i], j + a[i])
print(seg.get_segment(0, n+1))
