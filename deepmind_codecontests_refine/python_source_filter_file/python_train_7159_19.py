class BIT:
    # 1-indexed
    def __init__(self, n):
        self.size = n + 1
        self.bit = [0] * self.size

    def add(self, i, x):
        """Add x to a[i]."""
        while i < self.size:
            self.bit[i] += x
            i += i & -i

    def sumup(self, i):
        """Sum a[1]~a[i]."""
        res = 0
        while i > 0:
            res += self.bit[i]
            i -= i & -i
        return res

    def query(self, i, j):
        """Sum a[i]~a[j]."""
        return self.sumup(j) - self.sumup(i - 1)


N, Q = map(int, input().split())
C = list(map(int, input().split()))
X = [list(map(int, input().split())) for _ in range(Q)]

ans = [0] * Q
last_appeared = [0] * (N + 1)
bit = BIT(N + 1)
rm = 0
for i, (l, r) in sorted(enumerate(X), key=lambda x: x[1][1]):
    for j in range(rm + 1, r + 1):
        if last_appeared[C[j - 1]] > 0:
            bit.add(last_appeared[C[j - 1]], -1)
        last_appeared[C[j - 1]] = j
        bit.add(j, 1)

    rm = r
    ans[i] = bit.query(l, r)

print(*ans, sep="\n")
