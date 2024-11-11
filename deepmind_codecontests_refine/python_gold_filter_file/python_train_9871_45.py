class Segtree():  # Segtree

    def segfunc(self, x, y):  # 区間にしたい操作
        return max(x, y)  # ex) max,min,gcd,lcm,sum,product

    def __init__(self, LIST, ide_ele):  # LIST: 配列の初期値, ide_ele: 単位元
        n = len(LIST)
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        for i in range(n):  # 配列の値を葉にセット
            self.tree[self.num + i] = LIST[i]
        for i in range(self.num - 1, 0, -1):  # 構築していく
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, k, x):  # k番目の値をxに更新
        k += self.num
        self.tree[k] = x
        while k > 1:
            self.tree[k >> 1] = self.segfunc(self.tree[k], self.tree[k ^ 1])
            k >>= 1

    def query(self, l, r):  # [l, r)のsegfuncしたものを得る
        res = self.ide_ele
        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                res = self.segfunc(res, self.tree[r - 1])
            l >>= 1
            r >>= 1
        return res


n = int(input())
h = list(map(int, input().split()))
a = list(map(int, input().split()))

dp = Segtree([0] * (n + 1), 0)
for ai, hi in zip(a, h):
    dp.update(hi, dp.query(0, hi) + ai)
print(dp.query(0, n + 1))
