import io
import os

from collections import defaultdict

# https://raw.githubusercontent.com/cheran-senthil/PyRival/master/pyrival/data_structures/SegmentTree.py
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

        res_left = res_right = self._default
        while start < stop:
            if start & 1:
                res_left = self._func(res_left, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res_right = self._func(self.data[stop], res_right)
            start >>= 1
            stop >>= 1

        return self._func(res_left, res_right)

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)


inf = float("inf")


def solve(A, B, C, D, M1, M2, M3):
    def groupBadPrev(M):
        d = defaultdict(list)
        for x, y in M:
            x -= 1
            y -= 1
            d[y].append(x)
        return d

    dp = list(A)
    courses = [B, C, D]
    badPrevs = [
        groupBadPrev(M1),
        groupBadPrev(M2),
        groupBadPrev(M3),
    ]

    for course, badPrev in zip(courses, badPrevs):
        prevDp = dp
        segTree = SegmentTree(prevDp, inf, min)
        dp = [inf] * len(course)
        bestA = segTree.query(0, len(segTree))
        for b in range(len(course)):
            if b in badPrev:
                # Temporarily set unreachable prev to inf weight
                for a in badPrev[b]:
                    segTree[a] = inf

                # Extend off lowest
                dp[b] = segTree.query(0, len(segTree)) + course[b]

                # Undo
                for a in badPrev[b]:
                    segTree[a] = prevDp[a]
            else:
                dp[b] = bestA + course[b]

    ans = max(dp)
    if ans == inf:
        return -1
    return ans


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    TC = 1
    for tc in range(1, TC + 1):
        N1, N2, N3, N4 = [int(x) for x in input().split()]
        A = [int(x) for x in input().split()]
        B = [int(x) for x in input().split()]
        C = [int(x) for x in input().split()]
        D = [int(x) for x in input().split()]

        (M,) = [int(x) for x in input().split()]
        M1 = [[int(x) for x in input().split()] for i in range(M)]

        (M,) = [int(x) for x in input().split()]
        M2 = [[int(x) for x in input().split()] for i in range(M)]

        (M,) = [int(x) for x in input().split()]
        M3 = [[int(x) for x in input().split()] for i in range(M)]
        ans = solve(A, B, C, D, M1, M2, M3)
        print(ans)
