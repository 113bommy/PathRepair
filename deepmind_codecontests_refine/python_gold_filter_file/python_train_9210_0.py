from typing import TypeVar, Generic, Callable, List
import sys
from array import array  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


T = TypeVar('T')
S = TypeVar('S')


class StarrySkyTree(Generic[T, S]):
    __slots__ = ['size', 'node', 'lazy', 'unit', 'lazy_unit',
                 'op', 'upd', 'lazy_upd', 'subt_size']

    def __init__(self, size: int, default: T, unit: T, lazy_unit: S,
                 op: Callable[[T, T], T]) -> None:

        self.size = size2 = 1 << (len(bin(size)) - 2)
        self.unit, self.lazy_unit = unit, lazy_unit
        self.node = [default] * (size2 * 2)
        self.lazy = [lazy_unit] * (size2 * 2)
        self.op = op

        self.subt_size = subt = [0] * size2 + [1] * size + [0] * (size2 - size)
        for i in range(size2 * 2 - 1, 1, -1):
            subt[i >> 1] += subt[i]

    def build(self, a: List[T]) -> None:
        node = self.node
        node[self.size:self.size + len(a)] = a

        for i in range(self.size - 1, 0, -1):
            node[i] = self.op(node[i << 1], node[(i << 1) + 1])

    def find(self, left: int, right: int) -> T:
        left, right = left + self.size, right + self.size
        node, lazy = self.node, self.lazy
        self.__propagate(self.__enum_index(left, right))

        result = self.unit

        while left < right:
            if left & 1:
                if lazy[left] == self.lazy_unit:
                    result = self.op(node[left], result)
                else:
                    # node + lazy
                    result = self.op(node[left] + lazy[left], result)
                left += 1
            if right & 1:
                if lazy[right - 1] == self.lazy_unit:
                    result = self.op(node[right - 1], result)
                else:
                    # node + lazy
                    result = self.op(node[right - 1] + lazy[right - 1], result)
            left, right = left >> 1, right >> 1

        return result

    def update(self, left: int, right: int, value: S) -> None:
        left, right = left + self.size, right + self.size
        node, lazy, l_unit = self.node, self.lazy, self.lazy_unit

        _l, _r = left, right
        while _l < _r:
            if _l & 1:
                # update lazy
                lazy[_l] += value
                _l += 1
            if _r & 1:
                # update lazy
                lazy[_r - 1] += value

            _l, _r = _l >> 1, _r >> 1

        for i in self.__enum_index(left, right):
            node[i] = self.op(
                node[i * 2] if lazy[i * 2] == l_unit else node[i * 2] + lazy[i * 2],
                node[i * 2 + 1] if lazy[i * 2 + 1] == l_unit else node[i * 2 + 1] + lazy[i * 2 + 1])

    def __enum_index(self, left: int, right: int) -> List[int]:
        flag, idx = 0, []

        while left < right:
            if flag & 1:
                idx.append(left)
            if flag & 2:
                idx.append(right)
            flag |= (left & 1) | ((right & 1) * 2)
            left, right = left >> 1, right >> 1
        while left:
            idx.append(left)
            left >>= 1

        return idx

    def __propagate(self, index_list):
        node, lazy, l_unit = self.node, self.lazy, self.lazy_unit

        for i in reversed(index_list):
            if lazy[i] != l_unit:
                # refresh node
                node[i] += lazy[i]
                if i < self.size:
                    # update lazy
                    lazy[i * 2] += lazy[i]
                    lazy[i * 2 + 1] += lazy[i]
                lazy[i] = l_unit


n = int(input())
segt = StarrySkyTree[int, int](n, 10**9, 10**18, 0, min)
segt.build(list(map(int, input().split())))
t = int(input())
ans = []

for _ in range(t):
    q = tuple(map(int, input().split()))
    if len(q) == 3:
        if q[0] > q[1]:
            segt.update(q[0], n + 1, q[2])
            segt.update(0, q[1] + 1, q[2])
        else:
            segt.update(q[0], q[1] + 1, q[2])
    else:
        if q[0] > q[1]:
            ans.append(min(segt.find(q[0], n + 1), segt.find(0, q[1] + 1)))
        else:
            ans.append(segt.find(q[0], q[1] + 1))

print(*ans, sep='\n')
