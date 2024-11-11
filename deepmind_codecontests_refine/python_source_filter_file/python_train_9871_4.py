class SEGMENT_TREE:
    def __init__(self, N):
        """
        INPUT
        N: 配列のサイズ
        segment tree: 1-indexedで構築
        original array: 0-indexed
                 1
           2           3
         4    5     6     7
        8 9 10 11 12 13 14 15
        ---------------------
        0 1 2  3  4  5  6  7
        """
        self.N = N
        self.tree = [0] * (2 * N)  # 問題により修正

    def init(self, arr):
        N = self.N
        for i in range(N):
            self.tree[N + i] = arr[i]
        for i in range(N - 1, 0, -1):
            self.tree[i] = max(
                self.tree[i * 2], self.tree[i * 2 + 1])  # 問題により修正

    def update(self, p, value):
        """配列arr[p]をvalueに変更"""
        i = p + self.N
        self.tree[i] = value
        while i > 1:
            self.tree[i // 2] = max(self.tree[i], self.tree[i ^ 1])  # 問題により修正
            i //= 2

    def query(self, l, r):
        """
        l, r: 0-indexed
        半開区間[l, r)から条件を満たす数を返す
        """
        N = self.N
        res = 0  # 問題により修正
        l += N
        r += N
        while l < r:
            if (l & 1):
                res = max(res, self.tree[l])
                l += 1
            if (r & 1):
                r -= 1
                res = max(res, self.tree[r])
            l //= 2
            r //= 2
        return res


if __name__ == "__main__":
    N = int(input())
    H = list(map(int, input().split()))
    A = list(map(int, input().split()))
    seg = SEGMENT_TREE(N + 1)
    for h, a in zip(H, A):
        left = seg.query(0, h + 1)
        seg.update(h, left + a)
    print(seg.query(0, N+1))
