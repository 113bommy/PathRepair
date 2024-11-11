class BIT():
    """区間加算、一点取得クエリをそれぞれO(logN)で答える
    add: 区間[l, r)にvalを加える
    get_val: i番目の値を求める
    i, l, rは0-indexed
    """
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def _add(self, i, val):
        while i > 0:
            self.bit[i] += val
            i -= i & -i

    def get_val(self, i):
        """i番目の値を求める"""
        i = i + 1
        s = 0
        while i <= self.n:
            s += self.bit[i]
            i += i & -i
        return s

    def add(self, l, r, val):
        """区間[l, r)にvalを加える"""
        self._add(r, val)
        self._add(l, -val)


from operator import itemgetter


def compress(array):
    """座標圧縮したリストを返す"""
    set_ = set()
    for num in array:
        set_.add(num[0])
        set_.add(num[1])
    array2 = sorted(set_)
    memo = {value: index for index, value in enumerate(array2)}
    for i in range(len(array)):
        array[i] = (memo[array[i][0]], memo[array[i][1]])
    return array

def on_line(x, y):
    return x == 0 or x == r or y == 0 or y == c

def val(x, y):
    if y == 0:
        return x
    if x == r:
        return r + y
    if y == c:
        return r + c + (r - x)
    if x == 0:
        return r + c + r + (c - y)

r, c, n = map(int, input().split())
info = [list(map(int, input().split())) for i in range(n)]

res = []
for i in range(n):
    x1, y1, x2, y2 = info[i]
    if on_line(x1, y1) and on_line(x2, y2):
        left = val(x1, y1)
        right = val(x2, y2)
        if left > right:
            left, right = right, left
        res.append((left, right))


res = sorted(res, key=itemgetter(1))
res = compress(res)

bit = BIT(2 * len(res))
for left, right in res:
    if bit.get_val(left) != 0:
        print("NO")
        exit()
    else:
        bit.add(left, right + 1, 1)
print("YES")


