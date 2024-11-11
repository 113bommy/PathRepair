import io
import os
import math
from collections import Counter, defaultdict, deque, namedtuple

# https://github.com/cheran-senthil/PyRival/blob/master/pyrival/data_structures/SegmentTree.py
class SegmentTree:
    def __init__(self, data, default=0, func=max):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size : _size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        """func of data[start, stop)"""
        start += self._size
        stop += self._size
        res1 = self._default
        res2 = self._default
        while start < stop:
            if start & 1:
                res1 = self._func(res1, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res2 = self._func(self.data[stop], res2)
            start >>= 1
            stop >>= 1
        return self._func(res1, res2)

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)


def append(left, right):
    if left is None:
        return right
    if right is None:
        return left
    lEnter, lExit = divmod(left, 4)
    rEnter, rExit = divmod(right, 4)
    if lExit & rEnter:
        return lEnter * 4 + rExit
    return 0


def solve(N, Q, RC):
    # grid is col by row

    # first two bit is ways to enter a segment
    # last two bit is ways to exit a segment
    # For a single column, enter and exit are the same
    # For merging two segments of columns, take left's enter and right's exit if they are connected

    # 15 is 1111
    grid = [15 for c in range(N)]

    segTree = SegmentTree(grid, None, append)
    ans = []
    for r, c in RC:
        assert r in [0, 1]
        assert 0 <= c < N
        mask = 1 << r
        mask = mask * 4 + mask
        oldVal = segTree[c]
        segTree[c] = oldVal ^ mask
        if True:
            print("toggled", r, c)
            for i in range(32):
                w = 1 << i
                for j in range(0, N, w):
                    print(bin(segTree.query(j, j + w))[2:].rjust(4, "0"), end=" ")
                print()
                if w >= N:
                    break
        q = segTree.query(0, N)
        if q == 0:
            ans.append("No")
        else:
            # Since (1, 1) and (2, n) can't appear in query list
            ans.append("Yes")

    return "\n".join(ans)


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    N, Q = [int(x) for x in input().split()]
    RC = [[int(x) - 1 for x in input().split()] for i in range(Q)]
    ans = solve(N, Q, RC)
    print(ans)
