class UnionFind :
    def __init__(self, size) :
        self.parent = list(range(size))
        self.height = [0] * size
        self.size = [1] * size
        self.component = size

    def root(self, index) :
        if self.parent[index] == index :  # 根の場合
            return index
        rootIndex = self.root(self.parent[index])  # 葉の場合親の根を取得
        self.parent[index] = rootIndex  # 親の付け直し
        return rootIndex

    def union(self, index1, index2) :  # 結合
        root1 = self.root(index1)
        root2 = self.root(index2)

        if root1 == root2 :  # 連結されている場合
            return

        self.component -= 1  # 連結成分を減らす

        if self.height[root1] < self.height[root2] :
            self.parent[root1] = root2  # root2に結合
            self.size[root2] += self.size[root1]
        else :
            self.parent[root2] = root1  # root1に結合
            self.size[root1] += self.size[root2]
            if self.height[root1] == self.height[root2] :
                self.height[root1] += 1
        return

    def isSameRoot(self, index1, index2) :
        return self.root(index1) == self.root(index2)

    def sizeOfSameRoot(self, index) :
        return self.size[self.root(index)]

    def getComponent(self) :
        return self.component

N = int(input())
INF = 10**18
P = list(map(int, input().split()))
I = [-1] * (N + 1)
tree = UnionFind(N + 2)

for i, p in enumerate(P, start=1):
    I[p] = i

ans = 0
used = [False] * (N + 2)
for p in range(1, N):
    i = I[p]

    # p 未満の範囲 [i - left, i + right]
    left = tree.sizeOfSameRoot(i - 1) if used[i - 1] else 0
    right = tree.sizeOfSameRoot(i + 1) if used[i + 1] else 0

    cnt = 0
    leftMx = i - (left + 1)
    if leftMx >= 1 and not used[leftMx]:
        L = tree.sizeOfSameRoot(leftMx - 1) if (leftMx - 1) >= 0 and used[leftMx - 1] else 0
        cnt += (L + 1) * (right + 1)
    rightMx = i + (right + 1)
    if rightMx <= N and not used[rightMx]:
        R = tree.sizeOfSameRoot(rightMx + 1) if (rightMx + 1) <= N and used[rightMx + 1] else 0
        cnt += (left + 1) * (R + 1)
    ans += cnt * p

    used[i] = True
    if used[i - 1]:
        tree.union(i, i - 1)
    if used[i + 1]:
        tree.union(i, i + 1)
print(ans)
