 import sys

input = sys.stdin.buffer.readline

n, q = map(int, input().split())


class SegmentTree:
    ele = 10 ** 10
    func = min
    # SEG木は1-index
    # Aに関しては0-index

    def __init__(self, n):  # Aは0-idx
        self.n = n
        self.num = 2 ** ((self.n - 1).bit_length())
        self.SEG = [self.ele] * (2 * self.num)

    def search(self, idx):
        return self.SEG[idx + self.num]

    def initialize(self, A):
        for i in range(self.n):
            self.SEG[i + self.num] = A[i]
        for i in range(self.num - 1, 0, -1):
            self.SEG[i] = self.func(self.SEG[2 * i], self.SEG[2 * i + 1])

    def update(self, idx, val):
        idx += self.num
        self.SEG[idx] = val
        idx //= 2
        while idx:
            self.SEG[idx] = self.func(self.SEG[2 * idx], self.SEG[2 * idx + 1])
            idx //= 2

    def query(self, left, right):
        # maspy式。開区間のママ処理する
        # left, rightで値を分けているのは交換法則不成立のときのため
        # 開区間→Rが奇数→右端が偶数→1ずらしてから計算
        # 　下から上への遷移は2で割る
        # juppy氏は閉区間に直していた
        resleft = self.ele
        resright = self.ele
        left += self.num
        right += self.num
        while right - left > 0:
            if left % 2 == 1:
                resleft = self.func(resleft, self.SEG[left])
                left += 1
            if right % 2 == 1:
                right -= 1
                resright = self.func(resright, self.SEG[right])
            left //= 2
            right //= 2
        return self.func(resleft, resright)


ans = 0

tate = SegmentTree(n)
yoko = SegmentTree(n)

for i in range(q):
    s, x = map(int, input().split())
    x -= 1
    if s == 1:
        temp = tate.query(x, n)
        # print("t", i, temp)
        if temp == 10 ** 10:
            temp = n - 1
        now = yoko.search(temp)
        now = min(now, x)
        yoko.update(temp, now)
        ans += temp - 1
    else:
        temp = yoko.query(x, n)
        # print("t", i, temp)
        if temp == 10 ** 10:
            temp = n - 1
        now = tate.search(temp)
        now = min(now, x)
        tate.update(temp, now)
        ans += temp - 1
    # print("a", i, temp - 1)
ans = (n - 2) ** 2 - ans
assert ans >= 0
print(ans)
