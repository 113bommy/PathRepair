import io
import os

# List with O(n^1/3) (for n=10**6) get/set/insert/delete based on: https://github.com/cheran-senthil/PyRival/blob/master/pyrival/data_structures/SortedList.py


class UnsortedList:
    def __init__(self, iterable=[], _load=600):
        """Initialize sorted list instance."""
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i : i + _load] for i in range(0, _len, _load)]
        self._list_lens = [len(_list) for _list in _lists]
        # self._mins = [_list[0] for _list in _lists]
        self._fen_tree = []
        self._rebuild = True

    def _fen_build(self):
        """Build a fenwick tree instance."""
        self._fen_tree[:] = self._list_lens
        _fen_tree = self._fen_tree
        for i in range(len(_fen_tree)):
            if i | i + 1 < len(_fen_tree):
                _fen_tree[i | i + 1] += _fen_tree[i]
        self._rebuild = False

    def _fen_update(self, index, value):
        """Update `fen_tree[index] += value`."""
        if not self._rebuild:
            _fen_tree = self._fen_tree
            while index < len(_fen_tree):
                _fen_tree[index] += value
                index |= index + 1

    def _fen_query(self, end):
        """Return `sum(_fen_tree[:end])`."""
        if self._rebuild:
            self._fen_build()

        _fen_tree = self._fen_tree
        x = 0
        while end:
            x += _fen_tree[end - 1]
            end &= end - 1
        return x

    def _fen_findkth(self, k):
        """Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`)."""
        _list_lens = self._list_lens
        if k < _list_lens[0]:
            return 0, k
        if k >= self._len - _list_lens[-1]:
            return len(_list_lens) - 1, k + _list_lens[-1] - self._len
        if self._rebuild:
            self._fen_build()

        _fen_tree = self._fen_tree
        idx = -1
        for d in reversed(range(len(_fen_tree).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
                idx = right_idx
                k -= _fen_tree[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        """Delete value at the given `(pos, idx)`."""
        _lists = self._lists
        # _mins = self._mins
        _list_lens = self._list_lens

        self._len -= 1
        self._fen_update(pos, -1)
        del _lists[pos][idx]
        _list_lens[pos] -= 1

        if _list_lens[pos]:
            # _mins[pos] = _lists[pos][0]
            pass
        else:
            del _lists[pos]
            del _list_lens[pos]
            # del _mins[pos]
            self._rebuild = True

    def __len__(self):
        """Return the size of the sorted list."""
        return self._len

    def __getitem__(self, index):
        """Lookup value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def __delitem__(self, index):
        """Remove value at `index` from sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def __setitem__(self, index, value):
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        self._lists[pos][idx] = value

    def insert(self, index, value):
        _load = self._load
        _lists = self._lists
        _list_lens = self._list_lens

        if _lists:
            pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
            self._fen_update(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            _list_lens[pos] += 1
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                _list_lens.insert(pos + 1, len(_list) - _load)
                _list_lens[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _list_lens.append(1)
            self._rebuild = True
        self._len += 1

    def __iter__(self):
        """Return an iterator over the sorted list."""
        return (value for _list in self._lists for value in _list)

    def __reversed__(self):
        """Return a reverse iterator over the sorted list."""
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def __repr__(self):
        """Return string representation of sorted list."""
        return "SortedList({0})".format(list(self))


def solve(N, M, queries):
    idToMark = [-1 for i in range(N)]
    cups = UnsortedList([i for i in range(N)])
    for mark, pos in queries:
        pos -= 1  # 0-indexed
        cupId = cups[pos]
        del cups[pos]
        cups.insert(0, cupId)

        if idToMark[cupId] == -1:
            idToMark[cupId] = mark
        elif idToMark[cupId] != mark:
            return b"-1"

    markToCounts = [0 for i in range(N + 1)]
    for cupId, mark in enumerate(idToMark):
        if mark != -1:
            markToCounts[mark] += 1
            if markToCounts[mark] > 1:
                return b"-1"

    j = 1
    ans = []
    for cupId, mark in enumerate(idToMark):
        if mark != -1:
            ans.append(mark)
        else:
            while markToCounts[j] > 0:
                j += 1
            ans.append(j)
            j += 1
    return b" ".join(str(x).encode("ascii") for x in ans)


if False:
    N, M = 10 ** 6, 10 ** 6
    queries = [[N // 2 + (i % (N // 2)), N // 2] for i in range(M)]
    ans = solve(N, M, queries)
    # print(ans)
    assert ans != b"-1"
    exit()

if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    N, M = [int(x) for x in input().split()]
    queries = ((int(x) for x in input().split()) for i in range(M))
    ans = solve(N, M, queries)

    os.write(1, ans)
