import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


class BinaryIndexedTree:
    # http://hos.ac/slides/20140319_bit.pdf
    def __init__(self, size):
        """
        :param int size:
        """
        self._bit = [0] * size
        self._size = size

    def add(self, i, w):
        """
        i 番目に w を加える
        :param int i:
        :param int w:
        """
        x = i + 1
        while x <= self._size:
            self._bit[x - 1] += w
            x += x & -x

    def sum(self, i):
        """
        [0, i) の合計
        :param int i:
        """
        ret = 0
        while i > 0:
            ret += self._bit[i - 1]
            i -= i & -i
        return ret

    def __len__(self):
        return self._size


def median(A):
    return list(sorted(A))[len(A) // 2]


def test(A):
    N = len(A)
    M = []
    for l in range(N):
        for r in range(l + 1, N + 1):
            M.append(median(A[l:r]))
    print(median(M))


def less_than(k):
    arr = [0] * (N + 1)
    for i, b in enumerate(B):
        arr[i + 1] = 1 if b >= k else -1
    cum = cumsum(arr)
    base = min(cum)
    for i in range(len(cum)):
        cum[i] -= base

    # 中央値が k より小さくなる [l, r] の数
    # →[l, r] の総和がマイナスになる組み合わせの数
    # →転倒数
    bit = BinaryIndexedTree(size=max(cum) + 1)
    count = 0
    for i, c in enumerate(cum):
        count += i - bit.sum(c + 1)
        bit.add(c, 1)

        # 中央値が k より小さくなる数が半分より多ければ答えは k より小さい
        # NH2 = (N+1)C2
        if count > (N + 1) * N // 2 / 2:
            return True
    return False


def compress(li, origin=0):
    """
    座圧
    :param li:
    :param int origin:
    :rtype: list of int
    """
    *ret, = map({v: i + origin for i, v in enumerate(sorted(set(li)))}.__getitem__, li)
    return ret


def argsort(li, key=None, reverse=False):
    return [i for _, i in sorted(
        [(a, i) for i, a in enumerate(li)], key=(lambda t: key(t[0])) if key else None, reverse=reverse
    )]


def cumsum(it):
    """
    累積和
    :param collections.Iterable it:
    :return:
    """
    cs = 0
    ret = []
    for v in it:
        cs += v
        ret.append(cs)
    return ret


N = int(sys.stdin.buffer.readline())
A = list(map(int, sys.stdin.buffer.readline().split()))
# test(A)

indices = argsort(A)

# 座圧
B = compress(A)

lo = 0
hi = N
while abs(lo - hi) > 1:
    mid = (lo + hi) // 2
    if less_than(B[indices[mid]]):
        hi = mid
    else:
        lo = mid
print(A[indices[lo]])
