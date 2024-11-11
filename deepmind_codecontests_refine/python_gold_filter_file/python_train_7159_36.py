class BIT:
    """
    1-indexed
    """
    def __init__(self, size):
        self.size = size
        self.data = [0] * (size + 1)

    def add(self, index, value=1):
        while index <= self.size:
            self.data[index] += value
            index += index & (-index)

    def sum(self, index):
        """
        右端含める
        """
        ret = 0
        while index:
            ret += self.data[index]
            index -= index & (-index)
        return ret

    def search(self, val):
        """
        x_1 + ... x_i >= val を満たす最小のi
        """
        i = 0
        s = 0
        step = 1 << (self.size.bit_length() - 1)  # 一番上の長さ

        while step:
            if i + step <= self.size and s + self.data[i + step] < val:
                i += step
                s += self.data[i]
            step //= 2
        return i + 1

N, Q = map(int, input().split())
C = [-1] + list(map(int, input().split()))
tree = BIT(N)

query = [[] for _ in range(N + 1)]
for q in range(Q):
    l, r = map(int, input().split())
    query[r].append((q, l))

index = [-1] * (N + 1)
ans = [0] * Q

for r in range(1, N + 1):
    if index[C[r]] > 0:
        tree.add(index[C[r]], -1)
    tree.add(r, 1)
    index[C[r]] = r

    for q, l in query[r]:
        ans[q] = tree.sum(r) - tree.sum(l - 1)

print(*ans, sep='\n')
