class SegmentTree:
    def __init__(self, A, n=18, inf=10**20):
        l = len(A)
        self.size = n
        self.array = [inf]*(2**(n+1)-1)
        for i in range(l):
            self.array[i+2**n-1] = A[i]
        for i in range(2**n-2, -1, -1):
            self.array[i] = max(self.array[2*i+1], self.array[2*i+2])

    def _subquery(self, l, r, k, i, j):
        if j <= l or r <= i:
            return 0
        elif l <= i and j <= r:
            return self.array[k]
        else:
            l_max = self._subquery(l, r, 2 * k + 1, i, (i + j) // 2)
            r_max = self._subquery(l, r, 2 * k + 2, (i + j) // 2, j)
            return max(l_max, r_max)

    def max(self, l, r):
        return self._subquery(l, r, 0, 0, 2**self.size)

    def update(self, i, c):
        tmp = i + 2**self.size - 1
        self.array[tmp] = c
        while tmp > 0:
            tmp = (tmp - 1) // 2
            l = self.array[2 * tmp + 1]
            r = self.array[2 * tmp + 2]
            self.array[tmp] = max(l, r)

n = int(input())
*H, = map(lambda x: int(x)-1, input().split())
*A, = map(int, input().split())
DP = SegmentTree([0]*n)
for i in range(n):
    tmp = DP.max(0, H[i])
    DP.update(H[i], tmp+A[i])
print(DP.max(0, n))
