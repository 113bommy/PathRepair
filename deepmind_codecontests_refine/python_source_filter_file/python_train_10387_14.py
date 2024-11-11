from typing import Callable, Iterator, TypeVar

S = TypeVar("S")


class SegmentTree:
    """Segment Tree
    References:
        https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
    """

    __slots__ = ["_e", "_op", "_n", "_size", "_tree"]

    def __init__(self, a: Iterator[S], n: int, e: S, op: Callable[[S, S], S]) -> None:
        self._e = e
        self._op = op
        self._n = n
        self._size = 1 << (self._n - 1).bit_length()

        self._tree = [e] * 2 * self._size
        for i, a in enumerate(a, self._size):
            self._tree[i] = a
        for i in range(self._size - 1, 0, -1):
            self._update(i)

    def _update(self, k: int) -> None:
        """Update the value of a[k]."""
        self._tree[k] = self._op(self._tree[2 * k], self._tree[2 * k + 1])

    def set(self, k: int, x: S) -> None:
        """Assign x to a[k] in O(log n)."""
        assert 0 <= k < self._n

        k += self._size
        self._tree[k] = x
        while k:
            k >>= 1
            self._update(k)

    def get(self, k: int) -> S:
        """Return a[k] in O(1)."""
        assert 0 <= k < self._n
        return self._tree[k + self._size]

    def prod(self, l: int, r: int) -> S:
        """Return op(a[l], ..., a[r - 1]). Return e, if l == r.
        Complexity: O(log n)
        """
        assert 0 <= l <= r <= self._n

        sml, smr = self._e, self._e
        l += self._size
        r += self._size

        while l < r:
            if l & 1:
                sml = self._op(sml, self._tree[l])
                l += 1
            if r & 1:
                r -= 1
                smr = self._op(self._tree[r], smr)
            l >>= 1
            r >>= 1
        return self._op(sml, smr)

    def prod_all(self) -> S:
        """Return op(a[0], ..., a[n - 1]. Return e if n == 0.
        Complexity: O(1)
        """
        return self._tree[1]

    def max_right(self, l: int, f: Callable[[S], bool]) -> int:
        """
        Return an index r satisfying both:
            1. r = l or f(op(a[l], a[l + 1], ..., a[r - 1])) = true
            2. r = n or f(op(a[l], a[l + 1], ..., a[r])) = false.

        If f is monotone, this is the maximum r satisfying:
            f(op(a[l], a[l + 1], ..., a[r - 1])) = true.

        Complexity: O(log n)
        """
        assert 0 <= l <= self._n
        assert f(self._e)

        if l == self._n:
            return self._n

        l += self._size
        sm = self._e

        while True:
            while not l & 1:
                l >>= 1

            if not f(self._op(sm, self._tree[l])):
                while l < self._size:
                    l *= 2
                    if f(self._op(sm, self._tree[l])):
                        sm = self._op(sm, self._tree[l])
                        l += 1
                return l - self._size

            sm = self._op(sm, self._tree[l])
            l += 1

            if (l & -l) == l:
                break

        return self._n

    def min_left(self, r: int, f: Callable[[S], bool]) -> int:
        """
        Return an index l satisfying both:
            1. l = r or f(op(a[l], a[l + 1], ..., a[r - 1])) = true
            2. l = 0 or f(op(a[l - 1], a[l + 1], ..., a[r - 1])) = false.
        If f is monotone, this is the minimum l satisfying:
            f(op(a[l], a[l + 1], ..., a[r - 1])) = true.

        Complexity: O(log n)
        """
        assert 0 <= r <= self._n
        assert f(self._e)

        if not r:
            return 0

        r += self._size
        sm = self._e

        while True:
            r -= 1
            while r > 1 and r & 1:
                r >>= 1

            if not f(self._op(self._tree[r], sm)):
                while r < self._size:
                    r = 2 * r + 1
                    if f(self._op(self._tree[r], sm)):
                        sm = self._op(self._tree[r], sm)
                        r -= 1
                return r + 1 - self._size

            if (r & -r) == r:
                break

        return 0


def staticrmq():
    # https://judge.yosupo.jp/problem/staticrmq
    import sys

    read = sys.stdin.buffer.read
    readline = sys.stdin.buffer.readline

    N, _ = map(int, readline().split())
    A = map(int, readline().split())
    LR = map(int, read().split())
    tree = SegmentTree(A, N, (10 ** 10) + 1, min)
    res = [tree.prod(l, r) for l, r in zip(*[iter(LR)] * 2)]
    print("\n".join(map(str, res)))


def practice2_j():
    # https://atcoder.jp/contests/practice2/tasks/practice2_j
    import sys

    readline = sys.stdin.readline

    N, Q = map(int, readline().split())
    A = map(int, readline().split())
    tree = SegmentTree(A, N, -1, max)
    res = []
    for _ in range(Q):
        t, x, y = map(int, readline().split())
        if t == 1:
            tree.set(x - 1, y)
        elif t == 2:
            res.append(tree.prod(x - 1, y))
        else:
            res.append(tree.max_right(x - 1, lambda n: n < y) + 1)
    print("\n".join(map(str, res)))


def dsl_2_a():
    # https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
    N, Q, *X = map(int, open(0).read().split())
    tree = SegmentTree([2 ** 31 - 1] * N, N, 2 ** 31 - 1, min)
    res = []
    for com, x, y in zip(*[iter(X)] * 3):
        if com:
            res.append(tree.prod(x, y + 1))
        else:
            tree.set(x, y)
    print("\n".join(map(str, res)))


def abc125_c():
    # https://atcoder.jp/contests/abc125/tasks/abc125_c
    from math import gcd

    N, *A = map(int, open(0).read().split())
    tree = SegmentTree(A, N, 0, gcd)
    res = max(gcd(tree.prod(0, i), tree.prod(i + 1, N)) for i in range(N))
    print(res)


if __name__ == "__main__":
    staticrmq()
    # practice2_j()
    # dsl_2_a()
    # abc125_c()
