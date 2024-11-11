class UnionFind():
    "Either 0-indexed or 1-indexed"

    __slots__ = ["parent"]

    def __init__(self, size):
        self.parent = [-1] * (size + 1)
    
    def find(self, a):
        path = []
        while self.parent[a] > 0:
            path.append(a)
            a = self.parent[a]
        for child in path:
            self.parent[child] = a
        return a

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)

        if a == b:
            return
        else:
            if self.parent[a] == self.parent[b]:
                self.parent[a] = b
                self.parent[b] -= 1
            elif self.parent[a] < self.parent[b]: #aのほうが大きい
                self.parent[b] = a
            else:
                self.parent[a] = b #bのほうが大きい
        
    def same(self, a, b):
        return self.find(a) == self.find(b)


# 基本的に番兵を入れて使うのがいいでしょう。

class MultisetBIT:
    """
    最大値が小さい数について、その重複を許した集合を管理する。
    最大値 maxvalue を受け取り、[0, maxvalue] を管理する。
    counter は辞書型かリスト型で、counter[i] が i の個数を持つことを仮定する。
    counter が与えられなかった場合は、全て個数 0 で初期化される。
    基本的に閉区間で管理する。
    内部では受け取った数を +1 したものをindexとして持っているので注意。
    """

    __slots__ = ["n", "k", "data"]

    def __init__(self, maxvalue, counter = None):
        self.n = maxvalue + 1
        self.k = 1 << ((self.n + 1).bit_length() - 1)
        self.data = [0] * (self.n + 1)
        if counter is not None:
            self.update(counter)
        
    def update(self, counter):
        """
        counter を受け取って、それを反映させる。
        counter は辞書型かリスト型で、counter[i] が i の個数を持つことを仮定する。
        計算量は、n を要素の最大値として、 O(n) となる。
        """
        if isinstance(counter, list):
            self.data = [0] + counter + [0] * (self.n - len(counter))
        else:
            self.data = [0] * (self.n + 1)
            for k, v in counter.items():
                self.data[k + 1] = v
        for i in range(1, self.n + 1):
            if i + (i & -i) <= self.n:
                self.data[i + (i & -i)] += self.data[i]

    def add(self, value, count = 1):
        """
        与えられた引数を Multiset に加える。
        計算量は、n を要素の最大値として、 O(log n) となる。
        """
        value += 1
        while value <= self.n:
            self.data[value] += count
            value += value & -value

    def pop(self, value, count = 1):
        """
        Multiset から与えられた引数を取り除く。
        与えられた引数が Multiset に入っているかのチェックは行わなず、
        単にその個数を 1 減らすだけなので注意。
        計算量は、n を要素の最大値として、 O(log n) となる。
        """
        value += 1
        while value <= self.n:
            self.data[value] -= count
            value += value & -value

    def count_le(self, value):
        """
        Multiset 内の要素 elem のうち、0 <= elem <= value を満たすものを数える。
        計算量は、n を要素の最大値として、 O(log n) となる。
        """
        value += 1
        ret = 0
        while value > 0:
            ret += self.data[value]
            value -= value & -value
        return ret

    def count(self, first, last):
        """
        Multiset 内の要素 elem のうち、first <= elem <= last を満たすものを数える。
        計算量は、n を要素の最大値として、 O(log n) となる。
        """
        last += 1
        ret = 0
        while first < last:
            ret += self.data[last]
            last -= last & -last
        while last < first:
            ret -= self.data[first]
            first -= first & -first
        return ret

    def __getitem__(self, index):
        if isinstance(index, slice):
            return self.count(index.start, index.stop - 1)
        else:
            return self.count(index, index)

    def bisect(self, count):
        """
        Multiset 内の要素 elem のうち、count <= count_le(elem) を満たす最小のelemを返す。
        計算量は、n を要素の最大値として、 O(log n) となる。
        """
        ret = 0
        k = self.k
        while k > 0:
            if ret + k <= self.n and self.data[ret + k] < count:
                count -= self.data[ret + k]
                ret += k
            k //= 2
        return ret

    def lower_bound(self, value):
        """
        Multiset 内の要素 elem のうち、value <= elem を満たす最小のelemを返す。
        計算量は、n を要素の最大値として、 O(log n) となる。
        """
        return self.bisect(self.count_le(value - 1) + 1)

    def upper_bound(self, value):
        """
        Multiset 内の要素 elem のうち、value < elem を満たす最小のelemを返す。
        計算量は、n を要素の最大値として、 O(log n) となる。
        """
        return self.bisect(self.count_le(value) + 1)


N = int(input())
xys = [tuple(map(int, input().split())) for i in range(N)]
x2i = {x: i for i, (x, y) in enumerate(xys)}

xys.sort(key=lambda t: t[0])

splitted = [True] * (N - 1)

mbit = MultisetBIT(N + 1)
for n, (x, y) in enumerate(xys[:-1]):
    mbit.add(y)
    if mbit.count_le(N - n - 1):
        splitted[n] = False

print(splitted)

mbit = MultisetBIT(N + 1)
for n, (x, y) in enumerate(xys[:0:-1]):
    mbit.add(y)
    if mbit.count(n + 2, N + 1):
        splitted[N - 2 - n] = False

print(splitted)

ans = [0] * N
s = set()
for (x, y), flg in zip(xys, splitted):
    i = x2i[x]
    s.add(i)
    if flg:
        for i in s:
            ans[i] = len(s)
        s = set()

s.add(x2i[xys[-1][0]])
for i in s:
    ans[i] = len(s)
print(*ans, sep='\n')
