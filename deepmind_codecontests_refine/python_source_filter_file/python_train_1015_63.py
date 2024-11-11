def segfunc(x, y): return max(x, y)

class SegmentTree:
    def __init__(self, arr):
        size = len(arr)
        n = 2 ** (size - 1).bit_length()
        self.n = n
        self.node = [0] * (2*n)
        for i in range(size):
            self.node[i+n-1] = arr[i]
        for i in reversed(range(n-2)):
            self.node[i] = segfunc(self.node[2*i+1], self.node[2*i+2])

    def update(self, i, x):
        i += self.n - 1
        self.node[i] = x
        while i > 0:
            i = (i - 1) // 2
            self.node[i] = segfunc(self.node[i * 2 + 1], self.node[i * 2 + 2])

    def update(self, x, val):
        x += (self.n - 1)
        self.node[x] = val
        while x > 0:
            x = (x - 1) // 2
            self.node[x] = segfunc(self.node[2 * x + 1], self.node[2 * x + 2])

    def query(self, a, b):
        res = 0
        l = self.n - 1 + a
        r = self.n - 1 + (b - 1)

        while l <= r:
            if l == r:
                res = segfunc(res, self.node[l])
                break

            if l % 2 == 0:
                res = segfunc(res, self.node[l])
            if r % 2 == 1:
                res = segfunc(res, self.node[r])
            l = l // 2
            r = r // 2 - 1

        return res

N, K = map(int, input().split())
INF = 0
seg = SegmentTree([0] * 300000)
for i in range(N):
    a = int(input())
    tmp = seg.query(max(a - K, 0), min(a + K, 300000) + 1) + 1
    seg.update(a, tmp)
print(seg.query(0, N))
