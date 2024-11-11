from typing import Callable, List, TypeVar

S = TypeVar("S")


class SegmentTree:
    """Segment Tree
    References:
        https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
    """

    __slots__ = ["e", "op", "_n", "_size", "tree"]

    def __init__(self, a: List[S], e: S, op: Callable[[S, S], S]) -> None:
        self.e = e
        self.op = op
        self._n = len(a)
        self._size = 1 << (self._n - 1).bit_length()

        self.tree = [e] * self._size + a + [e] * (self._size - self._n)
        for i in range(self._size - 1, 0, -1):
            self._update(i)

    def _update(self, k: int) -> None:
        """Update the value of a[k]."""
        self.tree[k] = self.op(self.tree[2 * k], self.tree[2 * k + 1])

    def set(self, k: int, x: S) -> None:
        """Assign x to a[k] in O(log n)."""
        assert 0 <= k < self._n

        k += self._size
        self.tree[k] = x
        while k:
            k >>= 1
            self._update(k)

    def get(self, k: int) -> S:
        """Return a[k] in O(1)."""
        assert 0 <= k < self._n
        return self.tree[k + self._size]

    def prod(self, l: int, r: int) -> S:
        """Return op(a[l], ..., a[r - 1]). Return e, if l == r.
        Complexity: O(log n)
        """
        assert 0 <= l <= r <= self._n

        sml, smr = self.e, self.e
        l += self._size
        r += self._size

        while l < r:
            if l & 1:
                sml = self.op(sml, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                smr = self.op(self.tree[r], smr)
            l >>= 1
            r >>= 1
        return self.op(sml, smr)

    def prod_all(self) -> S:
        """Return op(a[0], ..., a[n - 1]. Return e if n == 0.
        Complexity: O(1)
        """
        return self.tree[1]

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
        assert f(self.e)

        if l == self._n:
            return self._n

        l += self._size
        sm = self.e

        while True:
            while not l & 1:
                l >>= 1

            if not f(self.op(sm, self.tree[l])):
                while l < self._size:
                    l *= 2
                    if f(self.op(sm, self.tree[l])):
                        sm = self.op(sm, self.tree[l])
                        l += 1
                return l - self._size

            sm = self.op(sm, self.tree[l])
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
        assert f(self.e)

        if not r:
            return 0

        r += self._size
        sm = self.e

        while True:
            r -= 1
            while r > 1 and r & 1:
                r >>= 1

            if not f(self.op(self.tree[r], sm)):
                while r < self._size:
                    r = 2 * r + 1
                    if f(self.op(self.tree[r], sm)):
                        sm = self.op(self.tree[r], sm)
                        r -= 1
                return r + 1 - self._size

            if (r & -r) == r:
                break

        return 0


# https://atcoder.jp/contests/practice2/tasks/practice2_j
import sys

readline = sys.stdin.buffer.readline

N, Q = map(int, readline().split())
(*A,) = map(int, readline().split())
tree = SegmentTree(A, 0, max)
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
