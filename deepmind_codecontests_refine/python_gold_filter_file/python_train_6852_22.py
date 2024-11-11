class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


n = int(input())
A = list(map(int, input().split()))
all_pattern = n * (n+1) // 2
check = all_pattern // 2 + bool(all_pattern % 2)
X = sorted(A)

left = 0
right = n

while left + 1 < right:
    idx = (left+right) // 2
    x = X[idx]
    up_or_down = [1 if num >= x else -1 for num in A]
    cumsum = [n]
    total = n
    for point in up_or_down:
        total += point
        cumsum.append(total)

    tree = Bit(2*n+1)
    pattern = 0
    for p in cumsum:
        pattern += tree.sum(p)
        tree.add(p, 1)

    if pattern >= check:
        left = idx
    else:
        right = idx

print(X[left])
